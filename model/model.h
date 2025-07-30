#ifndef S21_MODEL_H_
#define S21_MODEL_H_

#include <string>
#include <vector>

namespace s21 {

class StrategAffine;

class Model {
 public:
  struct Vertex {
    float x, y, z;
  };

  struct Face {
    std::vector<int> vertex_indices;
  };
  Model() = default;
  void LoadFromFile(const std::string& filename);
  void ApplyAffine(StrategAffine* affine, float dx, float dy, float dz);
  const std::vector<Vertex>& GetVertices() const { return vertices_; }
  const std::vector<Face>& GetFaces() const { return faces_; }
  float GetMaxVertex() const { return max_vertex_; }
  size_t GetEdgeCount() const;

 private:
  void CenterAndNormalize();
  std::vector<Vertex> vertices_;
  std::vector<Face> faces_;
  float max_vertex_ = 0.0f;
};
}  // namespace s21

#endif  // S21_MODEL_H_