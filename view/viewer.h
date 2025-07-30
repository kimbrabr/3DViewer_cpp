#ifndef VIEWER_H
#define VIEWER_H

#include <QOpenGLWidget>

#include "../controller/controller.h"

namespace s21 {
class Viewer : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit Viewer(QWidget* parent = nullptr);
  void SetController(Controller* controller);

  void setGLProjection();
  void setGLEdgeType();
  void paintVertices();

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

 private:
  Controller* controller_ = nullptr;
};
}  // namespace s21

#endif