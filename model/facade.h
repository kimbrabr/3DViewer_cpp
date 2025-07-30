#ifndef FACADE_H
#define FACADE_H

#include <string>
#include <vector>

#include "model.h"

namespace s21 {

class Facade {
 public:
  void LoadModel(const std::string& filename,
                 std::vector<Model::Vertex>& vertices,
                 std::vector<Model::Face>& faces, float& max_vertex);
};

}  // namespace s21

#endif  // FACADE_H