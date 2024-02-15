#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::updateDateTime()
{
       QDateTime currentDateTime = QDateTime::currentDateTime();
       QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

       ui->lcdNumber->display(formattedDateTime);

}
