#ifndef CALENDAREXCEPTION_H
#define CALENDAREXCEPTION_H

#include <stdexcept>
#include <iostream>
#include <string>

class CalendarException
{
public:
    CalendarException(std::string message) : error_message(message) { }
    void print_error() {
        std::cerr << error_message << std::endl;
    }

private:
    std::string error_message;
};

#endif // CALENDAREXCEPTION_H
