#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
{
    setupUi(this);
    gc = new GregorianCalendar();
    lcdNumbYear->display(gc->getYear());
    lcdNumbMonth->display(gc->getMonth());

    connect(pushButton_AddYear, SIGNAL( clicked()), this, SLOT(MoreYear()));
    connect(pushButton_LessYear, SIGNAL( clicked()), this, SLOT(LessYear()));
    connect(pushButton_MoreMonth, SIGNAL( clicked()), this, SLOT(MoreMonth()));
    connect(pushButton_LessMonth, SIGNAL( clicked()), this, SLOT(LessMonth()));
}

MainWindow::~MainWindow() {
    delete[] gc;
}


void MainWindow::MoreYear() {
    gc->setYear(+1);
    lcdNumbYear->display(gc->getYear());
}

void MainWindow::LessYear() {
    gc->setYear(-1);
    lcdNumbYear->display(gc->getYear());
}

void MainWindow::MoreMonth() {
    gc->setMonth(+1);
    lcdNumbMonth->display(gc->getMonth());
    //ViewDay();
}

void MainWindow::LessMonth() {
    gc->setMonth(-1);
    lcdNumbMonth->display(gc->getMonth());
    //ViewDay();
}

void MainWindow::ViewDay() {
    int nday = gc->getDay();

}
