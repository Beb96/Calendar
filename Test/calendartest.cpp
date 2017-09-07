#include "calendartest.h"


void CalendarTest::TestInitializeMonth_data() {
    QTest::addColumn<QString>("month");
    QTest::addColumn<QString>("result");

    QTest::newRow("January") << "January" << "January";
    QTest::newRow("February") << "February" << "February";
    QTest::newRow("March") << "March" << "March";
    QTest::newRow("April") << "April" << "April";
    QTest::newRow("May") << "May" << "May";
    QTest::newRow("June") << "June" << "June";
    QTest::newRow("July") << "July" << "July";
    QTest::newRow("August") << "August" << "August";
    QTest::newRow("September") << "September" << "September";
    QTest::newRow("October") << "October" << "October";
    QTest::newRow("November") << "November" << "November";
    QTest::newRow("December") << "December" << "December";

}

void CalendarTest::TestInitializeMonth() {

    GregorianCalendar gc;

    QFETCH(QString, result);

    QCOMPARE(gc.getCurrentMonth(), result);

}

void CalendarTest::TestSingleMonth() {
    GregorianCalendar gc;

    QCOMPARE(gc.getCurrentMonth(), QString("September"));

    gc.setCurrentMonth("March");
    QCOMPARE(gc.getCurrentMonth(), QString("March"));
}

void CalendarTest::TestYear() {

    GregorianCalendar gc;

    QCOMPARE(gc.getCurrentYear(), 2017);

    gc.setCurrentYear(2022);
    QCOMPARE(gc.getCurrentYear(), 2022);

}

void CalendarTest::TestInitializeDay_data() {
    QTest::addColumn<int>("number day");
    QTest::addColumn<int>("result");

    QTest::newRow("28 days") << 28 << 28;
    QTest::newRow("30 days") << 30 << 30;
    QTest::newRow("31 days") << 31 << 31;
}

void CalendarTest::TestInitializeDay() {
    GregorianCalendar gc;

    QFETCH(int, result);
    QCOMPARE(gc.getDay(), result);
}

void CalendarTest::TestSingleDay() {

    GregorianCalendar gc;

    QCOMPARE(gc.getDay(), 30);

    gc.setCurrentMonth("August");
    QCOMPARE(gc.getDay(), 31);

    gc.setCurrentMonth("June");
    QCOMPARE(gc.getDay(), 30);

    gc.setCurrentMonth("February");
    QCOMPARE(gc.getDay(), 28);

    gc.setCurrentYear(2016);
    QCOMPARE(gc.getDay(), 29);

}

void CalendarTest::TestSingleHour() {
    Timer time;

    QCOMPARE(time.getHour(), 11);

    time.setHour(23);
    QCOMPARE(time.getHour(), 23);

    time.setHour(26);
    QCOMPARE(time.getHour(), 0);

    time.setHour(24);
    QCOMPARE(time.getHour(), 0);
}

void CalendarTest::TestSingleMinute() {
    Timer time;

    time.setMinute(63);
    QCOMPARE(time.getMinute(), 0);

    time.setMinute(59);
    QCOMPARE(time.getMinute(), 59);
}

void CalendarTest::TestHourMinute() {
    Timer time;

    QCOMPARE(time.getHour(), 11);
    time.setMinute(59);

    time.setMinute();
    QCOMPARE(time.getHour(), 12);
    QCOMPARE(time.getMinute(), 0);

}
