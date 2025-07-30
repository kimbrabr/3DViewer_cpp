#include "viewer.h"

namespace s21 {
Viewer::Viewer(QWidget* parent) : QOpenGLWidget(parent) {}

void Viewer::SetController(Controller* controller) {
  controller_ = controller;
  update();
}

void Viewer::initializeGL() { glEnable(GL_DEPTH_TEST); }

void Viewer::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void Viewer::paintGL() {
  if (!controller_ || !controller_->GetModel()) return;
  setGLProjection();
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -4.0f);

  glEnableClientState(GL_VERTEX_ARRAY);
  const auto& vertices = controller_->GetModel()->GetVertices();
  if (!vertices.empty()) {
    glVertexPointer(3, GL_FLOAT, 0, vertices.data());
  }

  paintVertices();
  setGLEdgeType();
  const auto& faces = controller_->GetModel()->GetFaces();
  if (!faces.empty()) {
    glBegin(GL_LINES);
    for (const auto& face : faces) {
      if (face.vertex_indices.size() < 2) continue;

      const auto& indices = face.vertex_indices;
      for (size_t j = 0; j < indices.size(); j++) {
        size_t current = indices[j];
        size_t next = indices[(j + 1) % indices.size()];

        if (current < vertices.size() && next < vertices.size()) {
          const auto& v1 = vertices[current];
          const auto& v2 = vertices[next];
          glVertex3f(v1.x, v1.y, v1.z);
          glVertex3f(v2.x, v2.y, v2.z);
        }
      }
    }
    glEnd();
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Viewer::setGLProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1, 1, -1, 1, 2, 1000);
  glTranslatef(0, 0, -3);
}

void Viewer::setGLEdgeType() {
  glLineStipple(1, 0x3333);
  glLineWidth(1.0f);
  glColor3f(0, 0, 0);
}

void Viewer::paintVertices() {
  glPointSize(1.0f);
  glColor3f(0, 0, 0);
  const auto& vertices = controller_->GetModel()->GetVertices();
  if (!vertices.empty()) {
    glDrawArrays(GL_POINTS, 0, vertices.size());
  }
}
}  // namespace s21