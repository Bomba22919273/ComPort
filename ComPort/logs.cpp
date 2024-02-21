#include "logs.h"
#include "ui_logs.h"

#include <QJsonDocument>

Logs::Logs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logs)
{
    ui->setupUi(this);

    //default
    ui->radioButtonDataBits8->setChecked(true);
    ui->radioButtonBaudRate115200->setChecked(true);
    ui->radioButtonParityNone->setChecked(true);
    ui->radioButtonStopBits1->setChecked(true);




}

Logs::~Logs()
{
    delete ui;
}

void Logs::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(840,68,300,180);
}

void Logs::settingsSerialPort(QSerialPort &serialPort)
{
    this->serialPortLogs = &serialPort;
    ui->textBrowserLogs->append("connect");
    selectedBaudRate();
    selectedDataBits();
    selectedParityNone();
    selectStopBits();



}

void Logs::showLogs(QString dataFromComPort)
{

    ui->textBrowserLogs->append(dataFromComPort);

//    int selectBaudRate = ui->buttonGroupBaudRate->checkedId();
//    ui->textBrowser_logs->append(QString::number(selectBaudRate));

//    int selectDataBits = ui ->buttonGroupDataBits->checkedId();
//    ui->textBrowser_logs->append(QString::number(selectDataBits));

//     int selectParityNone = ui ->buttonGroupParity->checkedId();
//     ui->textBrowser_logs->append(QString::number(selectParityNone));

//     int selectStopBits = ui ->buttonGroupStopBits->checkedId();
//     ui->textBrowser_logs->append(QString::number(selectStopBits));


}


void Logs::selectedBaudRate()
{
    int selectBaudRate = ui->buttonGroupBaudRate->checkedId();

    switch (selectBaudRate) {

    //4800
    case -2:
    {
        serialPortLogs->setBaudRate(QSerialPort::Baud4800);
        break;
    }

    //9600
    case -3:
    {
        serialPortLogs->setBaudRate(QSerialPort::Baud9600);
        break;
    }

    //19200
    case -4:
    {
        serialPortLogs->setBaudRate(QSerialPort::Baud19200);
        break;
    }

    //38400
    case -5:
    {
        serialPortLogs->setBaudRate(QSerialPort::Baud38400);
        break;
    }

    //57600
    case -6:
    {
        serialPortLogs->setBaudRate(QSerialPort::Baud57600);
        break;
    }

    //115200
    case -7:
    {
        serialPortLogs->setBaudRate(QSerialPort::Baud115200);
        break;
    }

    default:
        serialPortLogs->setBaudRate(QSerialPort::Baud115200);


    }


}

void Logs::selectedDataBits()
{
    int selectDataBits = ui ->buttonGroupDataBits->checkedId();

    switch (selectDataBits) {
    case -2:
    {
        serialPortLogs->setDataBits(QSerialPort::Data8);
        break;
    }

    case -3:
    {
        serialPortLogs->setDataBits(QSerialPort::Data6);
        break;
    }

    case -4:
    {
        serialPortLogs->setDataBits(QSerialPort::Data5);
        break;
    }

    case -5:
    {
        serialPortLogs->setDataBits(QSerialPort::Data7);
        break;
    }
   }
}

void Logs::selectedParityNone()
{
    int selectParityNone = ui ->buttonGroupParity->checkedId();
    switch (selectParityNone) {
    case -2:
    {
        serialPortLogs->setParity(QSerialPort::NoParity);
        break;
    }
    case -3:
    {
        serialPortLogs->setParity(QSerialPort::EvenParity);
        break;
    }

    case -4:
    {
        serialPortLogs->setParity(QSerialPort::OddParity);
        break;
    }

    case -5:
    {
        serialPortLogs->setParity(QSerialPort::MarkParity);
        break;
    }
    case -6:
    {
        serialPortLogs->setParity(QSerialPort::SpaceParity);
        break;
    }

   }

}

void Logs::selectStopBits()
{
    int selectStopBits = ui ->buttonGroupStopBits->checkedId();
    switch (selectStopBits) {
    case -2:
    {
        serialPortLogs->setStopBits(QSerialPort::OneStop);
//        ui->textBrowser_logs->append("1");
        break;
    }
    case -4:
    {
        serialPortLogs->setStopBits(QSerialPort::TwoStop);
//        ui->textBrowser_logs->append("2");
        break;
    }



    }
}
