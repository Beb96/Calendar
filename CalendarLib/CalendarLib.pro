#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T10:02:45
#
#-------------------------------------------------

QT       -= gui

TARGET = CalendarLib
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += \
            gregoriancalendar.cpp \
            timer.cpp

HEADERS += \
            gregoriancalendar.h \
            timer.h \
            date.h \
            calendarexception.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
