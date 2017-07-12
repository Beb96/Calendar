#ifndef DATE_H
#define DATE_H

#include <time.h>


class Date
{
public:
    Date();
    ~Date();

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

private:
    time_t date;
    struct tm* getDate = NULL;
    char* readDate = NULL;
};

#endif // DATE_H
