#ifndef DATE_H
#define DATE_H

#include <time.h>


class Date
{
public:

    virtual int getYear() const = 0;
    virtual int getMonth() const = 0;
    virtual int getDay() const = 0;

    virtual int getHour() const = 0;
    virtual int getMinute() const = 0;
    virtual int getSecond() const = 0;

protected:
    time_t date;
    struct tm* getDate = NULL;
    char* readDate = NULL;
};

#endif // DATE_H
