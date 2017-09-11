#ifndef GREGORIANCALENDAR_H
#define GREGORIANCALENDAR_H

#include <time.h>
#include "Date.h"
#include <string>
#include <QString>
#include <QStringList>
#include "calendarexception.h"
#include <stdexcept>
#include <iostream>

class GregorianCalendar : public Date
{
public:
    GregorianCalendar() {

        CurrentDate();
        list_month << "Gennaio" << "Febbraio" << "Marzo" << "Aprile" << "Maggio" << "Giugno" << "Luglio" << "Agosto"
                   << "Settembre" << "Ottobre" << "Novembre" << "Dicembre";

        current_month = list_month.at(getDate->tm_mon).toLocal8Bit().constData();

        current_year = getDate->tm_year + 1900;
        first_year = current_year - 5;
        last_year = current_year + 5;

        int count_year = first_year;
        for (int i = 0; i <= last_year - first_year; i++) {
            list_year.append(QString::number(count_year));
            count_year ++;
        }
    }

    virtual ~GregorianCalendar() { }

    virtual void CurrentDate() override ;

    QStringList getListYear() const;
    int getYear(const int i) const throw(std::out_of_range);
    int getSizeListYear() const throw (CalendarException);
    void RemoveFirstElementListYear() throw (CalendarException);
    void RemoveLastElementListYear() throw (CalendarException);
    void AddElementHeadListYear();
    void AddElementTailListYear();
    int getCurrentYear() const;
    void setCurrentYear(const int y) throw(std::out_of_range);

    int getFirstYear() const;
    void setFirstYear(const int y) throw(CalendarException);
    int getLastYear() const;
    void setLastYear(const int y) throw(CalendarException);

    QStringList getListMonth() const;
    QString getMonth(const int i) const throw(std::out_of_range);
    QString getCurrentMonth() const;
    void setCurrentMonth(const QString m) throw(CalendarException);

    int getDay() const;
    int getDay(const int i_month, const int i_year) const;
    int getDayWeek(const int i_month, int year, int i_year) const;

private:

    int current_year;
    int first_year;
    int last_year;
    QStringList list_year;
    QStringList list_month;
    QString current_month;
};

#endif // GREGORIANCALENDAR_H
