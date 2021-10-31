#include "matrix_processor/heuristic_functions/euclidean_function.h"

namespace ia {

EuclideanFunction::EuclideanFunction(Direction direction) {
  direction_ = direction;
}

double EuclideanFunction::operator()(Position position, Position goal) const {
  return std::sqrt(
      std::pow(static_cast<double>(position.GetX() - goal.GetX()), 2) +
      std::pow(static_cast<double>(position.GetY() - goal.GetY()), 2));
}

}  // namespace ia
