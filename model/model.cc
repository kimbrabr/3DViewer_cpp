#include "model.h"

#include <cmath>
#include <limits>

#include "facade.h"
#include "obj_loader.h"
#include "strateg_affine.h"

namespace s21 {
void Model::LoadFromFile(const std::string& filename) {
  Facade loader;
  loader.LoadModel(filename, vertices_, faces_, max_vertex_);
  CenterAndNormalize();
}

void Model::ApplyAffine(StrategAffine* affine, float dx, float dy, float dz) {
  affine->Apply(vertices_, dx, dy, dz);
  affine->UpdateMaxVertex(max_vertex_, dx, dy, dz);
}
void Model::CenterAndNormalize() {
  if (vertices_.empty()) return;

  float min_x = std::numeric_limits<float>::max();
  float max_x = std::numeric_limits<float>::lowest();
  float min_y = std::numeric_limits<float>::max();
  float max_y = std::numeric_limits<float>::lowest();
  float min_z = std::numeric_limits<float>::max();
  float max_z = std::numeric_limits<float>::lowest();

  for (const auto& vertex : vertices_) {
    min_x = std::min(min_x, vertex.x);
    max_x = std::max(max_x, vertex.x);
    min_y = std::min(min_y, vertex.y);
    max_y = std::max(max_y, vertex.y);
    min_z = std::min(min_z, vertex.z);
    max_z = std::max(max_z, vertex.z);
  }

  float mid_x = (min_x + max_x) / 2.0f;
  float mid_y = (min_y + max_y) / 2.0f;
  float mid_z = (min_z + max_z) / 2.0f;

  float scale_factor = (max_vertex_ > 1.0f) ? 2.0f / max_vertex_ : 1.0f;

  for (auto& vertex : vertices_) {
    vertex.x = (vertex.x - mid_x) * scale_factor;
    vertex.y = (vertex.y - mid_y) * scale_factor;
    vertex.z = (vertex.z - mid_z) * scale_factor;
  }
}

size_t Model::GetEdgeCount() const {
  size_t edges = 0;
  for (const auto& face : faces_) {
    edges += face.vertex_indices.size() / 2;
  }
  return edges;
}

}  // namespace s21