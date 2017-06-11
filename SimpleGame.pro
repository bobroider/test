#-------------------------------------------------
#
# Project created by QtCreator 2017-06-06T23:45:42
#
#-------------------------------------------------

QT       += core gui \
    multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console
TARGET = SimpleGame
TEMPLATE = app


SOURCES += main.cpp \
    myrect.cpp \
    mybullet.cpp \
    myenemy.cpp \
    game.cpp \
    score.cpp \
    myhealth.cpp

HEADERS  += \
    myrect.h \
    mybullet.h \
    myenemy.h \
    game.h \
    score.h \
    myhealth.h

RESOURCES += \
    rsc.qrc
