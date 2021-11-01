#include "a_star_search/position.h"

namespace ia {

Position::Position(double x, double y) : x_{x}, y_{y} {}

void to_json(nlohmann::json& json, const Position& position) {
  json = nlohmann::json{position.GetX(), position.GetY()};
}

void from_json(const nlohmann::json& json, Position& position) {
  position.SetX(json[0]);
  position.SetY(json[1]);
}

}  // namespace ia
