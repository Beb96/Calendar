#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
{
    setupUi(this);
    gc = new GregorianCalendar();
    time = new Timer();

    lcdNumber_Minutes->display(time->getMinute());
    lcdNumber_Hour->display(time->getHour());

    tempo = std::thread(&MainWindow::ViewTime, this);
    //tempo(ViewTime);

    comboBox_Month->addItem("Jenuary");
    comboBox_Month->addItem("February");
    comboBox_Month->addItem("March");
    comboBox_Month->addItem("April");
    comboBox_Month->addItem("May");
    comboBox_Month->addItem("June");
    comboBox_Month->addItem("July");
    comboBox_Month->addItem("August");
    comboBox_Month->addItem("September");
    comboBox_Month->addItem("October");
    comboBox_Month->addItem("November");
    comboBox_Month->addItem("December");

    comboBox_Month->setCurrentText(gc->getMonth());

    for (int i = 1900; i <= 2030; i++) {
        comboBox_Year->addItem(QString::number(i));
    }

    comboBox_Year->setCurrentText(QString::number(gc->getYear()));

    ViewDay();

    connect(comboBox_Month, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeMonth()));
    connect(comboBox_Year, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeYear()));

}

void MainWindow::ViewTime() {
    int init = 0;
    do
    {
        do
        {
          if (init == 1)
              time->Wait(60);
          else {
              time->Wait(60 - time->getSecond());
              init = 1;
          }
          time->setMinute();
          lcdNumber_Minutes->display(time->getMinute());
        } while (time->getMinute() < 60);
        time->zeroMinute();
        lcdNumber_Minutes->display(time->getMinute());
        time->setHour();
        lcdNumber_Hour->display(time->getHour());
    } while(time->getHour() <= 24);
}

MainWindow::~MainWindow() {
    tempo.join();
    delete gc;
    delete time;
}

void MainWindow::ChangeYear() {
    gc->setYear(comboBox_Year->currentText().split(" ")[0].toInt());
    ViewDay();
}

void MainWindow::ChangeMonth() {
    gc->setMonth(comboBox_Month->currentText());
    ViewDay();
}

void MainWindow::ViewDay() {
    ClearView();
    int nday = gc->getDay();
    for (int i = 1; i <= nday; i++) {
        textEdit_Day->append(QString::number(i));
    }
}

void MainWindow::ClearView() {
    textEdit_Day->clear();
}
