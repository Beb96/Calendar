#include "timer.h"

// Metodo che ritorna il valore dell'ora attuale
int Timer::getHour() const {
    return hour;
}

// Metodo che incrementa di 1 il valore dell'ora attuale
void Timer::setHour() {
    hour ++;
    if (hour == 24)
        hour = 0;
}

/* Metodo che setta l'ora ad un certo valore passato per argomento.
 * L'eccezione viene lanciata se l'ora passata per argomento è maggiore dell'ora massima presente in un giorno
 */
void Timer::setHour(int h) throw (CalendarException){
    if (h > 24)
        throw CalendarException("Errore. Non esiste l'ora indicata ");
    else if (h == 24)
        hour = 0;
    else
        hour = h;
}

// Metodo che ritorna il valore dei minuti attuali
int Timer::getMinute() const {
    return minute;
}

// Metodo che incrementa il valore dei minuti attuali di 1
void Timer::setMinute() {
    if (minute == 59) {
        minute = 0;
        setHour();
    }
    else
        minute ++;
}

/* Metodo che setta il valore dei minuti con una certa quantità passata come argomento.
 * L'eccezione viene lanciata quando il valore passato per argomento è maggiore del valore massimo che i minuti
 * possono raprresentare.
 */
void Timer::setMinute(int m) throw (CalendarException){
    if (m > 60)
        throw CalendarException("Errore. Non esiste il minuto indicato ");
    else if(m == 60) {
        minute = 0;
        setHour();
    }
    else
        minute = m;
}

// Metodo che ritorna i secondi
int Timer::getSecond() const {
    return second;
}

// Metodo che permette di attendere una certa quantità di secondi
void Timer::Wait(int const sec) {
    clock_t endwait;
    endwait = clock() + sec * CLK_TCK;
    while ( clock() < endwait);
}
