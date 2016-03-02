#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T23:34:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CrazyBreakout
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    score.cpp \
    ball.cpp \
    commonblock.cpp \
    doubleblock.cpp \
    tripleblock.cpp \
    block.cpp \
    deepblock.cpp \
    surpriseblock.cpp \
    borderblock.cpp

HEADERS  += \
    game.h \
    player.h \
    score.h \
    ball.h \
    commonblock.h \
    doubleblock.h \
    tripleblock.h \
    block.h \
    deepblock.h \
    surpriseblock.h \
    borderblock.h

FORMS    +=

RESOURCES += \
    qrs.qrc
