#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QString>
#include <QTimer>
#include <QTextStream>
#include <QDate>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QChartView>
#include <QApplication>
#include <QPointF>
#include <QDateTimeAxis>
#include <QDateTime>


int ModBusCRC16( int* p, unsigned short n)
{
    int w, i;
    unsigned char j;
    for (w = 0xFFFF, i = 0; i < n; i++)
    {
        w ^= p[i];
        for (j = 0; j < 8; j++) if (w & 1)
        {
                w >>= 1;
                w ^= 0xA001;
        }
            else w >>= 1;
    }
    return w;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmr = new QTimer(this);
    tmr->start();
    tmr->setInterval(1000);
    connect(tmr,SIGNAL(timeout()), this, SLOT(updateDateTime()));


// Don't DELETE
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox_CP->addItems(stringPorts);
}

void MainWindow::updateDateTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
       QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");
       ui->textBrowser_DateTime->setText(formattedDateTime);
}
void MainWindow::initDraw_X()
{
    QPen penY_X(Qt::darkBlue,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_X = new QChart();
    series_X = new QSplineSeries;
    axisX_X = new QDateTimeAxis();
    axisY_X = new QValueAxis();

    chart_X->legend()->hide();                             // Скрываем легенду
    chart_X->addSeries(series_X);                            // Добавляем линию на график
    axisX_X->setTickCount(15);                             // Устанавливаем количество осей
    axisY_X->setTickCount(5);
    axisX_X->setFormat("hh:mm:ss");                        // Устанавливаем формат отображения времени
    axisY_X->setMin(-200);                                    // Устанавливаем диапазон оси Y
    axisY_X->setMax(2000);
    axisY_X->setLinePenColor(QColor(Qt::darkBlue));        // Устанавливаем цветовой стиль оси
    axisY_X->setGridLineColor(QColor(Qt::darkBlue));
    axisY_X->setGridLineVisible(false);                    // Устанавливаем сетку оси Y не отображать
    axisY_X->setLinePen(penY_X);
    axisX_X->setLinePen(penY_X);

    chart_X->addAxis(axisX_X,Qt::AlignBottom);               // Устанавливаем положение оси координат на графике
    chart_X->addAxis(axisY_X,Qt::AlignLeft);

    series_X->attachAxis(axisX_X);                           // Добавляем данные на ось
    series_X->attachAxis(axisY_X);

    axisY_X->setTitleText("X");

    // Отображаем график в окне
    ui->graphicsView->setChart(chart_X);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);   // Устанавливаем сглаживание


}

