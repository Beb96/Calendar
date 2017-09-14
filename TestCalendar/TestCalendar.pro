QT += core testlib
QT -= gui

TARGET = TestCalendar
CONFIG += console
CONFIG -= app_bundle
CONFIG += testcase
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    calendarapplicationtest.cpp

HEADERS += \
    calendarapplicationtest.h

# Percorso dove trovare la parte logica del programma
# $$PWD specifica il percorso completo che porta alla directory contenente il file corrente in fase di analisi.
INCLUDEPATH += $$PWD/../CalendarLib

# Aggiunge CalendarLib al linker
# $$ OUT_PWD specifica il percorso completo che porta alla directory in cui qmake pone il Makefile generato.
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CalendarLib/release/ -lCalendarLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CalendarLib/debug/ -lCalendarLib
