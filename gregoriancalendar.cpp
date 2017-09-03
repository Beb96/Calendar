#include "GregorianCalendar.h"

void GregorianCalendar::CurrentDate() {
    time(&date);
    getDate = localtime(&date);
    readDate = asctime(getDate);
}

int GregorianCalendar::getYear() const {
    return gregorianYear;
}

QString GregorianCalendar::getMonth() const {
    return gregorianMonth;
}


int GregorianCalendar::getDay() const {
    int nday = 0;
    if (gregorianMonth == "February") {
        if (getYear()%400 == 0)
            nday = 29;
        else if (getYear()%100 == 0)
            nday = 28;
        else if (getYear()% 4 == 0)
            nday = 29;
        else
            nday = 28;
    }
    else if (gregorianMonth == "November" || gregorianMonth == "April" || gregorianMonth == "June" || gregorianMonth == "September")
        nday = 30;
    else
        nday = 31;
    return nday;
}

void GregorianCalendar::setYear(const int y) {
    if (y > 2030)
        gregorianYear = 2030;
    else
        gregorianYear = y;
}

void GregorianCalendar::setMonth(const QString m) {
    gregorianMonth = m;
}
