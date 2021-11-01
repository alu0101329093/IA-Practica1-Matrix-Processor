#include "main.h"

int main(int argc, char* argv[]) {
  sio::client client;
  client.set_logs_quiet();
  client.connect("ws://localhost:3000");
  bool exit{};
  client.socket()->on("stop", [&](sio::event& ev) { exit = true; });
  client.socket()->on("sendMatrix", [&](sio::event& ev) {
    nlohmann::json json{nlohmann::json::parse(ev.get_message()->get_string())};
    auto matrix = json[0]["matrix"].get<std::vector<std::vector<int>>>();
    ia::HeuristicFunction* heuristic_function;
    if (json[0]["heuristicFunction"].get<int>() == 0) {
      heuristic_function = new ia::RectilinearFunction{};
    } else if (json[0]["heuristicFunction"].get<int>() == 1) {
      heuristic_function = new ia::EuclideanFunction{};
    }
    auto directions = ia::AStarSearch::Directions{json[0]["ways"].get<int>()};
    ia::Position start{json[0]["start"].get<ia::Position>()},
        goal{json[0]["goal"].get<ia::Position>()};
    ia::AStarSearch processor{matrix, heuristic_function, directions, start,
                              goal};
    nlohmann::json path_json{processor.GetShortestPath()};
    client.socket()->emit("receivePath", path_json.dump());
  });
  while (!exit) continue;
  std::cout << "Exit" << std::endl;
  return EXIT_SUCCESS;
}
