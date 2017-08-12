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

void Timer::setHour() {
    if (hour == 23)
        hour = 0;
    else
        hour ++;
}

void Timer::setMinute() {
    if (minute == 60)
        minute = 0;
    else
        minute ++;
}
