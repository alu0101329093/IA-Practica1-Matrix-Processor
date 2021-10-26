#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_HEURISTIC_FUNCTION_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_HEURISTIC_FUNCTION_H_

#include <vector>

#include "matrix_processor/position.h"

namespace ia {

class HeuristicFunction {
 public:
  enum class Direction {
    k4Ways,
    k8Ways,
  };

  virtual std::vector<Position> operator()(
      const std::vector<std::vector<int>>& matrix) const = 0;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_HEURISTIC_FUNCTION_H_