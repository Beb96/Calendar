#ifndef DATE_H
#define DATE_H

#include <time.h>
#include <QString>


class Date
{
public:
    virtual void CurrentDate() = 0;

protected:
    time_t date;
    struct tm* getDate = NULL;
    char* readDate = NULL;
};

#endif // DATE_H
