#-------------------------------------------------
#
# Project created by QtCreator 2018-03-17T21:44:18
#
#-------------------------------------------------

QT       += core gui
QT        +=Application
Qt       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cop_check
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11
SOURCES += main.cpp\
    class_2d.cpp \
    class_3d.cpp \
    class_face.cpp \
    class_line.cpp \
    class_plane.cpp \
    class_point.cpp \
    prob.cpp

HEADERS  += \
    class_face.h \
    class_2d.h \
    class_3d.h \
    class_line.h \
    class_plane.h \
    class_point.h

FORMS    += dialog.ui