void MainWindow::initDraw_Y()
{
    QPen penY_Y(Qt::darkRed,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_Y = new QChart();
    series_Y = new QSplineSeries;
    axisX_Y = new QDateTimeAxis();
    axisY_Y = new QValueAxis();

    chart_Y->legend()->hide();                             // Скрываем легенду
    chart_Y->addSeries(series_Y);                            // Добавляем линию на график
    axisX_Y->setTickCount(15);                             // Устанавливаем количество осей
    axisY_Y->setTickCount(5);
    axisX_Y->setFormat("hh:mm:ss");                        // Устанавливаем формат отображения времени
    axisY_Y->setMin(-200);                                    // Устанавливаем диапазон оси Y
    axisY_Y->setMax(2000);
    axisY_Y->setLinePenColor(QColor(Qt::darkRed));        // Устанавливаем цветовой стиль оси
    axisY_Y->setGridLineColor(QColor(Qt::darkRed));
    axisY_Y->setGridLineVisible(false);                    // Устанавливаем сетку оси Y не отображать
    axisY_Y->setLinePen(penY_Y);
    axisX_Y->setLinePen(penY_Y);

    chart_Y->addAxis(axisX_Y,Qt::AlignBottom);               // Устанавливаем положение оси координат на графике
    chart_Y->addAxis(axisY_Y,Qt::AlignLeft);

    series_Y->attachAxis(axisX_Y);                           // Добавляем данные на ось
    series_Y->attachAxis(axisY_Y);

    axisY_Y->setTitleText("Y");

    // Отображаем график в окне
    ui->graphicsView_2->setChart(chart_Y);
    ui->graphicsView_2->setRenderHint(QPainter::Antialiasing);   // Устанавливаем сглаживание


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


static int ij = 0;
void MainWindow::receiveMessage()
{
    QByteArray dataFromPort;
    dataFromPort = serialPort.readAll();

    QString dataInHex(dataFromPort.toHex());
    buffer.append(dataInHex);
    if(buffer.length() > 19)
    {

       QString message = buffer.mid(0,20);
       x = buffer.mid(2,2) + buffer.mid(0,2);
       y = buffer.mid(6,2) + buffer.mid(4,2);
       x0 = buffer.mid(10,2) + buffer.mid(8,2);
       y0 = buffer.mid(14,2) + buffer.mid(12,2);
       hs = buffer.mid(18,2) + buffer.mid(16,2);

       QString after = x +" " + y +" " + x0 + " " + y0 + " " + hs;

       after_hex1 = after.split(" ")[0].toInt(&ok,16);
       after_hex2 = after.split(" ")[1].toInt(&ok,16);
       after_hex3 = after.split(" ")[2].toInt(&ok,16);
       after_hex4 = after.split(" ")[3].toInt(&ok,16);
       after_hex5 = after.split(" ")[4].toInt(&ok,16);

       arrX[0] = buffer.mid(0,2).toInt(&ok,16);
       arrX[1] = buffer.mid(2,2).toInt(&ok,16);
       arrX[2] = buffer.mid(4,2).toInt(&ok,16);
       arrX[3] = buffer.mid(6,2).toInt(&ok,16);
       arrX[4] = buffer.mid(8,2).toInt(&ok,16);
       arrX[5] = buffer.mid(10,2).toInt(&ok,16);
       arrX[6] = buffer.mid(12,2).toInt(&ok,16);
       arrX[7] = buffer.mid(14,2).toInt(&ok,16);

       int y_0_10 = y0.toInt(&ok, 16);
       int x_0_10 = x0.toInt(&ok, 16);

       for (int i = 0; i <= 8;++i) {
           arrForMODBus[i] = arrX[i];
       }

       int MBCRC16 = ModBusCRC16(arrForMODBus, 8);

       //integers
       delta_x = after_hex1 - after_hex3;
       delta_y = after_hex2 - after_hex4;

       QString x_s = QString::number(delta_x,10); //delta x
       QString y_s = QString::number(delta_y,10); //delta y
       QString x_0_st = QString::number(x_0_10); // x 0
       QString y_0_st = QString::number(y_0_10); // y 0

       ij++;

       if (MBCRC16 == after_hex5){

           ui->textBrowser->setTextColor(Qt::blue);
           ui->textBrowser->append("Package " + QString::number(ij) + " : " +message + " ---> " + after);
           ui->textBrowser->setTextColor(Qt::black);
           ui->textBrowser->append(".....................................................................................");

           ui->textBrowser_X->setText(x_s);
           ui->textBrowser_X0->setText(x_0_st);
           ui->textBrowser_Y->setText(y_s);
           ui->textBrowser_Y0->setText(y_0_st);


           QDateTime currentTime_X = QDateTime::currentDateTime();
           QDateTime currentTime_Y = QDateTime::currentDateTime();
           int number_X;
           int number_Y;
           // Устанавливаем диапазон отображения координатной оси
           chart_X->axisX()->setMin(QDateTime::currentDateTime().addSecs(-60 * 1));       // За секунду до текущего времени системы
           chart_X->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
           chart_Y->axisX()->setMin(QDateTime::currentDateTime().addSecs(-60 * 1));       // За секунду до текущего времени системы
           chart_Y->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));// Системное текущее время


           number_X = x_s.toInt();
           number_Y = y_s.toInt();
           // Добавляем новую точку в конец кривой
           series_X->append(currentTime_X.toMSecsSinceEpoch(), number_X);
           series_Y->append(currentTime_Y.toMSecsSinceEpoch(), number_Y);






           buffer.remove(0,20);

       }
       else {
           Sleeper::msleep(50); // нужно поспать немного на случай если пришла большая посылка
           ui->textBrowser->setTextColor(Qt::red);
           ui->textBrowser->append("FAIL IN MBCRC16!!!");
           QString message2 = buffer.mid(0,100);
           ui->textBrowser->append(message2 );
            buffer.remove(0,100);

       }

       if(buffer.size()!=0){
           ui->textBrowser->setTextColor(Qt::red);

           ui->textBrowser->append("buffer not empty!!!");
           QString message2 = buffer.mid(0,100);
           ui->textBrowser->append(message2);
       }

    ui->textBrowser->setTextColor(Qt::black);
    ui->textBrowser->append(dataInHex);


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
        serialPort.setBaudRate(QSerialPort::Baud9600);
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



    initDraw_X();
    initDraw_Y();
    timer = new QTimer(this);
    timer->start();
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(receiveMessage()));



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
    timer->stop();
    serialPort.close();
    buffer.remove(0,100);
    ui->textBrowser->append("STOP from COM");

}


