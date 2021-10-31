#include "a_star_search/a_star_search.h"

namespace ia {

AStarSearch::AStarSearch(std::vector<std::vector<int>> matrix)
    : matrix_{matrix} {}

std::vector<Position> AStarSearch::GetPath() const {
  return {Position{1, 2}, Position{3, 4}};
}

}  // namespace ia
