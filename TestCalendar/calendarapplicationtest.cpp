#include "calendarapplicationtest.h"

CalendarApplicationTest::CalendarApplicationTest(QObject * parent) : QObject(parent)
{
}

// Metodo per effettuare test sulle operazioni dell'anno corrente
void CalendarApplicationTest::TestCurrentYear() {

    GregorianCalendar * gc = new GregorianCalendar();

    QVERIFY2(gc->getCurrentYear() == 2017, "Mi aspetto che il valore iniziale dell'anno sia 2017");

    gc->setCurrentYear(2015);
    QVERIFY2(gc->getCurrentYear() == 2015, "Mi aspettavo il valore impostato 2015");

    delete gc;
}

// Metodo per effettuare test sulle operazioni sulla lista degli anni e dimensione
void CalendarApplicationTest::TestYear() {

    GregorianCalendar * gc = new GregorianCalendar();

    QVERIFY2(gc->getSizeListYear() == 11, "Mi aspetto che la dimensione iniziale sia 11, 5 anni prima e dopo l'anno corrente");

    QVERIFY2(gc->getYear(2) == 2014, "Mi aspettavo il terzo valore della lista che e' 2014");

    QVERIFY_EXCEPTION_THROWN(gc->getYear(20), std::out_of_range);

    delete gc;

}

// Metodo per effettuare test sulle operazioni in testa alla lista degli anni
void CalendarApplicationTest::TestBeginListYear() {
    GregorianCalendar * gc = new GregorianCalendar();

    QVERIFY2(gc->getFirstYear() == 2012, "MI aspettavo l'anno iniziale inizializzato dal costruttore, 2012");

    gc->setFirstYear(1);
    QVERIFY2(gc->getFirstYear() == 2013, "Aumento il valore dell'anno iniziale di 1, mi aspettavo 2013");
    QVERIFY2(gc->getSizeListYear() == 10, "Mi aspetto che la dimensione della lista diminuisca, quindi 10 ");

    gc->setFirstYear(-1);
    gc->setFirstYear(-1);
    QVERIFY2(gc->getFirstYear() == 2011, "Diminuisco l'anno iniziale di 2, mi aspettavo 2011");
    QVERIFY2(gc->getSizeListYear() == 12, "Mi aspetto che la dimensione della lista aumenti, quindi 12");

    delete gc;
}

// Metodo per effettuare test sulle operazioni in coda alla lista degli anni
void CalendarApplicationTest::TestEndListYear() {
    GregorianCalendar * gc = new GregorianCalendar();

    QVERIFY2(gc->getLastYear() == 2022, "Mi aspetto l'anno finale sia l'anno corrente + 5, 2022");

    gc->setLastYear(1);
    QVERIFY2(gc->getLastYear() == 2023, "Aumento l'anno finale di 1, quindi mi aspetto che sia 2023");
    QVERIFY2(gc->getSizeListYear() == 12, "Aumento l'anno finale di 1, quindi mi aspetto aumenti la dimensione della lista, 12");

    gc->setLastYear(-1);
    gc->setLastYear(-1);
    QVERIFY2(gc->getLastYear() == 2021, "Diminuisco l'anno finale di partenza di 1, quindi mi aspetto 2021");
    QVERIFY2(gc->getSizeListYear() == 10, "Diminuisco l'anno finale di 1, deve diminuire la dimensione della lista di 1, 10");

    delete gc;
}

// Metodo per effettuare test sulle operazioni del mese corrente
void CalendarApplicationTest::TestCurrentMonth() {
    GregorianCalendar * gc = new GregorianCalendar();

    QVERIFY2(gc->getCurrentMonth() == QString("Settembre"), "Mi aspetto che il mese iniziale sia Settembre");

    gc->setCurrentMonth("Giugno");
    QVERIFY2(gc->getCurrentMonth() == QString("Giugno"), "Mi aspetto corrente settato sia Giugno");

    QVERIFY_EXCEPTION_THROWN(gc->setCurrentMonth(QString("Errore")), CalendarException);

    delete gc;
}

// Metodo per effettuare test sulla lista dei mesi
void CalendarApplicationTest::TestMonth() {

    GregorianCalendar * gc = new GregorianCalendar();

    QVERIFY2(gc->getMonth(2) == QString("Marzo"), "Mi aspetto che nella posizione 2 della lista mesi sia occupata da Marzo ");
    QVERIFY2(gc->getMonth(0) == QString("Gennaio"), "Mi aspetto che nella posizione 0 della lista mesi sia occupata da Gennaio");
    QVERIFY2(gc->getMonth(11) == QString("Dicembre"), "Mi aspetto che nella posizione 11 della lista mesi sia occupata da Dicembre");

    QVERIFY_EXCEPTION_THROWN(gc->getMonth(12), std::out_of_range);

    delete gc;
}

// Metodo per effettuare test sul numero dei giorni nei vari mesi
void CalendarApplicationTest::TestSingleDay() {

    GregorianCalendar * gc = new GregorianCalendar();

    gc->setCurrentMonth("Agosto");
    QVERIFY2(gc->getDay() == 31, "Mi aspetto che Agosto abbia 31 giorni");

    gc->setCurrentMonth("Giugno");
    QVERIFY2(gc->getDay() == 30, "Mi aspetto che Giugno abbia 30 giorni");

    gc->setCurrentYear(2017);
    gc->setCurrentMonth("Febbraio");
    QVERIFY2(gc->getDay() == 28, "Mi aspetto che Febbraio abbia 28 giorni negli anni non bisestili");

    gc->setCurrentYear(2016);
    QVERIFY2(gc->getDay() == 29, "Mi aspetto che Febbraio abbia 29 giorni negli anni bisestili");

    delete gc;
}

// Metodo per effettuare test sul giorno della settimana in cui inizia il mese
void CalendarApplicationTest::TestDayWeek() {
    GregorianCalendar * gc = new GregorianCalendar();

    QVERIFY2(gc->getDayWeek(8,2017,5) == 4, "Mi aspetto che il mese di Settembre del 2017 inizi di venerdi");

    delete gc;
}

// Metodo per effettuare test sulle operazioni riguardanti l'ora
void CalendarApplicationTest::TestSingleHour() {
    Timer * time = new Timer();

    time->setHour(23);
    QVERIFY2(time->getHour() == 23, "Mi aspetto che l'ora sia impostata sul valore 23");

    QVERIFY_EXCEPTION_THROWN(time->setHour(26), CalendarException);

    time->setHour(24);
    QVERIFY2(time->getHour() == 0, "Mi aspetto che l'ora sia impostata su 0");

    delete time;
}

// Metodo per effettuare test sulle operazioni riguardante i minuti
void CalendarApplicationTest::TestSingleMinute() {
    Timer * time = new Timer();

    QVERIFY_EXCEPTION_THROWN(time->setMinute(63), CalendarException);

    time->setMinute(59);
    QVERIFY2(time->getMinute() == 59, "Mi aspetto che i minuti siano impostati su 59");

    delete time;
}

// Metodo per effettuare test riguardanti l'interazione tra minuti ed ora
void CalendarApplicationTest::TestHourMinute() {
    Timer * time = new Timer();

    time->setHour(10);
    QVERIFY2(time->getHour() == 10, "Mi aspetto che l'ora sia settata su 10");
    time->setMinute(59);

    time->setMinute();
    QVERIFY2(time->getHour() == 11, "Mi aspetto che dalle 10:59 si passi alle ore 11:00");
    QVERIFY2(time->getMinute() == 0, "Mi aspetto che dalle 10:59 si passi alle 11:00");

    delete time;
}
