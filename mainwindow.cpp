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

    ViewDay();

    connect(pushButton_AddYear, SIGNAL( clicked()), this, SLOT(MoreYear()));
    connect(pushButton_LessYear, SIGNAL( clicked()), this, SLOT(LessYear()));
    connect(pushButton_MoreMonth, SIGNAL( clicked()), this, SLOT(MoreMonth()));
    connect(pushButton_LessMonth, SIGNAL( clicked()), this, SLOT(LessMonth()));
    connect(comboBox_Month, SIGNAL(clicked()), this, SLOT(ViewDay()));
}

MainWindow::~MainWindow() {
    delete gc;
}


void MainWindow::MoreYear() {
    gc->setYear(+1);
    lcdNumbYear->display(gc->getYear());
    //ClearView();
    //ViewDay();
}

void MainWindow::LessYear() {
    gc->setYear(-1);
    lcdNumbYear->display(gc->getYear());
    //ClearView();
    //ViewDay();
}

void MainWindow::MoreMonth() {
    gc->setMonth(+1);
    lcdNumbMonth->display(gc->getMonth());
    lcdNumbYear->display(gc->getYear());
    //ClearView();
    //ViewDay();
}

void MainWindow::LessMonth() {
    gc->setMonth(-1);
    lcdNumbMonth->display(gc->getMonth());
    lcdNumbYear->display(gc->getYear());
    //ClearView();
    //ViewDay();;
}

void MainWindow::ViewDay() {
    int nday = gc->getDay(comboBox_Month->currentText());
    for (int i = 1; i <= nday; i++) {
        textEdit_Day->append(QString::number(i));
    }
}

void MainWindow::ClearView() {
    textEdit_Day->clear();
}
