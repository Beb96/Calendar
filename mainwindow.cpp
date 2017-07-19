#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
{
    setupUi(this);
    GregorianCalendar();

    connect(pushButton_AddYear, SIGNAL( clicked()), this, SLOT(MoreYear()));
}


void MainWindow::MoreYear() {

}
