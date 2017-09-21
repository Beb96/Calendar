#ifndef THREADTIME_H
#define THREADTIME_H

#include <QThread>
#include "timer.h"

class ThreadTime : public QThread, Timer
{
    Q_OBJECT
public:
    explicit ThreadTime(QObject * parent = 0);
    void run(); // Metodo eseguito quando il thread invoca il metodo start()
    bool stop = false; // variabile per bloccare l'esecuzione del thread

signals:
    void MinuteChanged(int); // Segnale per indicare il cambiamento dei minuti
    void HourChanged(int); // Segnale per indicare il cambiamento dell'ora
};

#endif // THREADTIME_H
