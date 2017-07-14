#include "GregorianCalendar.h"


int GregorianCalendar::getYear() const {
    return gregorianYear;
}

int GregorianCalendar::getMonth() const {
    return gregorianMonth;
}

int GregorianCalendar::getDay(int pos) const {
    return gregorianDay[pos];
}

void GregorianCalendar::setYear(const int y) {
    gregorianYear = gregorianYear + y;
}

void GregorianCalendar::setMonth(const int m) {
    gregorianMonth = gregorianMonth + m;
}
