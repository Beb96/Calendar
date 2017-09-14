TEMPLATE = subdirs  
SUBDIRS += Calendario \ 
    TestCalendar \
    CalendarLib

CONFIG += C++11

# Specifico che i due progetti applicativi dipendono da un progetto libreria
Calendario.depends = CalendarLib
TestCalendar.depends = CalendarLib
