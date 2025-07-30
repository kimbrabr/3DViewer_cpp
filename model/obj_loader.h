#ifndef S21_OBJ_LOADER_H_
#define S21_OBJ_LOADER_H_
#include <sstream>
#include <string>

#include "model.h"

namespace s21 {
class ObjLoader {
 public:
  void Load(const std::string& filename, std::vector<Model::Vertex>& vertices,
            std::vector<Model::Face>& faces, float& max_vertex);

 private:
  void ParseVertex(std::istringstream& iss,
                   std::vector<Model::Vertex>& vertices, float& max_vertex);
  void ParseFace(std::istringstream& iss, std::vector<Model::Vertex>& vertices,
                 std::vector<Model::Face>& faces);
  int GetVertexIndex(const std::string& token, size_t vertex_count);
};
}  // namespace s21
#endif