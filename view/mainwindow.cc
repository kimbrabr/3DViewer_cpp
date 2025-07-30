#include "mainwindow.h"

#include <QFileDialog>

#include "viewer.h"

namespace s21 {
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      controller_(new Controller(new Model())) {
  ui->setupUi(this);
  // connect(ui->loadButton, &QPushButton::clicked, this,
  //         &MainWindow::on_loadButton_clicked);
  connect(ui->moveButton, &QPushButton::clicked, this,
          &MainWindow::on_moveButton_clicked);
  connect(ui->rotateButton, &QPushButton::clicked, this,
          &MainWindow::on_rotateButton_clicked);
  connect(ui->scaleButton, &QPushButton::clicked, this,
          &MainWindow::on_scaleButton_clicked);
}

MainWindow::~MainWindow() {
  delete controller_;
  delete ui;
}

void MainWindow::on_loadButton_clicked() {
  QString filename = QFileDialog::getOpenFileName(this, tr("Открыть OBJ"), "",
                                                  tr("OBJ Files (*.obj)"));
  if (!filename.isEmpty()) {
    controller_->LoadModel("");  //////////////////
    controller_->LoadModel(filename.toStdString());
    ui->openGLWidget->SetController(controller_);
    ui->fileLabel->setText(filename);
    updateModelInfo();
    ui->openGLWidget->update();
  }
}

void MainWindow::on_moveButton_clicked() {
  float dx = ui->moveX->text().toFloat();
  float dy = ui->moveY->text().toFloat();
  float dz = ui->moveZ->text().toFloat();
  controller_->MoveModel(dx, dy, dz);
  ui->openGLWidget->update();
}

void MainWindow::on_rotateButton_clicked() {
  float rx = ui->rotateX_2->text().toFloat();
  float ry = ui->rotateY_2->text().toFloat();
  float rz = ui->rotateZ_2->text().toFloat();
  controller_->RotateModel(ry, rx, rz);
  ui->openGLWidget->update();
}

void MainWindow::on_scaleButton_clicked() {
  float factor = ui->ScaleFactor->text().toFloat();
  controller_->ScaleModel(factor);
  ui->openGLWidget->update();
}

void MainWindow::updateModelInfo() {
  Model* model = controller_->GetModel();
  ui->vertices_label->setText("Vertices: " +
                              QString::number(model->GetVertices().size()));
  ui->faces_label->setText("Faces: " +
                           QString::number(model->GetFaces().size()));
}
}  // namespace s21
