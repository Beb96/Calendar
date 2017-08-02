#ifndef GREGORIANCALENDAR_H
#define GREGORIANCALENDAR_H

#include <time.h>
#include "Date.h"
#include <vector>
#include <string>
#include <QString>

class GregorianCalendar : public Date
{
public:
    GregorianCalendar() {
        time(&date);
        getDate = localtime(&date);
        readDate = asctime(getDate);

        gregorianYear = getDate->tm_year;
        gregorianMonth = getDate->tm_mon + 1;

        nameMonth[0] = "Jenuary";
        nameMonth[1] = "February";
        nameMonth[2] = "March";
        nameMonth[3] = "April";
        nameMonth[4] = "May";
        nameMonth[5] = "June";
        nameMonth[6] = "July";
        nameMonth[7] = "August";
        nameMonth[8] = "September";
        nameMonth[9] = "October";
        nameMonth[10] = "November";
        nameMonth[11] = "December";
    }

    virtual ~GregorianCalendar() { delete[] nameMonth; }

    virtual int getYear() const;
    virtual int getMonth() const;
    virtual int getDay(QString month) const;
    //virtual std::string * getNameMonth(int const pos) const;

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
