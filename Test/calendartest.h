#ifndef CALENDARTEST_H
#define CALENDARTEST_H

#include <QtTest>
#include "GregorianCalendar.h"
#include "timer.h"
#include <string>
#include "mainwindow.h"

class CalendarTest : public QObject
{
    Q_OBJECT

private slots:
    void TestInitializeMonth_data();
    void TestInitializeMonth();
    void TestSingleMonth();

    void TestYear();

    void TestInitializeDay_data();
    void TestInitializeDay();
    void TestSingleDay();

    void TestSingleHour();
    void TestSingleMinute();
    void TestHourMinute();

};

//QTEST_MAIN(CalendarTest)

#endif // CALENDARTEST_H
