#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "timer.h"
#include <QMainWindow>
#include "gregoriancalendar.h"
#include <QString>
#include <string>



class MainWindow : public QMainWindow, private Ui::MainWindowDLG
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ViewTime();

public slots:
    void ChangeYear();
    void ChangeMonth();
    void ViewDay();
    void ClearView();

private:
    GregorianCalendar* gc;
    Timer * time;
};

#endif // MAINWINDOW_H
