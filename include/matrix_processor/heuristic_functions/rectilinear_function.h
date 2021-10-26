#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_RECTILINEAR_FUNCTION_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_RECTILINEAR_FUNCTION_H_

#include <vector>

#include "matrix_processor/heuristic_functions/heuristic_function.h"
#include "matrix_processor/position.h"

namespace ia {

class RectilinearFunction : public HeuristicFunction {
 public:
  RectilinearFunction(Direction direction);

  std::vector<Position> operator()(
      const std::vector<std::vector<int>>& matrix) const override;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_RECTILINEAR_FUNCTION_H_
