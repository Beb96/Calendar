#include "GregorianCalendar.h"

void GregorianCalendar::CurrentDate() {
    time(&date);
    getDate = localtime(&date);
    readDate = asctime(getDate);
}

int GregorianCalendar::getCurrentYear() const {
    return current_year;
}

int GregorianCalendar::getYear(const int i) const {
    QString y = list_year.at(i).toLocal8Bit().constData();
    return y.split(" ")[0].toInt();
}

int GregorianCalendar::getSizeListYear() const {
    return list_year.size();
}

QString GregorianCalendar::getMonth(const int i) const {
    return list_month.at(i).toLocal8Bit().constData();
}

QString GregorianCalendar::getCurrentMonth() const {
    return current_month;
}

void GregorianCalendar::setCurrentMonth(const QString m) {
    current_month = m;
}

void GregorianCalendar::setCurrentYear(const int y) {
    current_year = y;
}


int GregorianCalendar::getDay() const {
    int nday = 0;
    if (current_month == "Febbraio") {
        if (getCurrentYear()%400 == 0)
            nday = 29;
        else if (getCurrentYear()%100 == 0)
            nday = 28;
        else if (getCurrentYear()% 4 == 0)
            nday = 29;
        else
            nday = 28;
    }
    else if (current_month == "Novembre" || current_month == "Aprile" || current_month == "Giugno" || current_month == "Settembre")
        nday = 30;
    else
        nday = 31;
    return nday;
}

int GregorianCalendar::getDay(const int i_month, const int i_year) const {
    int nday = 0;
    QString m = list_month.at(i_month).toLocal8Bit().constData();
    if (m == "Febbraio") {
        if (getYear(i_year)%400 == 0)
            nday = 29;
        else if (getYear(i_year)%100 == 0)
            nday = 28;
        else if (getYear(i_year)% 4 == 0)
            nday = 29;
        else
            nday = 28;
    }
    else if (m == "Novembre" || m == "Aprile" || m == "Giugno" || m == "Settembre")
        nday = 30;
    else
        nday = 31;
    return nday;
}

int GregorianCalendar::getDayWeek(const int i_month, int year, int i_year) const {
    int q = 0;
    int index = year;
    q = (year - 1) / 4;
    index = index + q;
    q = (year - 1) / 100;
    index = index - q;
    q = (year - 1) / 400;
    index = index + q;

    int nday = 0;
    int count_day = 1;
    for (int i = 0; i < i_month; i++) {
        nday = getDay(i, i_year);
        for(int j = 1; j <= nday; j++)
            count_day ++;
    }
    index = index + count_day;
    int day_week = index % 7;

    if (day_week == 1)
        day_week = 6;
    else if (day_week == 0)
        day_week = 5;
    else
        day_week = day_week - 2;

    return day_week;
}
