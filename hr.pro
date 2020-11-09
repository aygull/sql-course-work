#-------------------------------------------------
#
# Project created by QtCreator 2019-12-23T14:30:32
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hr
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += \
    mainwindow.ui \
    dialog.ui
