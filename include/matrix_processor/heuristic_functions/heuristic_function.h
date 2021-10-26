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

  inline Direction GetDirection() const { return direction_; }
  inline void SetDirection(Direction direction) { direction_ = direction; }

 protected:
  Direction direction_;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_HEURISTIC_FUNCTION_H_