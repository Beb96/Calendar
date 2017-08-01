#ifndef GREGORIANCALENDAR_H
#define GREGORIANCALENDAR_H

#include <time.h>
#include "Date.h"
#include <vector>
#include <string>

class GregorianCalendar : public Date
{
public:
    GregorianCalendar() {
        time(&date);
        getDate = localtime(&date);
        readDate = asctime(getDate);

        gregorianYear = getDate->tm_year;
        gregorianMonth = getDate->tm_mon + 1;

    }

    virtual ~GregorianCalendar() { delete[] nameMonth; }

    virtual int getYear() const;
    virtual int getMonth() const;
    virtual int getDay() const;

    virtual void setYear(const int y);
    virtual void setMonth(const int m);

    //virtual int getHour() const;
    //virtual int getMinute() const;
    //virtual int getSecond() const;

private:
    int gregorianYear;
    int gregorianMonth;
    std::string * nameMonth = new std::string[12];
};

#endif // GREGORIANCALENDAR_H
