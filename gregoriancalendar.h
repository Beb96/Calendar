#ifndef GREGORIANCALENDAR_H
#define GREGORIANCALENDAR_H

#include <time.h>
#include "Date.h"
#include <string>
#include <QString>

class GregorianCalendar : public Date
{
public:
    GregorianCalendar() {

        CurrentDate();
        gregorianYear = getDate->tm_year + 1900;

        switch (getDate->tm_mon)
        {
            case (0):
                gregorianMonth = "Jenuary";
                break;

            case (1):
                gregorianMonth = "February";
                break;

            case (2):
                gregorianMonth = "March";
                break;

            case (3):
                gregorianMonth = "April";
                break;

            case (4):
                gregorianMonth = "May";
                break;

            case (5):
                gregorianMonth = "June";
                break;

            case (6):
                gregorianMonth = "July";
                break;

            case (7):
                gregorianMonth = "August";
                break;

            case (8):
                gregorianMonth = "September";
                break;

            case (9):
                gregorianMonth = "October";
                break;

            case (10):
                gregorianMonth = "November";
                break;

            case (11):
                gregorianMonth = "December";
                break;

            default:
                gregorianMonth = "";
        }


    }

    virtual ~GregorianCalendar() { }

    virtual void CurrentDate() override;

    virtual int getYear() const;
    virtual QString getMonth() const;
    virtual int getDay() const;

    virtual void setYear(const int y);
    virtual void setMonth(const QString m);

private:

    int gregorianYear;
    QString gregorianMonth;
};

#endif // GREGORIANCALENDAR_H
