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

        int month = getDate->tm_mon;

        switch (getDate->tm_mon)
        {
            case (0):
                gregorianMonth = "Jenuary";

            case (1):
                gregorianMonth = "February";

            case (2):
                gregorianMonth = "March";

            case (3):
                gregorianMonth = "April";

            case (4):
                gregorianMonth = "May";

            case (5):
                gregorianMonth = "June";

            case (6):
                gregorianMonth = "July";

            case (7):
                gregorianMonth = "August";

            case (8):
                gregorianMonth = "September";

            case (9):
                gregorianMonth = "October";

            case (10):
                gregorianMonth = "November";

            case (11):
                gregorianMonth = "December";

            default:
                gregorianMonth = "";
        }


    }

    virtual ~GregorianCalendar() { }

    virtual int getYear() const;
    virtual QString getMonth() const;
    virtual int getDay(QString month) const;

    virtual void setYear(const int y);
    virtual void setMonth(const QString m);

    //virtual int getHour() const;
    //virtual int getMinute() const;
    //virtual int getSecond() const;

private:
    int gregorianYear;
    QString gregorianMonth;
};

#endif // GREGORIANCALENDAR_H
