#include "GregorianCalendar.h"

void GregorianCalendar::CurrentDate() {
    time(&date);
    getDate = localtime(&date);
    readDate = asctime(getDate);
}

int GregorianCalendar::getYear(const int i) const throw(std::out_of_range) {
    if (i < 0 || i > getSizeListYear())
        throw std::out_of_range("Indice errato per la selezione dell'anno ");
    QString y = list_year.at(i).toLocal8Bit().constData();
    return y.split(" ")[0].toInt();
}

int GregorianCalendar::getSizeListYear() const throw (CalendarException) {
    if (list_year.size() < 0)
        throw CalendarException("Errore! La lista non è stata inizializzata ");
    return list_year.size();
}

int GregorianCalendar::getCurrentYear() const {
    return current_year;
}

void GregorianCalendar::setCurrentYear(const int y) throw (std::out_of_range){
    if (y < first_year || y > last_year)
        throw std::out_of_range("Errore. Inserimento anno fuori dal range ");
    current_year = y;
}

int GregorianCalendar::getFirstYear() const {
    return first_year;
}

int GregorianCalendar::getLastYear() const {
    return last_year;
}

QString GregorianCalendar::getMonth(const int i) const throw(std::out_of_range) {
    if (i < 0 || i > 11)
        throw std::out_of_range("Indice errato per la selezione del mese");
    return list_month.at(i).toLocal8Bit().constData();
}

QString GregorianCalendar::getCurrentMonth() const {
    return current_month;
}

void GregorianCalendar::setCurrentMonth(const QString m) throw (CalendarException){
    bool result = false;
    for (int i = 0; i < 12; i++) {
        if(m == list_month.at(i).toLocal8Bit().constData())
            result = true;
    }
    if (!result)
        throw CalendarException("Errore! Inserimento mese insesistente");
    current_month = m;
}


int GregorianCalendar::getDay() const {
    int nday = 0;
    if (getCurrentMonth() == "Febbraio") {
        if (getCurrentYear()%400 == 0)
            nday = 29;
        else if (getCurrentYear()%100 == 0)
            nday = 28;
        else if (getCurrentYear()% 4 == 0)
            nday = 29;
        else
            nday = 28;
    }
    else if (getCurrentMonth() == "Novembre" || getCurrentMonth() == "Aprile" || getCurrentMonth() == "Giugno" || getCurrentMonth() == "Settembre")
        nday = 30;
    else
        nday = 31;
    return nday;
}

int GregorianCalendar::getDay(const int i_month, const int i_year) const {
    int nday = 0;
    QString m;
    try {
        m = getMonth(i_month);
    }
    catch (std::out_of_range err) {
        std::cerr << err.what() << std::endl;
    }

    if (m == "Febbraio") {
        try {
            if (getYear(i_year)%400 == 0)
                nday = 29;
            else if (getYear(i_year)%100 == 0)
                nday = 28;
            else if (getYear(i_year)% 4 == 0)
                nday = 29;
            else
                nday = 28;
        }
        catch (std::out_of_range err) {
            std::cerr << err.what() << std::endl;
        }
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
