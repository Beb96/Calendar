#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gregoriancalendar.h"
#include <QtGui>
#include <qlcdnumber.h>

//class QLCDNumber;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //void MoreYear();
    //void LessYear();
    //void MoreMonth();
    //void LessMonth();


private:
    Ui::MainWindow *ui;
    GregorianCalendar gc;
    QLCDNumber *lcdyear;
};

#endif // MAINWINDOW_H
