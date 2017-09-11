#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "timer.h"
#include <QMainWindow>
#include "gregoriancalendar.h"
#include <QString>
#include <string>
#include <thread>
#include "calendarexception.h"
#include <stdexcept>



class MainWindow : public QMainWindow, private Ui::MainWindowDLG
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ViewTime();
    void CreateListMonth(QComboBox * cb);
    void CreateListYear(QComboBox * cb);
    void ViewDay();
    void ClearView();
    void ButtonEnable();

public slots:
    void IncreaseFirstYear();
    void DecrementFirstYear();
    void IncreaseLastYear();
    void DecrementLastYear();
    void ChangeYear();
    void ChangeMonth();

private:
    int table_rows;
    GregorianCalendar* gc;
    Timer * time;
    std::thread tempo;
};

#endif // MAINWINDOW_H
