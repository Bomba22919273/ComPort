#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QSplineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QTimer>
#include "QDateTime"

QT_CHARTS_USE_NAMESPACE   // Использование QChart должно добавить это предложение

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    void initDraw_X();
    void initDraw_Y();

private slots:



    void receiveMessage();
    void on_RefreshButton_clicked();

    void on_ConnectButton_clicked();

    void on_DisconnectButton_clicked();

    void on_ClearButton_clicked();

    void on_StopButton_clicked();

    void updateDateTime();



private:
    Ui::MainWindow *ui;

    QTimer *timer;                           // Таймер
        QChart *chart_X;
        QChart *chart_Y; //холст
        QSplineSeries *series_X;                     //линия
        QSplineSeries *series_Y;
        QDateTimeAxis *axisX_X;                    //ось
        QDateTimeAxis *axisX_Y;
        QValueAxis *axisY_X;
        QValueAxis *axisY_Y;



    QTimer *tmr;
    QSerialPort serialPort;
    QSerialPortInfo info;
    QString buffer;
    QString code;
    QString x;
    QString y;
    QString x0;
    QString y0;
    QString hs;
    int codeSize;
    int after_hex1;
    int after_hex2;
    int after_hex3;
    int after_hex4;
    int after_hex5;
    int after_hex_wo_hs;
    int delta_x;
    int delta_y;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
    int x8;
    int arrX[8];
    int arrForMODBus[8];
    bool ok;
    int base;
};
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
 };
#endif // MAINWINDOW_H
