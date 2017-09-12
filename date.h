#ifndef DATE_H
#define DATE_H

#include <time.h> // Libreria per ottenere la data attuale dal sistema operativo
#include <QString>


class Date
{
public:
    virtual void CurrentDate() = 0;

protected:
    time_t date; // variabile per ottenere la data attuale dal sistema operativo
    struct tm* getDate = NULL; // struttura con attributi necessari per leggere tutti i valori ottenuti dalla
                               // variabile time
};

#endif // DATE_H
