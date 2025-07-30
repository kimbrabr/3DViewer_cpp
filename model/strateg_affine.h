#ifndef STRATEG_AFFINE_H
#define STRATEG_AFFINE_H

#include <vector>

#include "model.h"

namespace s21 {

class StrategAffine {
 public:
  virtual ~StrategAffine() = default;
  virtual void Apply(std::vector<Model::Vertex>& vertices, float param1,
                     float param2, float param3) = 0;
  virtual bool UpdateMaxVertex(float& /*max_vertex*/, float /*param1*/,
                               float /*param2*/, float /*param3*/) const {
    return false;
  }
};

class MoveAffine : public StrategAffine {
 public:
  void Apply(std::vector<Model::Vertex>& vertices, float dx, float dy,
             float dz) override;
};

class RotateAffine : public StrategAffine {
 public:
  void Apply(std::vector<Model::Vertex>& vertices, float angle_x, float angle_y,
             float angle_z) override;
};

class ScaleAffine : public StrategAffine {
 public:
  void Apply(std::vector<Model::Vertex>& vertices, float factor, float unused1,
             float unused2) override;
  bool UpdateMaxVertex(float& max_vertex, float param1, float /*param2*/,
                       float /*param3*/) const override {
    bool updated = false;
    if (param1 > 0.0f) {
      max_vertex *= param1;
      updated = true;
    }
    return updated;
  }
};

}  // namespace s21

#endif  // STRATEG_AFFINE_H