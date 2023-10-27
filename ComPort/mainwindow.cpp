#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QString>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox_CP->addItems(stringPorts);
}

MainWindow::~MainWindow()
{
    serialPort.close();
    delete ui;
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

    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
        ui->textBrowser->append(QString::number(i));
        ui->textBrowser->append(ports.at(i).manufacturer());
        ui->textBrowser->append(ports.at(i).description());
         ui->textBrowser->append(ports.at(i).serialNumber());
         ui->textBrowser->append(ports.at(i).systemLocation());
}
}

void MainWindow::receiveMessage()
{
    static  int ij = 0;
    QByteArray dataBA;
    double nv;
    double value;
    double vnv;

    dataBA = serialPort.readAll();
   // QString data(dataBA.toHex());
   //buffer.append(data);
   //int index = buffer.indexOf(code);
   // ui->textBrowser->append(dataBA);
    QString data(dataBA.toHex()); // cast? QByteArray to QString
    buffer.append(data);
    code = "227d0a0d";
    int index = buffer.indexOf(code);
    if (index != -1) {
        ij ++;
        QString message = buffer.mid(4,index-4);
        message.remove(message.indexOf("223a2022"),8);
        QString ADC = message.right(message.size() - 8);
        ui->textBrowser->setTextColor(Qt::blue);
        ui->textBrowser->append(QString::number(ij) + "  " + dataBA.mid(0,8)  +"   " + dataBA.mid(1,1) + ADC + dataBA.mid(1,1) + " };");
        nv = 1.250000000/0xFFFFFF;
        value = (ADC.toInt(&ok,16)&(0xFFFFFFF))>>3;
        vnv = value*nv;
        QString ADC_final = QString::number(vnv);

       buffer.remove(0,index+code.size());
    } else {
        ui->textBrowser->append(buffer);
    }
}

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
        serialPort.setBaudRate(QSerialPort::Baud115200);
        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setStopBits(QSerialPort::OneStop);
        serialPort.setParity(QSerialPort::NoParity);
        serialPort.setFlowControl(QSerialPort::NoFlowControl);
        // Коннектимся к receiveMessage чтобы у нас все работало
        ui->textBrowser->setTextColor(Qt::green);
        connect(&serialPort,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
        ui->textBrowser->append("Connected to COM");
        ui->textBrowser->setTextColor(Qt::black);
    }
}
