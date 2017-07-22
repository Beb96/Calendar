#ifndef JEWISHCALENDAR_H
#define JEWISHCALENDAR_H

#include "Date.h"

class JewishCalendar : public Date
{
public:
    JewishCalendar() {
        time(&date);
        getDate = localtime(&date);
        readDate = asctime(getDate);

        jewishYear = getDate->tm_year + 3761;

    }

    virtual ~JewishCalendar() {}

private:
    int jewishYear;
    int jewishMonth;
};

#endif // JEWISHCALENDAR_H
