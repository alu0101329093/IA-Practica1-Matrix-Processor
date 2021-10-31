#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_EUCLIDEAN_FUNCTION_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_EUCLIDEAN_FUNCTION_H_

#include <cmath>
#include <vector>

#include "matrix_processor/heuristic_functions/heuristic_function.h"
#include "matrix_processor/position.h"

namespace ia {

class EuclideanFunction : public HeuristicFunction {
 public:
  EuclideanFunction(Direction direction);

  double operator()(Position position, Position goal) const override;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_EUCLIDEAN_FUNCTION_H_
