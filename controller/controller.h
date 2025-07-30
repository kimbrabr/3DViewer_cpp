#ifndef S21_CONTROLLER_H_
#define S21_CONTROLLER_H_
#include <memory>

#include "../model/model.h"
#include "command.h"

namespace s21 {
class Controller {
 public:
  explicit Controller(Model* model) : model_(model) {}
  void LoadModel(const std::string& filename);
  void MoveModel(float dx, float dy, float dz);
  void RotateModel(float angle_x, float angle_y, float angle_z);
  void ScaleModel(float factor);
  Model* GetModel() const { return model_; }

 private:
  Model* model_;
};

}  // namespace s21
#endif
