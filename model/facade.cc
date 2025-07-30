#include "facade.h"

#include "obj_loader.h"

namespace s21 {

void Facade::LoadModel(const std::string& filename,
                       std::vector<Model::Vertex>& vertices,
                       std::vector<Model::Face>& faces, float& max_vertex) {
  ObjLoader loader;
  loader.Load(filename, vertices, faces, max_vertex);
}

}  // namespace s21