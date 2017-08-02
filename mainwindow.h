#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
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

public slots:
    void MoreYear();
    void LessYear();
    void MoreMonth();
    void LessMonth();
    void ViewDay();
    void ClearView();

private:
    GregorianCalendar* gc;
};

#endif // MAINWINDOW_H
