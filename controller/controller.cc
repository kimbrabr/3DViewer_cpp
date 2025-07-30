#include "controller.h"
namespace s21 {
void Controller::LoadModel(const std::string& filename) {
  model_->LoadFromFile(filename);
}

void Controller::MoveModel(float dx, float dy, float dz) {
  auto command = std::make_unique<MoveCommand>(dx, dy, dz);
  command->Execute(*model_);
}

void Controller::RotateModel(float angle_x, float angle_y, float angle_z) {
  auto command = std::make_unique<RotateCommand>(angle_x, angle_y, angle_z);
  command->Execute(*model_);
}

void Controller::ScaleModel(float factor) {
  auto command = std::make_unique<ScaleCommand>(factor);
  command->Execute(*model_);
}

}  // namespace s21