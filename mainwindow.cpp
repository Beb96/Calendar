#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
{
    setupUi(this);
    gc = new GregorianCalendar();
    lcdNumbYear->display(gc->getYear());
    lcdNumbMonth->display(gc->getMonth());

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

    comboBox_Month->setCurrentIndex(gc->getMonth());

    for (int i = 1800; i <= 2030; i++) {
        comboBox_Year->addItem(QString::number(i));
    }

    comboBox_Year->setCurrentText(QString::number(gc->getYear()));

    connect(comboBox_Month, SIGNAL(currentIndexChanged(int)), this, SLOT(ViewDay()));
    connect(comboBox_Year, SIGNAL(currentIndexChanged(int)), this, SLOT(ViewDay()));

    ViewDay();
}

MainWindow::~MainWindow() {
    delete gc;
}


void MainWindow::ViewDay() {
    ClearView();
    gc->setYear(comboBox_Year->currentText().split(" ")[0].toInt());
    int nday = gc->getDay(comboBox_Month->currentText());
    for (int i = 1; i <= nday; i++) {
        textEdit_Day->append(QString::number(i));
    }
}

void MainWindow::ClearView() {
    textEdit_Day->clear();
}
