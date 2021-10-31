#include "matrix_processor/heuristic_functions/rectilinear_function.h"

namespace ia {

RectilinearFunction::RectilinearFunction(Direction direction) {
  direction_ = direction;
}

double RectilinearFunction::operator()(Position position, Position goal) const {
  return std::abs(static_cast<double>(position.GetX() - goal.GetX())) +
         std::abs(static_cast<double>(position.GetY() - goal.GetY()));
}

}  // namespace ia
