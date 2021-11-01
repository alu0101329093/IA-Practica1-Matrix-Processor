#include "a_star_search/a_star_search.h"

namespace ia {

AStarSearch::AStarSearch(std::vector<std::vector<int>> matrix,
                         HeuristicFunction* heuristic_function,
                         Directions direction, const Position& start,
                         const Position& goal)
    : matrix_{matrix},
      heuristic_function_{heuristic_function},
      directions_{},
      start_{start},
      goal_{goal} {
  SetDirections(direction);
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
    for (Position next : GetPositionNeightbors(current)) {
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

bool AStarSearch::PositionInBounds(const Position& position) const {
  return position.GetX() >= 0 && position.GetX() < matrix_.size() &&
         position.GetY() >= 0 && position.GetY() < matrix_[0].size();
}

bool AStarSearch::PositionPassable(const Position& position) const {
  return matrix_[position.GetX()][position.GetY()] != 0;
}

std::vector<Position> AStarSearch::GetPositionNeightbors(
    const Position& position) const {
  std::vector<Position> neighbors{};
  for (const auto& direction : directions_) {
    Position next{direction.GetX() + position.GetX(),
                  direction.GetY() + position.GetY()};
    if (PositionInBounds(next) && PositionPassable(next))
      neighbors.push_back(next);
  }
  return neighbors;
}

std::vector<Position> AStarSearch::ReconstructPath(
    const std::map<Position, Position>& came_from) const {
  std::vector<Position> path;
  if (came_from.find(goal_) == came_from.end()) return {};
  Position current = goal_;
  while (current != start_) {
    path.push_back(current);
    current = came_from.at(current);
  }
  std::reverse(path.begin(), path.end());
  return path;
}

}  // namespace ia
