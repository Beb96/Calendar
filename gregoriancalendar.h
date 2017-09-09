#ifndef GREGORIANCALENDAR_H
#define GREGORIANCALENDAR_H

#include <time.h>
#include "Date.h"
#include <string>
#include <QString>
#include <QStringList>
#include "calendarexception.h"
#include <stdexcept>

class GregorianCalendar : public Date
{
public:
    GregorianCalendar() {

        CurrentDate();
        list_month << "Gennaio" << "Febbraio" << "Marzo" << "Aprile" << "Maggio" << "Giugno" << "Luglio" << "Agosto"
                   << "Settembre" << "Ottobre" << "Novembre" << "Dicembre";

        current_month = list_month.at(getDate->tm_mon).toLocal8Bit().constData();

        int count_year = first_year;
        for (int i = 0; i <= last_year - first_year; i++) {
            list_year.append(QString::number(count_year));
            count_year ++;
        }

        current_year = getDate->tm_year + 1900;

    }

    virtual ~GregorianCalendar() { }

    virtual void CurrentDate() override ;

    int getYear(const int i) const throw(std::out_of_range);
    int getSizeListYear() const throw (CalendarException);
    int getCurrentYear() const;
    void setCurrentYear(const int y) throw(std::out_of_range);

    int getFirstYear() const;
    int getLastYear() const;

    QString getMonth(const int i) const throw(std::out_of_range);
    QString getCurrentMonth() const;
    void setCurrentMonth(const QString m) throw(CalendarException);

    int getDay() const;
    int getDay(const int i_month, const int i_year) const;
    int getDayWeek(const int i_month, int year, int i_year) const;

private:

    int current_year;
    int first_year = 2010;
    int last_year = 2020;
    QStringList list_year;
    QStringList list_month;
    QString current_month;
};

#endif // GREGORIANCALENDAR_H
