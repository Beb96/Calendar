#ifndef CALENDARTEST_H
#define CALENDARTEST_H

#include <QtTest>
#include "GregorianCalendar.h"
#include "timer.h"
#include <string>
#include "mainwindow.h"
#include <stdexcept>
#include <iostream>
#include "calendarexception.h"

class CalendarTest : public QObject
{
    Q_OBJECT

private slots:

    void TestCurrentYear();
    void TestYear();

    void TestCurrentMonth();
    void TestMonth();

    void TestSingleDay();

    void TestSingleHour();
    void TestSingleMinute();
    void TestHourMinute();

};

#endif // CALENDARTEST_H
