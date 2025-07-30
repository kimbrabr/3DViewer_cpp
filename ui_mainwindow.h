/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "view/viewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QGridLayout *gridLayout_8;
  QVBoxLayout *verticalLayout_3;
  s21::Viewer *openGLWidget;
  QStatusBar *statusbar;
  QMenuBar *menubar;
  QDockWidget *dockWidget;
  QWidget *dockWidgetContents_4;
  QVBoxLayout *verticalLayout_9;
  QWidget *widget;
  QVBoxLayout *verticalLayout_4;
  QVBoxLayout *verticalLayout_8;
  QLabel *label_2;
  QLabel *label;
  QLineEdit *moveX;
  QLabel *label_3;
  QLineEdit *moveY;
  QLabel *label_4;
  QLineEdit *moveZ;
  QPushButton *moveButton;
  QWidget *widget_2;
  QVBoxLayout *verticalLayout_5;
  QGridLayout *gridLayout_4;
  QLineEdit *rotateX_2;
  QLabel *label_5;
  QLineEdit *rotateY_2;
  QPushButton *rotateButton;
  QLabel *label_6;
  QLabel *label_7;
  QLabel *label_8;
  QLineEdit *rotateZ_2;
  QWidget *widget_3;
  QVBoxLayout *verticalLayout_6;
  QVBoxLayout *verticalLayout_7;
  QLabel *label_9;
  QLabel *label_12;
  QLineEdit *ScaleFactor;
  QPushButton *scaleButton;
  QDockWidget *dockWidget_2;
  QWidget *dockWidgetContents_5;
  QGridLayout *gridLayout_7;
  QLabel *vertices_label;
  QGridLayout *gridLayout_5;
  QLabel *faces_label;
  QDockWidget *dockWidget_3;
  QWidget *dockWidgetContents_6;
  QFormLayout *formLayout;
  QGridLayout *gridLayout_6;
  QPushButton *loadButton;
  QLabel *fileLabel;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName("MainWindow");
    MainWindow->resize(1069, 851);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName("centralwidget");
    gridLayout_8 = new QGridLayout(centralwidget);
    gridLayout_8->setObjectName("gridLayout_8");
    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setObjectName("verticalLayout_3");
    openGLWidget = new s21::Viewer(centralwidget);
    openGLWidget->setObjectName("openGLWidget");

    verticalLayout_3->addWidget(openGLWidget);

    gridLayout_8->addLayout(verticalLayout_3, 0, 0, 1, 1);

    MainWindow->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName("statusbar");
    MainWindow->setStatusBar(statusbar);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 1069, 24));
    MainWindow->setMenuBar(menubar);
    dockWidget = new QDockWidget(MainWindow);
    dockWidget->setObjectName("dockWidget");
    dockWidgetContents_4 = new QWidget();
    dockWidgetContents_4->setObjectName("dockWidgetContents_4");
    verticalLayout_9 = new QVBoxLayout(dockWidgetContents_4);
    verticalLayout_9->setObjectName("verticalLayout_9");
    widget = new QWidget(dockWidgetContents_4);
    widget->setObjectName("widget");
    verticalLayout_4 = new QVBoxLayout(widget);
    verticalLayout_4->setObjectName("verticalLayout_4");
    verticalLayout_8 = new QVBoxLayout();
    verticalLayout_8->setObjectName("verticalLayout_8");
    label_2 = new QLabel(widget);
    label_2->setObjectName("label_2");

    verticalLayout_8->addWidget(label_2);

    label = new QLabel(widget);
    label->setObjectName("label");

    verticalLayout_8->addWidget(label);

    moveX = new QLineEdit(widget);
    moveX->setObjectName("moveX");

    verticalLayout_8->addWidget(moveX);

    label_3 = new QLabel(widget);
    label_3->setObjectName("label_3");

    verticalLayout_8->addWidget(label_3);

    moveY = new QLineEdit(widget);
    moveY->setObjectName("moveY");

    verticalLayout_8->addWidget(moveY);

    label_4 = new QLabel(widget);
    label_4->setObjectName("label_4");

    verticalLayout_8->addWidget(label_4);

    moveZ = new QLineEdit(widget);
    moveZ->setObjectName("moveZ");

    verticalLayout_8->addWidget(moveZ);

    moveButton = new QPushButton(widget);
    moveButton->setObjectName("moveButton");

    verticalLayout_8->addWidget(moveButton);

    verticalLayout_4->addLayout(verticalLayout_8);

    verticalLayout_9->addWidget(widget);

    widget_2 = new QWidget(dockWidgetContents_4);
    widget_2->setObjectName("widget_2");
    verticalLayout_5 = new QVBoxLayout(widget_2);
    verticalLayout_5->setObjectName("verticalLayout_5");
    gridLayout_4 = new QGridLayout();
    gridLayout_4->setObjectName("gridLayout_4");
    rotateX_2 = new QLineEdit(widget_2);
    rotateX_2->setObjectName("rotateX_2");

    gridLayout_4->addWidget(rotateX_2, 2, 0, 1, 1);

    label_5 = new QLabel(widget_2);
    label_5->setObjectName("label_5");

    gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

    rotateY_2 = new QLineEdit(widget_2);
    rotateY_2->setObjectName("rotateY_2");

    gridLayout_4->addWidget(rotateY_2, 4, 0, 1, 1);

    rotateButton = new QPushButton(widget_2);
    rotateButton->setObjectName("rotateButton");

    gridLayout_4->addWidget(rotateButton, 7, 0, 1, 1);

    label_6 = new QLabel(widget_2);
    label_6->setObjectName("label_6");

    gridLayout_4->addWidget(label_6, 5, 0, 1, 1);

    label_7 = new QLabel(widget_2);
    label_7->setObjectName("label_7");

    gridLayout_4->addWidget(label_7, 3, 0, 1, 1);

    label_8 = new QLabel(widget_2);
    label_8->setObjectName("label_8");

    gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

    rotateZ_2 = new QLineEdit(widget_2);
    rotateZ_2->setObjectName("rotateZ_2");

    gridLayout_4->addWidget(rotateZ_2, 6, 0, 1, 1);

    verticalLayout_5->addLayout(gridLayout_4);

    verticalLayout_9->addWidget(widget_2);

    widget_3 = new QWidget(dockWidgetContents_4);
    widget_3->setObjectName("widget_3");
    verticalLayout_6 = new QVBoxLayout(widget_3);
    verticalLayout_6->setObjectName("verticalLayout_6");
    verticalLayout_7 = new QVBoxLayout();
    verticalLayout_7->setObjectName("verticalLayout_7");
    label_9 = new QLabel(widget_3);
    label_9->setObjectName("label_9");

    verticalLayout_7->addWidget(label_9);

    label_12 = new QLabel(widget_3);
    label_12->setObjectName("label_12");

    verticalLayout_7->addWidget(label_12);

    ScaleFactor = new QLineEdit(widget_3);
    ScaleFactor->setObjectName("ScaleFactor");

    verticalLayout_7->addWidget(ScaleFactor);

    scaleButton = new QPushButton(widget_3);
    scaleButton->setObjectName("scaleButton");

    verticalLayout_7->addWidget(scaleButton);

    verticalLayout_6->addLayout(verticalLayout_7);

    verticalLayout_9->addWidget(widget_3);

    dockWidget->setWidget(dockWidgetContents_4);
    MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    dockWidget_2 = new QDockWidget(MainWindow);
    dockWidget_2->setObjectName("dockWidget_2");
    dockWidgetContents_5 = new QWidget();
    dockWidgetContents_5->setObjectName("dockWidgetContents_5");
    gridLayout_7 = new QGridLayout(dockWidgetContents_5);
    gridLayout_7->setObjectName("gridLayout_7");
    vertices_label = new QLabel(dockWidgetContents_5);
    vertices_label->setObjectName("vertices_label");

    gridLayout_7->addWidget(vertices_label, 0, 0, 1, 1);

    gridLayout_5 = new QGridLayout();
    gridLayout_5->setObjectName("gridLayout_5");
    faces_label = new QLabel(dockWidgetContents_5);
    faces_label->setObjectName("faces_label");

    gridLayout_5->addWidget(faces_label, 0, 0, 1, 1);

    gridLayout_7->addLayout(gridLayout_5, 0, 1, 1, 1);

    dockWidget_2->setWidget(dockWidgetContents_5);
    MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidget_2);
    dockWidget_3 = new QDockWidget(MainWindow);
    dockWidget_3->setObjectName("dockWidget_3");
    dockWidgetContents_6 = new QWidget();
    dockWidgetContents_6->setObjectName("dockWidgetContents_6");
    formLayout = new QFormLayout(dockWidgetContents_6);
    formLayout->setObjectName("formLayout");
    gridLayout_6 = new QGridLayout();
    gridLayout_6->setObjectName("gridLayout_6");
    loadButton = new QPushButton(dockWidgetContents_6);
    loadButton->setObjectName("loadButton");

    gridLayout_6->addWidget(loadButton, 0, 0, 1, 1);

    formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout_6);

    fileLabel = new QLabel(dockWidgetContents_6);
    fileLabel->setObjectName("fileLabel");

    formLayout->setWidget(0, QFormLayout::FieldRole, fileLabel);

    dockWidget_3->setWidget(dockWidgetContents_6);
    MainWindow->addDockWidget(Qt::TopDockWidgetArea, dockWidget_3);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    label_2->setText(
        QCoreApplication::translate("MainWindow", "MOVE", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    moveX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    label_3->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    moveY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    label_4->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
    moveZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    moveButton->setText(
        QCoreApplication::translate("MainWindow", "MoveButton", nullptr));
    rotateX_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    label_5->setText(
        QCoreApplication::translate("MainWindow", "Rotate", nullptr));
    rotateY_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    rotateButton->setText(
        QCoreApplication::translate("MainWindow", "RotateButton", nullptr));
    label_6->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
    label_7->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    label_8->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    rotateZ_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    label_9->setText(
        QCoreApplication::translate("MainWindow", "Scale", nullptr));
    label_12->setText(
        QCoreApplication::translate("MainWindow", "Factor", nullptr));
    ScaleFactor->setText(
        QCoreApplication::translate("MainWindow", "1", nullptr));
    scaleButton->setText(
        QCoreApplication::translate("MainWindow", "ScaleButton", nullptr));
    vertices_label->setText(
        QCoreApplication::translate("MainWindow", "Vertices: 0", nullptr));
    faces_label->setText(
        QCoreApplication::translate("MainWindow", "Faces: 0", nullptr));
    loadButton->setText(
        QCoreApplication::translate("MainWindow", "Downloads", nullptr));
    fileLabel->setText(
        QCoreApplication::translate("MainWindow", "File not", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
