#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_EUCLIDEAN_FUNCTION_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_EUCLIDEAN_FUNCTION_H_

#include <cmath>

#include "a_star_search/heuristic_functions/heuristic_function.h"
#include "a_star_search/position.h"

namespace ia {

class EuclideanFunction : public HeuristicFunction {
 public:
  EuclideanFunction(Direction direction);

  double operator()(Position position, Position goal) const override;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_EUCLIDEAN_FUNCTION_H_
