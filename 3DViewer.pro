QT += core gui widgets opengl openglwidgets

CONFIG +=c++17

TARGET= 3DViewer
TEMPLATE = app

SOURCES += main.cpp \
           model/model.cc \
           model/obj_loader.cc \
           model/facade.cc \
           model/strateg_affine.cc \
           view/mainwindow.cc \
           view/viewer.cc \
           controller/controller.cc

HEADERS += model/model.h \
           model/obj_loader.h \
           model/facade.h \
           model/strateg_affine.h \
           view/mainwindow.h \
           view/viewer.h \
           controller/controller.h \
           controller/command.h

FORMS += mainwindow.ui

DESTDIR = build

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target