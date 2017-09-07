#ifndef TIMER_H
#define TIMER_H

#include "Date.h"


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
    void Wait(int const sec);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void zeroHour();
    void setHour();
    void setMinute();
    void setHour(int h);
    void setMinute(int m);


private:
    int hour;
    int minute;
    int second;
};

#endif // TIMER_H
