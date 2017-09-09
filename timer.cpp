#include "timer.h"

void Timer::CurrentDate() {
    time(&date);
    getDate = localtime(&date);
    readDate = asctime(getDate);
}

int Timer::getHour() const {
    return hour;
}

void Timer::setHour() {
    hour ++;
    if (hour == 24)
        hour = 0;
}

void Timer::setHour(int h) throw (CalendarException){
    if (h > 24)
        throw CalendarException("Errore. Non esiste l'ora indicata ");
    else if (h == 24)
        hour = 0;
    else
        hour = h;
}

int Timer::getMinute() const {
    return minute;
}

void Timer::setMinute() {
    if (minute == 59) {
        minute = 0;
        setHour();
    }
    else
        minute ++;
}

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

int Timer::getSecond() const {
    return second;
}

void Timer::Wait(int const sec) {
    clock_t endwait;
    endwait = clock() + sec * CLK_TCK;
    while ( clock() < endwait);
}
