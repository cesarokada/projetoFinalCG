#-------------------------------------------------
#
# Project created by QtCreator 2015-07-24T11:19:40
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = projetoFinalCG
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    camera.cpp \
    planetas.cpp

LIBS += -lglut
LIBS += -lGL
LIBS += -lGLU

HEADERS += \
    camera.h \
    planetas.h

