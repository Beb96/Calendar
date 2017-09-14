#ifndef CALENDARAPPLICATIONTEST_H
#define CALENDARAPPLICATIONTEST_H

#include <QObject>
#include <QtTest/QtTest> // libreria per la gestione dell'unit testing
#include <stdexcept> // libreria per la gestione delle eccezioni

#include "gregoriancalendar.h" // classe per la gestione delle eccezioni
#include "timer.h" // classe per la gestione del tempo
#include "calendarexception.h" // classe per la gestione del calendario

class CalendarApplicationTest : public QObject
{
    Q_OBJECT
public:
    explicit CalendarApplicationTest(QObject * parent = 0);

private slots:
    void TestCurrentYear(); // Metodo per effettuare test sull'anno corrente
    void TestYear(); // Metodo per effettuare test sulla lista degli anni
    void TestBeginListYear(); // Metodo per effettuare test sulle operazioni in testa alla lista
    void TestEndListYear(); // Metodo per effettuare test sulle operazioni in coda alla lista

    void TestCurrentMonth(); // Metodo per effettuare test sul mese corrente
    void TestMonth(); // Metodo per effettuare test sulla lista dei mesi

    void TestSingleDay(); // Metodo per effettuare test sul numero dei giorni in un mese
    void TestDayWeek(); // Metodo per effettuare test sul giorno della settimana in cui inizia il mese

    void TestSingleHour(); // Metodo per effettuare test sull'ora
    void TestSingleMinute(); // Metodo per effettuare test sui minuti
    void TestHourMinute(); // Metodo per effettuare test per l'interazione tra minuti ed ora
};

#endif // CALENDARAPPLICATIONTEST_H
