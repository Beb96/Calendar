#ifndef GREGORIANCALENDAR_H
#define GREGORIANCALENDAR_H

#include <time.h>
#include "Date.h"

class GregorianCalendar : public Date
{
public:
    GregorianCalendar();
    virtual ~GregorianCalendar();

    virtual int getYear() const;
    virtual int getMonth() const;
    virtual int getDay() const;

    virtual int getHour() const;
    virtual int getMinute() const;
    virtual int getSecond() const;

private:
    int year;
    int month;
    int* day = new int [31];
};

#endif // GREGORIANCALENDAR_H
