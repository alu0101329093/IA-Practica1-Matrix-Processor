#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_

#include <map>
#include <memory>
#include <queue>
#include <vector>

#include "a_star_search/heuristic_functions/heuristic_function.h"
#include "a_star_search/position.h"
#include "nlohmann/json.hpp"

namespace ia {

class AStarSearch {
 public:
  enum class Directions {
    k4Ways,
    k8Ways,
  };

  AStarSearch(std::vector<std::vector<int>> matrix,
              HeuristicFunction* heuristic_function, Directions directions,
              const Position& start, const Position& goal);

  inline const std::vector<std::vector<int>> GetMatrix() const {
    return matrix_;
  }
  inline void SetMatrix(const std::vector<std::vector<int>>& matrix) {
    matrix_ = matrix;
  }
  inline const std::unique_ptr<HeuristicFunction>& GetHeuristicFunction()
      const {
    return heuristic_function_;
  }
  inline void SetHeuristicFunction(HeuristicFunction* heuristic_function) {
    heuristic_function_.reset(heuristic_function);
  }
  const std::vector<Position>& GetDirections() const;
  void SetDirections(Directions directions);

  std::vector<Position> GetShortestPath() const;

 private:
  typedef std::pair<double, Position> PQElement;

  struct ComparePrioritiedPosition {
    bool operator()(const PQElement& lhs, const PQElement& rhs) const {
      return lhs.first > rhs.first;
    }
  };

  bool PositionInBounds(const Position& position) const;
  bool PositionPassable(const Position& position) const;
  std::vector<Position> GetPositionNeightbors(const Position& position) const;
  std::vector<Position> ReconstructPath(
      const std::map<Position, Position>& came_from) const;

  std::vector<std::vector<int>> matrix_;
  std::unique_ptr<HeuristicFunction> heuristic_function_;
  std::vector<Position> directions_;
  Position start_;
  Position goal_;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_
