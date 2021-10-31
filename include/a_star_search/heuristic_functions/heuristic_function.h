#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_HEURISTIC_FUNCTION_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_HEURISTIC_FUNCTION_H_

#include "a_star_search/position.h"

namespace ia {

class HeuristicFunction {
 public:
  virtual double operator()(Position position, Position goal) const = 0;
};

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_HEURISTIC_FUNCTIONS_HEURISTIC_FUNCTION_H_