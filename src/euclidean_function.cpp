#include "a_star_search/heuristic_functions/euclidean_function.h"

namespace ia {

EuclideanFunction::EuclideanFunction() {}

double EuclideanFunction::operator()(Position position, Position goal) const {
  return std::sqrt(std::pow(position.GetX() - goal.GetX(), 2) +
                   std::pow(position.GetY() - goal.GetY(), 2));
}

}  // namespace ia
