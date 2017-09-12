#ifndef TIMER_H
#define TIMER_H

#include "Date.h"
#include "calendarexception.h"


class Timer : public Date
{
public:
    Timer() {
        CurrentDate(); // Metodo che permette di ottenere i valori dell'ora, minuti e secondi
        hour = getDate->tm_hour;
        minute = getDate->tm_min;
        second = getDate->tm_sec;
    }

    virtual ~Timer() { }

    virtual void CurrentDate() override;

    // Metodo che ritorna il valore dell'ora attuale
    int getHour() const;
    // Metodo che incrementa il valore dell'ora di 1
    void setHour();
    // Metodo che setta il valore dell'ora con un valore passato per argomento
    void setHour(int h) throw(CalendarException);

    // Metodo che ritorna il valore dei minuti attuale
    int getMinute() const;
    // Metodo che incrementa il valore dei minuti di 1
    void setMinute();
    // Metodo che setta il valore dei minuti con un valore passato per argomento
    void setMinute(int m) throw(CalendarException);

    // Metodo che ritorna il valore dei secondi
    int getSecond() const;
    // Metodo che permette di attendere una certa quantità di secondi passata come argomento
    void Wait(int const sec);

private:
    int hour; // variabile per la conservazione dell'ora
    int minute; // variabile per la conservazione dei minuti
    int second; // variabile per la conservazione dei secondi
};

#endif // TIMER_H
