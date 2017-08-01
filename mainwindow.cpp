#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
{
    setupUi(this);
    gc = new GregorianCalendar();
    lcdNumbYear->display(gc->getYear());
    lcdNumbMonth->display(gc->getMonth());
    //ViewDay();

    connect(pushButton_AddYear, SIGNAL( clicked()), this, SLOT(MoreYear()));
    connect(pushButton_LessYear, SIGNAL( clicked()), this, SLOT(LessYear()));
    connect(pushButton_MoreMonth, SIGNAL( clicked()), this, SLOT(MoreMonth()));
    connect(pushButton_LessMonth, SIGNAL( clicked()), this, SLOT(LessMonth()));
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

/*void MainWindow::ViewDay() {
    int nday = gc->getDay();
    for (int i = 1; i <= nday; i++)

        textEdit_Day->append(QString::number(i));

}

void MainWindow::ClearView() {
    textEdit_Day->clear();
}*/
