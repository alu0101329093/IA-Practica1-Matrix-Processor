#include <array>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "nlohmann/json.hpp"
#include "sio_client.h"

int main(int argc, char* argv[]) {
  sio::client client;
  // client.set_logs_quiet();
  client.connect("ws://localhost:3000");
  bool exit{};
  client.socket()->on("stop", [&](sio::event& ev) { exit = true; });
  client.socket()->on("sendMatrix", [&](sio::event& ev) {
    nlohmann::json json{nlohmann::json::parse(ev.get_message()->get_string())};
    std::vector<std::vector<int>> matrix =
        json[0].get<std::vector<std::vector<int>>>();
    nlohmann::json path_json{std::vector<std::vector<int>>{{0, 0}, {1, 1}}};
    client.socket()->emit("receivePath", path_json.dump());
  });
  while (!exit) continue;
  std::cout << "Exit" << std::endl;
  return EXIT_SUCCESS;
}
