#ifndef DATE_H
#define DATE_H

#include <time.h> // Libreria per ottenere la data attuale dal sistema operativo
#include <QString>


class Date
{
protected:

    // Metodo per ottenere la data, l'ora e i minuti attuali
    void CurrentDate() {
        time(&date);
        getDate = localtime(&date);
    }

    // Metodoche ritorna il valore dell'anno attuale
    int getInitYear() const {
        return getDate->tm_year + 1900;
    }

    // Metodo che ritorna il valore del mese attuale
    int getInitMonth() const {
        return getDate->tm_mon;
    }

    // Metodo che ritorna l'ora attuale
    int getInitHour() const {
        return getDate->tm_hour;
    }

    // Metodo che ritorna i minuti attuali
    int getInitMinute() const {
        return getDate->tm_min;
    }

    // Metodo che ritorna i secondi attuali
    int getInitSecond() const {
        return getDate->tm_sec;
    }


private:
    time_t date; // variabile per ottenere la data attuale dal sistema operativo
    struct tm* getDate = NULL; // struttura con attributi necessari per leggere tutti i valori ottenuti dalla
                               // variabile date
};

#endif // DATE_H
