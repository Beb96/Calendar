#include "calendartest.h"


void CalendarTest::TestCurrentYear() {

    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getCurrentYear(), 2017);

    gc->setCurrentYear(2015);
    QCOMPARE(gc->getCurrentYear(), 2015);

    QVERIFY_EXCEPTION_THROWN(gc->setCurrentYear(2022), std::out_of_range);

    delete gc;
}

void CalendarTest::TestYear() {

    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getSizeListYear(), 11);
    QCOMPARE(gc->getFirstYear(), 2010);
    QCOMPARE(gc->getLastYear(), 2020);

    QCOMPARE(gc->getYear(2), 2012);

    QVERIFY_EXCEPTION_THROWN(gc->getYear(20), std::out_of_range);

    delete gc;

}


void CalendarTest::TestCurrentMonth() {
    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getCurrentMonth(), QString("Settembre"));

    gc->setCurrentMonth("Giugno");
    QCOMPARE(gc->getCurrentMonth(), QString("Giugno"));

    QVERIFY_EXCEPTION_THROWN(gc->setCurrentMonth(QString("Errore")), CalendarException);

    delete gc;
}

void CalendarTest::TestMonth() {

    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getMonth(2), QString("Marzo"));
    QCOMPARE(gc->getMonth(0), QString("Gennaio"));
    QCOMPARE(gc->getMonth(11), QString("Dicembre"));

    QVERIFY_EXCEPTION_THROWN(gc->getMonth(12), std::out_of_range);

    delete gc;
}

void CalendarTest::TestSingleDay() {

    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getDay(), 30);

    gc->setCurrentMonth("Agosto");
    QCOMPARE(gc->getDay(), 31);

    gc->setCurrentMonth("Giugno");
    QCOMPARE(gc->getDay(), 30);

    gc->setCurrentMonth("Febbraio");
    QCOMPARE(gc->getDay(), 28);

    gc->setCurrentYear(2016);
    QCOMPARE(gc->getDay(), 29);

    delete gc;
}

void CalendarTest::TestSingleHour() {
    Timer * time = new Timer();

    QCOMPARE(time->getHour(), 9);

    time->setHour(23);
    QCOMPARE(time->getHour(), 23);

    QVERIFY_EXCEPTION_THROWN(time->setHour(26), CalendarException);

    time->setHour(24);
    QCOMPARE(time->getHour(), 0);

    delete time;
}

void CalendarTest::TestSingleMinute() {
    Timer * time = new Timer();

    QVERIFY_EXCEPTION_THROWN(time->setMinute(63), CalendarException);

    time->setMinute(59);
    QCOMPARE(time->getMinute(), 59);

    delete time;
}

void CalendarTest::TestHourMinute() {
    Timer * time = new Timer();

    QCOMPARE(time->getHour(), 10);
    time->setMinute(59);

    time->setMinute();
    QCOMPARE(time->getHour(), 11);
    QCOMPARE(time->getMinute(), 0);

    delete time;
}
