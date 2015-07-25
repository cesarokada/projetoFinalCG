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
    tv.cpp \
    camera.cpp \
    ventilador.cpp

LIBS += -lglut
LIBS += -lGL
LIBS += -lGLU

HEADERS += \
    tv.h \
    camera.h \
    ventilador.h

