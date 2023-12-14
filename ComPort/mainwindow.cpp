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

//int ModBusCRC16( int* p, unsigned short n)
//{
//    int w, i;
//    unsigned char j;
//    for (w = 0xFFFF, i = 0; i < n; i++)
//    {
//        w ^= p[i];
//        for (j = 0; j < 8; j++)
//        if (w & 1)
//        {
//            w >>= 1;
//            w ^= 0xA001;
//        }
//        else w >>= 1;
//    }
//    return w;
//}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Отображение актуального времени
    tmr = new QTimer(this);
    tmr->start();
    tmr->setInterval(500);
    connect(tmr,SIGNAL(timeout()), this, SLOT(updateDateTime()));
    connect(tmr,SIGNAL(timeout()),this,SLOT(receiveMessage()));


    tmrAxis = new QTimer(this);
    tmrAxis -> setInterval(5000);
    connect(tmrAxis, SIGNAL(timeout()), this, SLOT(clearAxis()));
    tmrAxis ->start();
    ui->textBrowser->setText("DeviceSerial: 1, firmwareVersion:30 \r\n");




    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox_CP->addItems(stringPorts);




    initDraw_X();
    initDraw_Y();
    initDraw_XY();

}

//static int ij = 0;
void MainWindow::receiveMessage()
{
/*   QByteArray dataFromPort;
    dataFromPort = serialPort.readAll();

    QString dataInHex;
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






//___________________________________________________________________________________
    QByteArray data;
    QString x_s, y_s, x0_s, y0_s;
    data.append(serialPort.readAll()); // Чтение доступных данных из порта
    if (data.contains("\r\n")) { // Проверка наличия завершающего символа
        QString receivedData(data);

        int xIndex = receivedData.indexOf("X:") + 2;
        int yIndex = receivedData.indexOf("Y:") + 2;
        int x0Index = receivedData.indexOf("X0:") + 3;
        int y0Index = receivedData.indexOf("Y0:") + 3;
        if (xIndex != -1 && yIndex != -1 && x0Index != -1 && y0Index != -1) {
            x_s = receivedData.mid(xIndex, yIndex - xIndex - 2).trimmed();
            y_s = receivedData.mid(yIndex, x0Index - yIndex - 3).trimmed();
            x0_s = receivedData.mid(x0Index, y0Index - x0Index - 3).trimmed();
            y0_s = receivedData.mid(y0Index, receivedData.size() - y0Index - 2).trimmed();
            QString message = "X:" + x_s + " " + "Y:" + y_s + " " + "X0:" + x0_s + " " + "Y0:" + y0_s +"\r\n";
            ui->textBrowser->append(message);
        }
        data.clear();
    }
//___________________________________________________________________________________

*/

//JSON_______________________________________________________________________________
    QByteArray data;

    data.append(serialPort.readAll());
    if (data.contains("\n")) {
        QString receivedData(data);
        receivedData.remove('\r');
        QStringList jsonStrings = receivedData.split('\n');
        foreach (QString jsonString, jsonStrings) {
            QByteArray jsonData = jsonString.toUtf8();
            QJsonParseError error;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);
            QJsonObject jsonObject = jsonDoc.object();

            if (error.error == QJsonParseError::NoError) {

                QString jsonString = QString::fromUtf8(jsonDoc.toJson(QJsonDocument::Compact));
                ui->textBrowser->append(jsonString);


                QJsonValue inclinometerXValue = jsonObject.value("inclinometerX");
                if (inclinometerXValue.isDouble()) {
                    double inclinometerX = inclinometerXValue.toDouble();
                    QString x_s = QString::number(inclinometerX);
                    ui->textBrowser_X->setText(x_s);
                    number_X= x_s.toInt();

                }

                QJsonValue inclinometerYValue = jsonObject.value("inclinometerY");
                if (inclinometerYValue.isDouble()) {
                    double inclinometerY = inclinometerYValue.toDouble();
                    QString y_s = QString::number(inclinometerY);
                    ui->textBrowser_Y->setText(y_s);
                    number_Y= y_s.toInt();
                }

                QJsonValue SpringTemperatureValue = jsonObject.value("springTemperature");
                if (SpringTemperatureValue.isDouble()) {
                    double SpringTemperature = SpringTemperatureValue.toDouble();
                    QString st_s = QString::number(SpringTemperature);
                    ui->textBrowser_ST->setText(st_s);

                    QDateTime currentTime_ST = QDateTime::currentDateTime();
                    chart_X->axisX()->setMin(QDateTime::currentDateTime().addSecs(-15 * 1));       // За секунду до текущего времени системы
                    chart_X->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
                    springTemperature = st_s.toDouble();
                    series_X->append(currentTime_ST.toMSecsSinceEpoch(), springTemperature);

                }


                QJsonValue GravityValue = jsonObject.value("gravity");
                if ( GravityValue.isDouble()) {
                    double  Gravity = GravityValue.toDouble();
                    QString grav_s = QString::number( Gravity);
                    ui->textBrowser_Gravity->setText(grav_s);

                    QDateTime currentTime_gravity = QDateTime::currentDateTime();
                    chart_Y->axisX()->setMin(QDateTime::currentDateTime().addSecs(-15 * 1));       // За секунду до текущего времени системы
                    chart_Y->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
                    gravity = grav_s.toDouble();
                    series_Y->append(currentTime_gravity.toMSecsSinceEpoch(), gravity);

                }
            }
        }
        ui->textBrowser->append("\r\n");
        data.clear();
    }





//    QDateTime currentTime_X = QDateTime::currentDateTime();
//    QDateTime currentTime_Y = QDateTime::currentDateTime();


//    chart_X->axisX()->setMin(QDateTime::currentDateTime().addSecs(-15 * 1));       // За секунду до текущего времени системы
//    chart_X->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
//    chart_Y->axisX()->setMin(QDateTime::currentDateTime().addSecs(-15 * 1));       // За секунду до текущего времени системы
//    chart_Y->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));// Системное текущее время



//    number_Y = y_s.toInt();
//    number_X0= x0_s.toInt();
//    number_Y0= y0_s.toInt();

//    // Добавляем новую точку в конец кривой
//    series_X->append(currentTime_X.toMSecsSinceEpoch(), number_X);
//    series_Y->append(currentTime_Y.toMSecsSinceEpoch(), number_Y);
//    series_X0Y0->append(number_X0,number_Y0);

//    ui->textBrowser_X->setText(x_s);
//    ui->textBrowser_X0->setText(x0_s);
//    ui->textBrowser_Y->setText(y_s);
//    ui->textBrowser_Y0->setText(y0_s);


//            buffer.remove(0,20);

//        }
//        else {
//            Sleeper::msleep(50); // нужно поспать немного на случай если пришла большая посылка
//            ui->textBrowser->setTextColor(Qt::red);
//            ui->textBrowser->append("FAIL IN MBCRC16!!!");
//            QString message2 = buffer.mid(0,100);
//            ui->textBrowser->append(message2 );
//            buffer.remove(0,100);
//            }

//        if(buffer.size()!=0)
//        {
//            ui->textBrowser->setTextColor(Qt::red);

//            ui->textBrowser->append("buffer not empty!!!");
//            QString message2 = buffer.mid(0,100);
//            ui->textBrowser->append(message2);
//        }

//        ui->textBrowser->setTextColor(Qt::black);
//        ui->textBrowser->append(dataInHex);


//    }
}




MainWindow::~MainWindow()
{
    delete ui;
}


