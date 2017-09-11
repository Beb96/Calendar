#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <stdexcept>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{
    setupUi(this);
    gc = new GregorianCalendar();

    time = new Timer();

    lcdNumber_Minutes->display(time->getMinute());
    lcdNumber_Hour->display(time->getHour());

    tempo = std::thread(&MainWindow::ViewTime, this);


    CreateListMonth(comboBox_Month);

    comboBox_Month->setCurrentText(gc->getCurrentMonth());

    CreateListYear(comboBox_Year);

    lcdNumber_firstYear->display(gc->getFirstYear());
    lcdNumber_LastYear->display(gc->getLastYear());

    comboBox_Year->setCurrentText(QString::number(gc->getCurrentYear()));

    tableWidget_Day->setRowCount(6);
    tableWidget_Day->verticalHeader()->setVisible(false);
    tableWidget_Day->setColumnCount(7);
    tableWidget_Day->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList days_week;
    days_week << "Lunedì" << "Martedì" << "Mercoledì" << "Giovedì" << "Venerdì" << "Sabato" << "Domenica";
    tableWidget_Day->setHorizontalHeaderLabels(days_week);

    ViewDay();

    connect(comboBox_Month, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeMonth()));
    connect(comboBox_Year, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeYear()));
    connect(pushButton_IncreaseFirstYear, SIGNAL(clicked()), this, SLOT(IncreaseFirstYear()));
    connect(pushButton_DecrementFirstYear, SIGNAL(clicked()), this, SLOT(DecrementFirstYear()));
    connect(pushButton_IncreaseLastYear, SIGNAL(clicked()), this, SLOT(IncreaseLastYear()));
    connect(pushButton_DecrementLastYear, SIGNAL(clicked()), this, SLOT(DecrementLastYear()));
}

MainWindow::~MainWindow() {
    tempo.join();
    delete gc;
    delete time;
}

void MainWindow::ViewTime() {
    int init = 0;
    int zero_minute = 0;
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
          if (time->getMinute() == 0)
              zero_minute = 1;
          lcdNumber_Minutes->display(time->getMinute());
        } while (zero_minute == 0);
        lcdNumber_Minutes->display(time->getMinute());
        lcdNumber_Hour->display(time->getHour());
        zero_minute = 0;
    } while(time->getHour() <= 24);
}

void MainWindow::CreateListMonth(QComboBox * cb) {
    cb->addItems(gc->getListMonth());
}

void MainWindow::CreateListYear(QComboBox *cb) {
    cb->addItems(gc->getListYear());
}

void MainWindow::IncreaseFirstYear() {
    comboBox_Year->removeItem(0);
    gc->setFirstYear(1);
    try {
        gc->RemoveFirstElementListYear();
    }
    catch (CalendarException& err) {
        err.print_error();
    }
    lcdNumber_firstYear->display(gc->getFirstYear());
    ButtonEnable();
}

void MainWindow::DecrementFirstYear() {
    gc->setFirstYear(-1);
    gc->AddElementHeadListYear();
    comboBox_Year->insertItem(0,QString::number(gc->getFirstYear()));
    lcdNumber_firstYear->display(gc->getFirstYear());
    ButtonEnable();
}

void MainWindow::IncreaseLastYear() {
    gc->setLastYear(1);
    gc->AddElementTailListYear();
    comboBox_Year->addItem(QString::number(gc->getYear(gc->getSizeListYear() - 1)));
    lcdNumber_LastYear->display(gc->getLastYear());
    comboBox_Year->setCurrentText(QString::number(gc->getCurrentYear()));
    ButtonEnable();
}

void MainWindow::DecrementLastYear() {
    int index = comboBox_Year->count() - 1;
    comboBox_Year->removeItem(index);
    gc->setLastYear(-1);
    try {
        gc->RemoveLastElementListYear();
    }
    catch (CalendarException& err) {
        err.print_error();
    }
    ButtonEnable();
    lcdNumber_LastYear->display(gc->getLastYear());
}

void MainWindow::ViewDay() {

    ClearView();

    int nday = gc->getDay();

    int day_week = gc->getDayWeek(comboBox_Month->currentIndex(), gc->getCurrentYear(), comboBox_Year->currentIndex());
    int day = 1;
    int maxday_week = 7;
    for (int i = 0; i < tableWidget_Day->rowCount(); i++) {
        for (int j = day_week; j < maxday_week; j++) {
            if (day <= nday) {
                tableWidget_Day->setItem(i, j, new QTableWidgetItem(QString::number(day)));
                day ++;
            }
            else {
                break;
            }
        }
        if (day_week != 0)
            day_week = 0;
    }
}

void MainWindow::ClearView() {
    tableWidget_Day->clearContents();
}

void MainWindow::ChangeYear() {
    try {
        gc->setCurrentYear(comboBox_Year->currentText().split(" ")[0].toInt());
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Errore, selezionato anno fuori dalla lista " << std::endl;
    }

    ViewDay();
}

void MainWindow::ChangeMonth() {
    try {
        gc->setCurrentMonth(comboBox_Month->currentText());
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Errore, selezionato mese fuori dalla lista " << std::endl;
    }

    ViewDay();
}

void MainWindow::ButtonEnable() {
    if (gc->getFirstYear() == gc->getLastYear()) {
       pushButton_IncreaseFirstYear->setEnabled(false);
       pushButton_DecrementLastYear->setEnabled(false);
    }
    else {
        pushButton_IncreaseFirstYear->setEnabled(true);
        pushButton_DecrementLastYear->setEnabled(true);
    }
    if (gc->getFirstYear() == gc->getLastYear()) {
       pushButton_IncreaseFirstYear->setEnabled(false);
       pushButton_DecrementLastYear->setEnabled(false);
    }
    else {
        pushButton_IncreaseFirstYear->setEnabled(true);
        pushButton_DecrementLastYear->setEnabled(true);
    }
}
