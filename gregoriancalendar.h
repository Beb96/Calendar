#ifndef GREGORIANCALENDAR_H
#define GREGORIANCALENDAR_H

#include <time.h>
#include "Date.h"

class GregorianCalendar : public Date
{
public:
    GregorianCalendar() {
        time(&date);
        getDate = localtime(&date);
        readDate = asctime(getDate);

        gregorianYear = getDate->tm_year;
        gregorianMonth = getDate->tm_mon;

        int maxDay = 31;
        for (int i = 1; i <= maxDay; i++) {
            gregorianDay[i] = i;
        }
    }

    virtual ~GregorianCalendar() {
        delete[] gregorianDay;
    }

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
    int* gregorianDay = new int [31];
};

#endif // GREGORIANCALENDAR_H
