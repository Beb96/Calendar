#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T17:10:30
#
#-------------------------------------------------

QT       += core gui
QT += widgets testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Calendario
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    GregorianCalendar.cpp \
    timer.cpp \
    Test/calendartest.cpp

HEADERS  += mainwindow.h \
    Date.h \
    GregorianCalendar.h \
    timer.h \
    Test/calendartest.h

FORMS    += mainwindow.ui




# install
target.path = mainwindow
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial3
source.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .

INSTALLS += target sources

DISTFILES +=

