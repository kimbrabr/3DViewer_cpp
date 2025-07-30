#include "obj_loader.h"

#include <cmath>
#include <fstream>
#include <sstream>

namespace s21 {
void ObjLoader::Load(const std::string& filename,
                     std::vector<Model::Vertex>& vertices,
                     std::vector<Model::Face>& faces, float& max_vertex) {
  std::ifstream file(filename);
  if (!file.is_open()) return;

  max_vertex = 0.0f;
  vertices.clear();
  faces.clear();

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string prefix;
    iss >> prefix;

    if (prefix == "v") {
      ParseVertex(iss, vertices, max_vertex);
    } else if (prefix == "f") {
      ParseFace(iss, vertices, faces);
    }
  }
  file.close();
}

void ObjLoader::ParseVertex(std::istringstream& iss,
                            std::vector<Model::Vertex>& vertices,
                            float& max_vertex) {
  Model::Vertex vertex;
  if (iss >> vertex.x >> vertex.y >> vertex.z) {
    vertices.push_back(vertex);
    max_vertex = std::max(max_vertex, std::fabs(vertex.x));
    max_vertex = std::max(max_vertex, std::fabs(vertex.y));
    max_vertex = std::max(max_vertex, std::fabs(vertex.z));
  }
}

void ObjLoader::ParseFace(std::istringstream& iss,
                          std::vector<Model::Vertex>& vertices,
                          std::vector<Model::Face>& faces) {
  Model::Face face;
  std::string token;
  while (iss >> token) {
    int index = GetVertexIndex(token, vertices.size());
    if (index >= 0 && static_cast<size_t>(index) < vertices.size()) {
      face.vertex_indices.push_back(index);
    }
  }
  if (!face.vertex_indices.empty()) {
    faces.push_back(face);
  }
}

int ObjLoader::GetVertexIndex(const std::string& token, size_t vertex_count) {
  int result = -1;
  std::string index_str = token.substr(0, token.find('/'));

  if (!index_str.empty()) {
    std::istringstream iss(index_str);
    int index;
    if (iss >> index) {
      if (index < 0) {
        index += vertex_count;
      } else {
        index -= 1;
      }
      if (index >= 0 && static_cast<size_t>(index) < vertex_count) {
        result = index;
      }
    }
  }

  return result;
}
}  // namespace s21