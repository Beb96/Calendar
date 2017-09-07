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


    CreateListMonth(comboBox_Month);

    comboBox_Month->setCurrentText(gc->getCurrentMonth());

    CreateListYear(comboBox_Year);

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

MainWindow::~MainWindow() {
    tempo.join();
    delete gc;
    delete time;
}

void MainWindow::ChangeYear() {
    gc->setCurrentYear(comboBox_Year->currentText().split(" ")[0].toInt());
    ViewDay();
}

void MainWindow::ChangeMonth() {
    gc->setCurrentMonth(comboBox_Month->currentText());
    ViewDay();
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

void MainWindow::CreateListMonth(QComboBox * cb) {

    int n_month = 12;
    for (int i = 0; i < n_month; i++)
        cb->addItem(gc->getMonth(i));

}

void MainWindow::CreateListYear(QComboBox *cb) {
    for (int i = 0; i < gc->getSizeListYear(); i++) {
        cb->addItem(QString::number(gc->getYear(i)));
    }
}
