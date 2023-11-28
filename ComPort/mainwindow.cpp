#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QString>
#include <QTimer>
#include <QTime>
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
#include <QGraphicsView>
#include <QEvent>
#include <QDebug>


int ModBusCRC16( int* p, unsigned short n)
{
    int w, i;
    unsigned char j;
    for (w = 0xFFFF, i = 0; i < n; i++)
    {
        w ^= p[i];
        for (j = 0; j < 8; j++)
        if (w & 1)
        {
            w >>= 1;
            w ^= 0xA001;
        }
        else w >>= 1;
    }
    return w;
}

static int ij = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Отображение актуального времени
    tmr = new QTimer(this);
    tmr->start();
    tmr->setInterval(5);
    connect(tmr,SIGNAL(timeout()), this, SLOT(updateDateTime()));

    tmrAxis = new QTimer(this);
    tmrAxis -> setInterval(5000);
    connect(tmrAxis, SIGNAL(timeout()), this, SLOT(clearAxis()));
    tmrAxis ->start();




    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox_CP->addItems(stringPorts);
    connect(&serialPort,SIGNAL(readyRead()),this,SLOT(receiveMessage()));

    initDraw_X();
    initDraw_Y();
    initDraw_XY0();
    initDraw_XY();



}
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

        if (MBCRC16 == after_hex5)
        {


            ui->textBrowser->setTextColor(Qt::blue);
            ui->textBrowser->append("Package " + QString::number(ij) + " : " +message + " ---> " + after);
            ui->textBrowser->setTextColor(Qt::black);
            ui->textBrowser->append(".....................................................................................");



            ui->textBrowser_X->setText(x_s);
            ui->textBrowser_X0->setText(x_0_st);
            ui->textBrowser_Y->setText(y_s);
            ui->textBrowser_Y0->setText(y_0_st);

            number_X = x_s.toInt();
            number_Y = y_s.toInt();
            number_X0= x_0_st.toInt();
            number_Y0= y_0_st.toInt();



            QDateTime currentTime_X = QDateTime::currentDateTime();
            QDateTime currentTime_Y = QDateTime::currentDateTime();

            // Устанавливаем диапазон отображения координатной оси
            chart_X->axisX()->setMin(QDateTime::currentDateTime().addSecs(-15 * 1));       // За секунду до текущего времени системы
            chart_X->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
            chart_Y->axisX()->setMin(QDateTime::currentDateTime().addSecs(-15 * 1));       // За секунду до текущего времени системы
            chart_Y->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));// Системное текущее время



            if(number_X > X_max) {X_max = number_X; ui->textBrowser_X_max->setText(x_s);}
            if(number_X < X_min) {X_min = number_X; ui->textBrowser_X_min->setText(x_s);}

            if(number_Y > Y_max) {Y_max = number_Y; ui->textBrowser_Y_max->setText(y_s);}
            if(number_Y < Y_min) {Y_min = number_Y; ui->textBrowser_Y_min->setText(y_s);}
            // Добавляем новую точку в конец кривой
            series_X->append(currentTime_X.toMSecsSinceEpoch(), number_X);
            series_Y->append(currentTime_Y.toMSecsSinceEpoch(), number_Y);
            series_X0Y0->append(number_X0,number_Y0);



            draw_axis_X();
            draw_axis_Y();
            draw_axis_XY0();

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

        if(buffer.size()!=0)
        {
            ui->textBrowser->setTextColor(Qt::red);

            ui->textBrowser->append("buffer not empty!!!");
            QString message2 = buffer.mid(0,100);
            ui->textBrowser->append(message2);
        }

        ui->textBrowser->setTextColor(Qt::black);
        ui->textBrowser->append(dataInHex);


    }
}




MainWindow::~MainWindow()
{
    delete ui;
}


