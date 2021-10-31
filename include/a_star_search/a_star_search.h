#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_

#include <memory>
#include <vector>

#include "a_star_search/heuristic_functions/heuristic_function.h"
#include "a_star_search/position.h"
#include "nlohmann/json.hpp"

namespace ia {

class AStarSearch {
 public:
  AStarSearch(std::vector<std::vector<int>> matrix);

  inline const std::vector<std::vector<int>> GetMatrix() const {
    return matrix_;
  }
  inline void SetMatrix(const std::vector<std::vector<int>>& matrix) {
    matrix_ = matrix;
  }
  std::vector<Position> GetPath() const;

 private:
  std::vector<std::vector<int>> matrix_;
  std::unique_ptr<HeuristicFunction> heuristic_function_;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_MATRIX_PROCESSOR_H_