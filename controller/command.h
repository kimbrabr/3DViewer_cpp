#ifndef S21_COMMAND_H_
#define S21_COMMAND_H_

#include "../model/model.h"
#include "../model/strateg_affine.h"

namespace s21 {
class Command {
 public:
  virtual ~Command() = default;
  virtual void Execute(Model& model) = 0;
};

class MoveCommand : public Command {
 public:
  MoveCommand(float dx, float dy, float dz) : dx_(dx), dy_(dy), dz_(dz) {}
  void Execute(Model& model) override {
    MoveAffine move;
    model.ApplyAffine(&move, dx_, dy_, dz_);
  }

 private:
  float dx_, dy_, dz_;
};

class RotateCommand : public Command {
 public:
  RotateCommand(float angle_x, float angle_y, float angle_z)
      : angle_x_(angle_x), angle_y_(angle_y), angle_z_(angle_z) {}
  void Execute(Model& model) override {
    RotateAffine rotate;
    model.ApplyAffine(&rotate, angle_x_, angle_y_, angle_z_);
  }

 private:
  float angle_x_, angle_y_, angle_z_;
};

class ScaleCommand : public Command {
 public:
  explicit ScaleCommand(float factor) : factor_(factor) {}
  void Execute(Model& model) override {
    ScaleAffine scale;
    model.ApplyAffine(&scale, factor_, 0.0f, 0.0f);
  }

 private:
  float factor_;
};
}  // namespace s21

#endif