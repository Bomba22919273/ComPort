#include "logs.h"
#include "ui_logs.h"

#include <QJsonDocument>

Logs::Logs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logs)
{
    ui->setupUi(this);


    ui->comboBox_logs->addItem("115200");
    ui->comboBox_logs->addItem("9600");

    selectedBaudRate();

}

Logs::~Logs()
{
    delete ui;
}

void Logs::logsIsOpen(QString data)
{

    ui->textBrowser_logs->append(data);


}


void Logs::selectedBaudRate()
{
    QString selectBaudRate = ui->comboBox_logs->currentText();
    int currentBaudRate = selectBaudRate.toInt();
    switch (currentBaudRate) {

    case 115200:
    {
        serialPortLogs.setBaudRate(QSerialPort::Baud115200);
        serialPortLogs.setDataBits(QSerialPort::Data8);
        serialPortLogs.setStopBits(QSerialPort::OneStop);
        serialPortLogs.setParity(QSerialPort::NoParity);
        serialPortLogs.setFlowControl(QSerialPort::NoFlowControl);

    }

    case 9600:
    {
        serialPortLogs.setBaudRate(QSerialPort::Baud115200);
        serialPortLogs.setDataBits(QSerialPort::Data8);
        serialPortLogs.setStopBits(QSerialPort::OneStop);
        serialPortLogs.setParity(QSerialPort::NoParity);
        serialPortLogs.setFlowControl(QSerialPort::NoFlowControl);


    }



    }



}
