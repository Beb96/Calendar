#include "GregorianCalendar.h"

// Metodo ereditato dalla classe virtuale Date. Serve per ottenere la data attuale
void GregorianCalendar::CurrentDate() {
    time(&date);
    getDate = localtime(&date);
}

// Metodo per ritornare l'intera lista degli anni
QStringList GregorianCalendar::getListYear() const {
    return list_year;
}

/* Metodo per ritornare un determinato anno attravero un indice.
 * L'eccezione viene lanciata quando l'indice ha valore minore del primo indice della lista o quando ha valore
 * maggiore della dimensione della lista.
 */
int GregorianCalendar::getYear(const int i) const throw(std::out_of_range) {
    if (i < 0 || i > getSizeListYear())
        throw std::out_of_range("Indice errato per la selezione dell'anno ");
    QString y = list_year.at(i).toLocal8Bit().constData();
    return y.split(" ")[0].toInt();
}

/* Metodo per ritornare la dimensione della lista degli anni.
 * L'eccezione viene lanciata quando la lista non contiene nemmeno un elemento.
 */
int GregorianCalendar::getSizeListYear() const throw (CalendarException) {
    if (list_year.size() < 0)
        throw CalendarException("Errore! La lista non è stata inizializzata ");
    return list_year.size();
}

// Metodo che ritorna il valore dell'anno corrente selezionato dalla comboBox
int GregorianCalendar::getCurrentYear() const {
    return current_year;
}

/* Metodo che setta il valore dell'anno corrente selezionato dalla comboBox
 * L'eccezione viene lanciata se l'anno selezionato è minore del primo elemento della lista oppure maggiore
 * dell'ultimo elemento della lista
 */
void GregorianCalendar::setCurrentYear(const int y) throw (std::out_of_range){
    if (y < first_year || y > last_year)
        throw std::out_of_range("Errore. Inserimento anno fuori dal range ");
    current_year = y;
}

// Metodo che ritorna il valore della variabile che conserva il valore del primo elemento della lista degli anni
int GregorianCalendar::getFirstYear() const {
    return first_year;
}

/* Metodo che setta il valore della variabile che conserva il valore del primo elemento della lista degli anni
 * L'eccezione viene lanciata se il primo elemento della lista degli anni è più grande dell'ultimo elemento della
 * lista degli anni
 */
void GregorianCalendar::setFirstYear(const int y) throw(CalendarException) {
    if (y > 0) {
        first_year ++;
        if (getLastYear() < getFirstYear())
            throw CalendarException("Errore. L'anno iniziale non può essere minore dell'anno finale ");
        try {
            RemoveFirstElementListYear();
        }
        catch (CalendarException& err) {
            err.print_error();
        }
    }
    else {
        first_year --;
        AddElementHeadListYear();
    }
}

// Metodo che ritorna il valore della variabile che conserva il valore dell'ultimo elemento della lista degli
// anni
int GregorianCalendar::getLastYear() const {
    return last_year;
}

/* Metodo che setta il valore della variabile che conserva il valore dell'ultimo elemento della lista degli anni
 * L'eccezione viene lanciata se il primo elemento della lista degli anni è più grande dell'ultimo elemento della
 * lista degli anni
 */
void GregorianCalendar::setLastYear(const int y) throw(CalendarException) {
    if (y > 0) {
        last_year ++;
        AddElementTailListYear();
    }
    else {
        last_year --;
        if (getLastYear() < getFirstYear())
            throw CalendarException("Errore. L'anno iniziale non può essere minore dell'anno finale ");
        try {
            RemoveLastElementListYear();
        }
        catch (CalendarException& err) {
            err.print_error();
        }
    }
}

/* Metodo che rimuove il primo elemento dalla lista degli anni.
 * L'eccezione viene lanciata se la lista è vuota
 */
void GregorianCalendar::RemoveFirstElementListYear() throw (CalendarException){
    if (list_year.isEmpty())
        throw CalendarException("La lista degli anni e' vuota. Non e' possibile rimuovere alcun elemento ");
    list_year.removeFirst();
}

/* Metodo che rimuove l'ultimo elemento della lista degli anni.
 * L'eccezione viene lanciata se la lista è vuota
 */
void GregorianCalendar::RemoveLastElementListYear() throw (CalendarException) {
    if (list_year.isEmpty())
        throw CalendarException("La lista degli anni e' vuota. Non e' possibile rimuovere alcun elemento ");
    list_year.removeLast();
}

// Metodo che aggiunge un elemento alla fine della lista degli anni e dopo la riordina in modo che diventi
// il primo elemento
void GregorianCalendar::AddElementHeadListYear() {
    list_year.append(QString::number(getLastYear()));
    list_year.sort();
}

// Metodo che aggiunge un elemento in coda alla lista degli anni
void GregorianCalendar::AddElementTailListYear() {
    list_year.append(QString::number(getLastYear()));
}

// Metodo che ritorna l'intera lista dei mesi
QStringList GregorianCalendar::getListMonth() const {
    return list_month;
}

/* Metodo che ritorna il valore di un determinato mese attraverso un indice passato come argomento.
 * L'eccezione viene lanciata se l'indice è minore dell'indice dove si trova il primo elemento oppure maggiore
 * dell'indice dove si trova l'ultimo elemento della lista dei mesi
 */
QString GregorianCalendar::getMonth(const int i) const throw(std::out_of_range) {
    int first_element = 0;
    int last_element = 11;
    if (i < first_element || i > last_element)
        throw std::out_of_range("Indice errato per la selezione del mese");
    return list_month.at(i).toLocal8Bit().constData();
}

// Metodo che ritorna il valore del mese corrente selezionato dalla comboBox
QString GregorianCalendar::getCurrentMonth() const {
    return current_month;
}

/* Metodo che setta il valore del mese corrente selezionato dalla comboBox.
 * L'eccezione viene lanciata se il mese passato come argomento non è presente nella lista dei mesi
 */
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

// Metodo che ritorna il valore del numero di giorni totali presenti nel mese corrente e nell'anno corrente
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

/* Metodo che ritorna il valore del numero di giorni totali presenti in un determinato mese e in un
 * determinato anno.
 */
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

// Metodo che ritorna il giorno della settimana in cui il mese inizia.
int GregorianCalendar::getDayWeek(const int i_month, int year, int i_year) const {
    int q = 0; // variabile utilizzata per ottenere la parte intera dei vari quozienti presenti nel metodo
    int index = year; // variabile di appoggio per effettuare le operazioni algebriche di somma e sottrazione
    q = (year - 1) / 4;
    index = index + q;
    q = (year - 1) / 100;
    index = index - q;
    q = (year - 1) / 400;
    index = index + q;

    int nday = 0; // variabile per indicare il numero di giorni presenti un determinato mese
    // variabile per contare il numero di giorni che vi sono dal 1 gennaio dell'anno corrente fino al giorno 1
    // del mese selezionato
    int count_day = 1;
    for (int i = 0; i < i_month; i++) {
        nday = getDay(i, i_year);
        for(int j = 1; j <= nday; j++)
            count_day ++;
    }
    index = index + count_day;
    /* Variabile per il calcolo del giorno della settimana, il quale però procede in questo modo:
     * 0 = Sabato
     * 1 = Domenica
     * 2 = Lunedì
     * 3 = Martedì
     * 4 = Mercoledì
     * 5 = Giovedì
     * 6 = Venerdì
     */
    int day_week = index % 7;

    if (day_week == 1)
        day_week = 6;
    else if (day_week == 0)
        day_week = 5;
    else
        day_week = day_week - 2;

    return day_week;
}
