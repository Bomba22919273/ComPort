#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logs.h"
#include "ui_logs.h"


void MainWindow::on_ConnectButton_clicked()
{

    QString portName = ui->comboBox_CP->currentText(); //CP- ComPort
     ui->statusBar->showMessage("Подключаюсь... ");

    serialPort.setPortName(portName);
    if(!serialPort.open(QIODevice::ReadWrite)) {
        ui->statusBar->showMessage("Не могу подключиться");
    }
    else if(!serialPort.isOpen()) {
        ui->statusBar->showMessage("Проблемы с подключением");
    } else {


        ui->statusBar->showMessage("Connected is successfully");
        ui->textBrowser->setTextColor(Qt::black);

    }
    tmrXY = new QTimer(this);
    tmrXY -> setInterval(500);
    connect(tmrXY, SIGNAL(timeout()), this, SLOT(clear_XY()));
    tmrXY -> start();

}

void Logs::on_DisconnectButton_clicked()
{
    //serialPort.close();
    ui->textBrowser_logs->append("Disconnected from COM");
    buffer.remove(0,100);
}

void Logs::on_ClearButton_clicked()
{
    ui->textBrowser_logs->clear();

}

void Logs::on_StopButton_clicked()
{

   //erialPort.close();
    buffer.remove(0,100);
    ui->textBrowser_logs->append("STOP from COM");

}

void MainWindow::on_RefreshButton_clicked()
{
    ui->comboBox_CP->clear();
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for (int i = 0 ; i < ports.size() ; i++) {
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox_CP->addItems(stringPorts);

    for(int i = 0 ; i < ports.size() ; i++) {
        stringPorts.append(ports.at(i).portName());
        ui->textBrowser->append(QString::number(i));
        ui->textBrowser->append(ports.at(i).manufacturer());
        ui->textBrowser->append(ports.at(i).description());
        ui->textBrowser->append(ports.at(i).serialNumber());
        ui->textBrowser->append(ports.at(i).systemLocation());
    }
}
