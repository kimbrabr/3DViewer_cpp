#include "strateg_affine.h"

#include <cmath>

namespace s21 {

void MoveAffine::Apply(std::vector<Model::Vertex>& vertices, float dx, float dy,
                       float dz) {
  for (auto& vertex : vertices) {
    vertex.x += dx;
    vertex.y += dy;
    vertex.z += dz;
  }
}

void RotateAffine::Apply(std::vector<Model::Vertex>& vertices, float angle_x,
                         float angle_y, float angle_z) {
  float rad_x = angle_x * M_PI / 180.0f;
  float rad_y = angle_y * M_PI / 180.0f;
  float rad_z = angle_z * M_PI / 180.0f;

  float cos_x = std::cos(rad_x);
  float sin_x = std::sin(rad_x);
  float cos_y = std::cos(rad_y);
  float sin_y = std::sin(rad_y);
  float cos_z = std::cos(rad_z);
  float sin_z = std::sin(rad_z);

  for (auto& vertex : vertices) {
    float tmp[3] = {vertex.x, vertex.y, vertex.z};
    // x
    vertex.y = tmp[1] * cos_x - tmp[2] * sin_x;
    vertex.z = tmp[1] * sin_x + tmp[2] * cos_x;
    tmp[0] = vertex.x;
    tmp[1] = vertex.y;
    tmp[2] = vertex.z;
    // y
    vertex.x = tmp[0] * cos_y + tmp[2] * sin_y;
    vertex.z = -tmp[0] * sin_y + tmp[2] * cos_y;
    tmp[0] = vertex.x;
    tmp[1] = vertex.y;
    tmp[2] = vertex.z;
    // z
    vertex.x = tmp[0] * cos_z - tmp[1] * sin_z;
    vertex.y = tmp[0] * sin_z + tmp[1] * cos_z;
  }
}

void ScaleAffine::Apply(std::vector<Model::Vertex>& vertices, float factor,
                        float, float) {
  if (factor != 0.0f) {
    for (auto& vertex : vertices) {
      vertex.x *= factor;
      vertex.y *= factor;
      vertex.z *= factor;
    }
  }
}

}  // namespace s21