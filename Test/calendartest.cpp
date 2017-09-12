#include "calendartest.h"

// Metodo per effettuare test sulle operazioni dell'anno corrente
void CalendarTest::TestCurrentYear() {

    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getCurrentYear(), 2017);

    gc->setCurrentYear(2015);
    QCOMPARE(gc->getCurrentYear(), 2015);

    delete gc;
}

// Metodo per effettuare test sulle operazioni sulla lista degli anni e dimensione
void CalendarTest::TestYear() {

    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getSizeListYear(), 11);

    QCOMPARE(gc->getYear(2), 2014);

    QVERIFY_EXCEPTION_THROWN(gc->getYear(20), std::out_of_range);

    delete gc;

}

// Metodo per effettuare test sulle operazioni in testa alla lista degli anni
void CalendarTest::TestBeginListYear() {
    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getFirstYear(), 2012);

    gc->setFirstYear(1);
    QCOMPARE(gc->getFirstYear(), 2013);
    QCOMPARE(gc->getSizeListYear(), 10);

    gc->setFirstYear(-1);
    gc->setFirstYear(-1);
    QCOMPARE(gc->getFirstYear(), 2011);
    QCOMPARE(gc->getSizeListYear(), 12);

    delete gc;
}

// Metodo per effettuare test sulle operazioni in coda alla lista degli anni
void CalendarTest::TestEndListYear() {
    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getLastYear(), 2022);

    gc->setLastYear(1);
    QCOMPARE(gc->getLastYear(), 2023);
    QCOMPARE(gc->getSizeListYear(), 12);

    gc->setLastYear(-1);
    gc->setLastYear(-1);
    QCOMPARE(gc->getLastYear(), 2021);
    QCOMPARE(gc->getSizeListYear(), 10);

    delete gc;
}

// Metodo per effettuare test sulle operazioni del mese corrente
void CalendarTest::TestCurrentMonth() {
    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getCurrentMonth(), QString("Settembre"));

    gc->setCurrentMonth("Giugno");
    QCOMPARE(gc->getCurrentMonth(), QString("Giugno"));

    QVERIFY_EXCEPTION_THROWN(gc->setCurrentMonth(QString("Errore")), CalendarException);

    delete gc;
}

// Metodo per effettuare test sulla lista dei mesi
void CalendarTest::TestMonth() {

    GregorianCalendar * gc = new GregorianCalendar();

    QCOMPARE(gc->getMonth(2), QString("Marzo"));
    QCOMPARE(gc->getMonth(0), QString("Gennaio"));
    QCOMPARE(gc->getMonth(11), QString("Dicembre"));

    QVERIFY_EXCEPTION_THROWN(gc->getMonth(12), std::out_of_range);

    delete gc;
}

// Metodo per effettuare test sul numero dei giorni nei vari mesi
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

// Metodo per effettuare test sulle operazioni riguardanti l'ora
void CalendarTest::TestSingleHour() {
    Timer * time = new Timer();

    time->setHour(23);
    QCOMPARE(time->getHour(), 23);

    QVERIFY_EXCEPTION_THROWN(time->setHour(26), CalendarException);

    time->setHour(24);
    QCOMPARE(time->getHour(), 0);

    delete time;
}

// Metodo per effettuare test sulle operazioni riguardante i minuti
void CalendarTest::TestSingleMinute() {
    Timer * time = new Timer();

    QVERIFY_EXCEPTION_THROWN(time->setMinute(63), CalendarException);

    time->setMinute(59);
    QCOMPARE(time->getMinute(), 59);

    delete time;
}

// Metodo per effettuare test riguardanti l'interazione tra minuti ed ora
void CalendarTest::TestHourMinute() {
    Timer * time = new Timer();

    time->setHour(10);
    QCOMPARE(time->getHour(), 10);
    time->setMinute(59);

    time->setMinute();
    QCOMPARE(time->getHour(), 11);
    QCOMPARE(time->getMinute(), 0);

    delete time;
}
