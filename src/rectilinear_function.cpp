#include "a_star_search/heuristic_functions/rectilinear_function.h"

namespace ia {

RectilinearFunction::RectilinearFunction() {}

double RectilinearFunction::operator()(Position position, Position goal) const {
  return std::abs(position.GetX() - goal.GetX()) +
         std::abs(position.GetY() - goal.GetY());
}

}  // namespace ia
