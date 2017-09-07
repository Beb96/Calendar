#include "timer.h"

void Timer::CurrentDate() {
    time(&date);
    getDate = localtime(&date);
    readDate = asctime(getDate);
}

void Timer::Wait(int const sec) {
    clock_t endwait;
    endwait = clock() + sec * CLK_TCK;
    while ( clock() < endwait);
}

int Timer::getHour() const {
    return hour;
}

int Timer::getMinute() const {
    return minute;
}

int Timer::getSecond() const {
    return second;
}

void Timer::setHour() {
    hour ++;
    if (hour == 24)
        hour = 0;
}

void Timer::setMinute() {
    if (minute == 59) {
        minute = 0;
        setHour();
    }
    else
        minute ++;
}

void Timer::setHour(int h) {
    if (h >= 24)
        hour = 0;
    else
        hour = h;
}

void Timer::setMinute(int m) {
    if (m > 60)
        minute = 0;
    else if(m == 60) {
        minute = 0;
        setHour();
    }
    else
        minute = m;
}
