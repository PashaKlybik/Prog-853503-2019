#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T15:43:36
#
#-------------------------------------------------

QT       += core gui opengl

win32: LIBS += -lOpengl32

CONFIG += C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rubik
TEMPLATE = app

SOURCES += main.cpp\
        rubik.cpp \
    state.cpp \
    result.cpp \
    3Dmodel.cpp \
    resolve.cpp

HEADERS  += rubik.h \
    state.h \
    result.h \
    3Dmodel.h \
    resolve.h

FORMS    += rubik.ui \
    result.ui

RESOURCES += \
    rubik.qrc
