#ifndef GREGORIANCALENDAR_H
#define GREGORIANCALENDAR_H

#include <string>
#include <QString>
#include <QStringList>
#include <stdexcept> // Libreria per la gestione delle eccezioni
#include <iostream> // Libreria per stampare a video i messaggi di errore lanciati dalle eccezioni

#include "Date.h" // Classe virtuale
#include "calendarexception.h" // Classe per la gestione di alcune eccezioni

class GregorianCalendar : public Date
{
public:
    GregorianCalendar();

    virtual ~GregorianCalendar() { }

    QStringList getListYear() const; // Metodo per ritornare l'intera lista degli

    // Metodo per ritornare un determinato anno attraverso un indice
    int getYear(const int i) const throw(std::out_of_range);
    // Metodo per ottenere la dimensione della lista degli anni
    int getSizeListYear() const throw (CalendarException);

    // Metodo per ottenere l'anno corrente
    int getCurrentYear() const;
    // Metodo per settare l'anno corrente
    void setCurrentYear(const int y) throw(std::out_of_range);

    // Metodo per ottenere l'anno iniziale della lista
    int getFirstYear() const;
    // Metodo per settare l'anno iniziale della lista
    void setFirstYear(const int y) throw(CalendarException);
    // Metodo per ottenere l'anno finale della lista
    int getLastYear() const;
    // Metodo per settare l'anno finale della lista
    void setLastYear(const int y) throw(CalendarException);

    // Metodo per la rimozione dell' elemento in testa alla lista
    void RemoveFirstElementListYear() throw (CalendarException);
    // Metodo per la rimozione dell' elemento in coda alla lista
    void RemoveLastElementListYear() throw (CalendarException);
    // Metodo per l'aggiunta di un elemento in testa alla lista
    void AddElementHeadListYear();
    // Metodo per l'aggiunta di un elemento in coda alla lista
    void AddElementTailListYear();

    // Metodo per ritornare l'intera lista dei mesi
    QStringList getListMonth() const;
    // Metodo per ritornare un determinato mese attraverso il passaggio di un indice
    QString getMonth(const int i) const throw(std::out_of_range);

    // Metodo per ritornare il mese corrente
    QString getCurrentMonth() const;
    // Metodo per settare il mese corrente
    void setCurrentMonth(const QString m) throw(CalendarException);

    // Metodo per ottenere il numero dei giorni dal mese e anno corrente
    int getDay() const;
    // Metodo per ottenere il numero dei giorni da un determinato mese ed un determinato anno
    int getDay(const int i_month, const int i_year) const;
    // Metodo per ottenere il giorno della settimana da cui partono i giorni
    int getDayWeek(const int i_month, int year, int i_year) const;

private:

    int current_year; // variabile per la conservazione dell'anno corrente o quello selezionato in runtime
    int first_year; // variabile per indicare il primo elemento della lista degli anni
    int last_year; // variabile per indicare l'ultimo elemento della lista degli anni
    QStringList list_year; // lista per conoscere gli anni presenti nel calendario
    QStringList list_month; // lista per conoscere i mesi presenti nel calendario
    QString current_month; // variabile per la conservazione del mese corrente o quello selezionato in runtime
};

#endif // GREGORIANCALENDAR_H
