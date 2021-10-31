#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_POSITION_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_POSITION_H_

#include <cstddef>
#include <nlohmann/json.hpp>

namespace ia {

class Position {
 public:
  Position(std::size_t x, std::size_t y);

  inline std::size_t GetX() const { return x_; }
  inline void SetX(std::size_t x) { x_ = x; }
  inline std::size_t GetY() const { return y_; }
  inline void SetY(std::size_t y) { y_ = y; }

 private:
  std::size_t x_;
  std::size_t y_;
};

void to_json(nlohmann::json& json, const Position& position);
void from_json(const nlohmann::json& json, Position& position);

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_POSITION_H_