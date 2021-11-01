#ifndef MATRIXPROCESSOR_MATRIX_PROCESSOR_POSITION_H_
#define MATRIXPROCESSOR_MATRIX_PROCESSOR_POSITION_H_

#include <cstddef>
#include <nlohmann/json.hpp>

namespace ia {

class Position {
 public:
  Position(double x = 0, double y = 0);

  inline double GetX() const { return x_; }
  inline void SetX(double x) { x_ = x; }
  inline double GetY() const { return y_; }
  inline void SetY(double y) { y_ = y; }

  inline friend bool operator==(const Position& this_position,
                                const Position& another_position) {
    return this_position.x_ == another_position.x_ &&
           this_position.y_ == another_position.y_;
  }
  inline friend bool operator!=(const Position& this_position,
                                const Position& another_position) {
    return this_position.x_ != another_position.x_ ||
           this_position.y_ != another_position.y_;
  }
  inline friend bool operator<(const Position& this_position,
                               const Position& another_position) {
    return this_position.x_ < another_position.x_ ||
           (this_position.x_ == another_position.x_ &&
            this_position.y_ < another_position.y_);
  }
  inline friend bool operator>(const Position& this_position,
                               const Position& another_position) {
    return this_position.x_ > another_position.x_ ||
           (this_position.x_ == another_position.x_ &&
            this_position.y_ > another_position.y_);
  }

 private:
  double x_;
  double y_;
};

void to_json(nlohmann::json& json, const Position& position);
void from_json(const nlohmann::json& json, Position& position);

}  // namespace ia

#endif  // MATRIXPROCESSOR_MATRIX_PROCESSOR_POSITION_H_