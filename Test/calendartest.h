#ifndef CALENDARTEST_H
#define CALENDARTEST_H

#include <QtTest> // Libreria che permette di eseguire lo unit testing
#include <string>
#include <stdexcept> // Libreria che permette la gestione delle eccezioni all'interno del programma
#include <iostream> // Libreria che permette di stampare a video il messaggio di errore una volta catturata
                    // l'eccezione

#include "GregorianCalendar.h" // Classe per la gestione del calendario gregoriano
#include "timer.h" // classe per la gestione del cronometro
#include "calendarexception.h" // classe per la gestione di alcune eccezioni

class CalendarTest : public QObject
{
    Q_OBJECT

private slots:

    void TestCurrentYear(); // Metodo per effettuare test sull'anno corrente
    void TestYear(); // Metodo per effettuare test sulla lista degli anni
    void TestBeginListYear(); // Metodo per effettuare test sulle operazioni in testa alla lista
    void TestEndListYear(); // Metodo per effettuare test sulle operazioni in coda alla lista

    void TestCurrentMonth(); // Metodo per effettuare test sul mese corrente
    void TestMonth(); // Metodo per effettuare test sulla lista dei mesi

    void TestSingleDay(); // Metodo per effettuare test sul numero dei giorni in un mese

    void TestSingleHour(); // Metodo per effettuare test sull'ora
    void TestSingleMinute(); // Metodo per effettuare test sui minuti
    void TestHourMinute(); // Metodo per effettuare test per l'interazione tra minuti ed ora

};

#endif // CALENDARTEST_H
