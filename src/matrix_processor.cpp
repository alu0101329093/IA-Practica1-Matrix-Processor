#include "matrix_processor/matrix_processor.h"

namespace ia {

MatrixProcessor::MatrixProcessor(std::vector<std::vector<int>> matrix)
    : matrix_{matrix} {}

std::vector<Position> MatrixProcessor::GetPath() const {
  return {Position{1, 2}, Position{3, 4}};
}

}  // namespace ia
