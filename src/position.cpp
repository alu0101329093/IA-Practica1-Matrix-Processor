#include "matrix_processor/position.h"

namespace ia {

Position::Position(std::size_t x, std::size_t y) : x_{x}, y_{y} {}

void to_json(nlohmann::json& json, const Position& position) {
  json = nlohmann::json{{position.GetX(), position.GetY()}};
}

}  // namespace ia
