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
}

MainWindow::~MainWindow() {
    delete[] gc;
}


void MainWindow::MoreYear() {
    gc->setYear(+1);
    lcdNumbYear->display(gc->getYear());
}
