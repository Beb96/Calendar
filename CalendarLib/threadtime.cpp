#include "threadtime.h"
#include <QtCore> // Libreria utilizzata per la gestione dei thread

ThreadTime::ThreadTime(QObject * parent) : QThread(parent)
{
}

// Metodo per l'esecuzione dello scorrere del tempo. Viene invocato quando il thread lancia il metodo start()
void ThreadTime::run()
{
    int init = 0;
    int zero_minute = 0;
    int count = getSecond();
    QMutex mutex; // Protegge una sezione del codice affinchè possa accedervi un solo thread alla volta.
    do
    {
        do
        {
            do
            {
                mutex.lock(); // blocca i thread fino a quando non viene invocato il metodo unlock()
                if(this->stop)
                    return;
                mutex.unlock(); // sblocca i thread che erano stati bloccati
                if(init == 1)
                {
                    Wait(1);
                    count ++;
                }
                else
                {
                    Wait(1);
                    count ++;
                }
            } while(count < 60);
            count = 0;
            init = 1;
            setMinute();
            emit MinuteChanged(getMinute());
            if (getMinute() == 0)
                zero_minute = 1;
        } while (zero_minute == 0);
        mutex.lock();
        if(this->stop)
            return;
        mutex.unlock();
        zero_minute = 0;
        emit HourChanged(getHour());
    } while(getHour() <= 24);
}
