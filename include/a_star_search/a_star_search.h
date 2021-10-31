#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_

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
              HeuristicFunction* heuristic_function, Directions directions);

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
  std::vector<Position> GetPositionNeightbors();

  std::vector<std::vector<int>> matrix_;
  std::unique_ptr<HeuristicFunction> heuristic_function_;
  std::vector<Position> directions_;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_
