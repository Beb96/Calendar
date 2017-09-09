#ifndef TIMER_H
#define TIMER_H

#include "Date.h"
#include "calendarexception.h"


class Timer : public Date
{
public:
    Timer() {
        CurrentDate();
        hour = getDate->tm_hour;
        minute = getDate->tm_min;
        second = getDate->tm_sec;
    }

    virtual ~Timer() { }

    virtual void CurrentDate() override;

    int getHour() const;
    void setHour();
    void setHour(int h) throw(CalendarException);

    int getMinute() const;
    void setMinute();
    void setMinute(int m) throw(CalendarException);

    int getSecond() const;
    void Wait(int const sec);

private:
    int hour;
    int minute;
    int second;
};

#endif // TIMER_H
