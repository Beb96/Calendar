#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T17:10:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calendario
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gregoriancalendar.cpp

HEADERS  += mainwindow.h \
    Date.h \
    gregoriancalendar.h

FORMS    += mainwindow.ui
