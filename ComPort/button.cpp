#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_ConnectButton_clicked()
{

    QString portName = ui->comboBox_CP->currentText(); //CP- ComPort
    ui->textBrowser->append("Подключаюсь к:");
    ui->textBrowser->append(portName);
    serialPort.setPortName(portName);
    if(!serialPort.open(QIODevice::ReadWrite)) {
        ui->textBrowser->setTextColor(Qt::red);
        ui->textBrowser->append("Не могу подключиться");
        ui->textBrowser->setTextColor(Qt::black);
    }
    if(!serialPort.isOpen()) {
        ui->textBrowser->setTextColor(Qt::red);
        ui->textBrowser->append("Проблема с подключением");
        ui->textBrowser->setTextColor(Qt::black);
    } else {
        serialPort.setBaudRate(QSerialPort::Baud9600);
        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setStopBits(QSerialPort::OneStop);
        serialPort.setParity(QSerialPort::NoParity);
        serialPort.setFlowControl(QSerialPort::NoFlowControl);
        ui->textBrowser->setTextColor(Qt::green);
        ui->textBrowser->append("Connected to COM");
        ui->textBrowser->setTextColor(Qt::black);

    }
    tmrXY = new QTimer(this);
    tmrXY -> setInterval(500);
    connect(tmrXY, SIGNAL(timeout()), this, SLOT(clear_XY()));
    tmrXY -> start();

}

void MainWindow::on_DisconnectButton_clicked()
{
    serialPort.close();
    ui->textBrowser->append("Disconnected from COM");
    buffer.remove(0,100);
}

void MainWindow::on_ClearButton_clicked()
{

    ui->textBrowser->clear();

}

void MainWindow::on_StopButton_clicked()
{

    serialPort.close();
    buffer.remove(0,100);
    ui->textBrowser->append("STOP from COM");

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
