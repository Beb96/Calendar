#ifndef CALENDAREXCEPTION_H
#define CALENDAREXCEPTION_H

#include <iostream> // libreria per la visualizzazione del messaggio di errore sul display
#include <string>

class CalendarException
{
public:
    CalendarException(std::string message) : error_message(message) { }
    void print_error() {
        std::cerr << error_message << std::endl;
    }

private:
    std::string error_message; // variabile contenente il messaggio di errore
};

#endif // CALENDAREXCEPTION_H
