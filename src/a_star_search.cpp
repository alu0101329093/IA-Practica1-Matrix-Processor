#include "a_star_search/a_star_search.h"

namespace ia {

AStarSearch::AStarSearch(std::vector<std::vector<int>> matrix,
                         HeuristicFunction* heuristic_function,
                         Directions direction)
    : matrix_{matrix}, heuristic_function_{heuristic_function}, directions_{} {
  start_.SetX(100);
  start_.SetY(100);
}

const std::vector<Position>& AStarSearch::GetDirections() const {
  return directions_;
}

void AStarSearch::SetDirections(Directions directions) {
  switch (directions) {
    case Directions::k4Ways:
      directions_ = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
      break;
    case Directions::k8Ways:
      directions_ = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                     {1, 0},  {1, -1}, {0, -1}};
      break;
    default:
      break;
  }
}

std::vector<Position> AStarSearch::GetShortestPath() const {
  std::priority_queue<PQElement, std::vector<PQElement>,
                      ComparePrioritiedPosition>
      frontier{};
  frontier.push({0, start_});
  std::map<Position, Position> came_from{{start_, start_}};
  std::map<Position, double> cost_so_far{{start_, 0}};

  while (!frontier.empty()) {
    Position current = frontier.top().second;
    frontier.pop();
    if (current == goal_) break;
    for (Position next : GetPositionNeightbors()) {
      double new_cost = cost_so_far[current] + 1;
      if (cost_so_far.find(next) == cost_so_far.end() ||
          new_cost < cost_so_far[next]) {
        cost_so_far[next] = new_cost;
        double priority = new_cost + (*heuristic_function_)(next, goal_);
        frontier.push({priority, next});
        came_from[next] = current;
      }
    }
  }
  return ReconstructPath(came_from);
}

std::vector<Position> GetPositionNeightbors() const {}

std::vector<Position> AStarSearch::ReconstructPath(
    std::map<Position, Position> came_from) const {
  std::vector<Position> path;
  if (came_from.find(goal_) == came_from.end()) return {};
  Position current = goal_;
  while (current != start_) {
    path.push_back(current);
    current = came_from[current];
  }
  std::reverse(path.begin(), path.end());
  return path;
}

}  // namespace ia
