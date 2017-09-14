#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T09:28:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += C++11

TARGET = Calendario
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# Percorso dove trovare la parte logica del programma
# $$PWD specifica il percorso completo che porta alla directory contenente il file corrente in fase di analisi.
INCLUDEPATH += $$PWD/../CalendarLib

# Aggiunge CalendarLib al linker
# $$ OUT_PWD specifica il percorso completo che porta alla directory in cui qmake pone il Makefile generato.
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CalendarLib/release/ -lCalendarLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CalendarLib/debug/ -lCalendarLib
