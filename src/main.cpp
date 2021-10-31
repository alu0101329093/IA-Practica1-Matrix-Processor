#include "main.h"

int main(int argc, char* argv[]) {
  sio::client client;
  client.set_logs_quiet();
  client.connect("ws://localhost:3000");
  bool exit{};
  client.socket()->on("stop", [&](sio::event& ev) { exit = true; });
  client.socket()->on("sendMatrix", [&](sio::event& ev) {
    nlohmann::json json{nlohmann::json::parse(ev.get_message()->get_string())};
    ia::AStarSearch processor{json[0].get<std::vector<std::vector<int>>>(),
                              new ia::RectilinearFunction{},
                              ia::AStarSearch::Directions::k4Ways};
    nlohmann::json path_json{processor.GetShortestPath()};
    client.socket()->emit("receivePath", path_json.dump());
  });
  while (!exit) continue;
  std::cout << "Exit" << std::endl;
  return EXIT_SUCCESS;
}
