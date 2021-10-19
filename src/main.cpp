#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "nlohmann/json.hpp"
#include "sio_client.h"

std::vector<std::vector<int>> GenerateRandomMatrix() {
  std::vector<std::vector<int>> matrix(50, std::vector<int>(50));
  srand(static_cast<unsigned int>(time(nullptr)));
  for (auto& row : matrix) {
    for (auto& value : row) {
      value = rand() % 2;
    }
  }
  matrix[3][4] = 2;
  matrix[13][8] = 3;
  return matrix;
}

int main(int argc, char* argv[]) {
  sio::client client;
  // client.set_logs_quiet();
  client.connect("ws://localhost:3000");
  bool exit{};
  client.socket()->on("stop", [&](sio::event& ev) { exit = true; });
  while (!exit) {
    std::vector<std::vector<int>> matrix{GenerateRandomMatrix()};
    nlohmann::json json{matrix};
    std::string string{json.dump()};
    client.socket()->emit("receiveMatrix", string);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }std
  std::cout << "Exit" << std::endl;
  // system("pause");
  return EXIT_SUCCESS;
}
