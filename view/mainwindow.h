#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../controller/controller.h"
#include "ui_mainwindow.h"
#include "viewer.h"

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_loadButton_clicked();
  void on_moveButton_clicked();
  void on_rotateButton_clicked();
  void on_scaleButton_clicked();

 private:
  void updateModelInfo();

  Ui::MainWindow *ui;
  Controller *controller_;
};
}  // namespace s21

#endif  // MAINWINDOW_H
