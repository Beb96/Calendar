#include "GregorianCalendar.h"


int GregorianCalendar::getYear() const {
    return gregorianYear;
}

int GregorianCalendar::getMonth() const {
    return gregorianMonth;
}

int GregorianCalendar::getDay() const {
    int month = getMonth();
    int year = getYear();
    int nday = 0;
    if (month == 2) {
        if (year%4 == 0)
            nday = 29;
        else
            nday = 28;
    }
    else if (month == 11 || month == 4 || month == 6 || month == 9)
        nday = 30;
    else
        nday = 31;
}

void GregorianCalendar::setYear(const int y) {
    gregorianYear = gregorianYear + y;
}

void GregorianCalendar::setMonth(const int m) {
    gregorianMonth = gregorianMonth + m;
}
