#include "a_star_search/a_star_search.h"

namespace ia {

AStarSearch::AStarSearch(std::vector<std::vector<int>> matrix,
                         HeuristicFunction* heuristic_function,
                         Directions direction)
    : matrix_{matrix}, heuristic_function_{heuristic_function}, directions_{} {}

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
  typedef std::pair<double, Position> PQElement;
  std::priority_queue<PQElement, std::vector<PQElement>,
                      std::greater<PQElement>>
      frontier;
  return {Position{1, 2}, Position{3, 4}};
}

}  // namespace ia
