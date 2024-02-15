#ifndef  MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTime>
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
#include <QLCDNumber>
#include "charts.h"
#include "logs.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(QChart *chart, QWidget *parent = nullptr);
    ~MainWindow();



signals:
    void open_charts();
    void open_logs(QString);


private slots:


    void updateDateTime();
    void initDrawChart_XY();
    void receiveMessage();
    void on_RefreshButton_clicked();
    void on_ConnectButton_clicked();
    void clearXY(int number_X, int number_Y );
    void on_openLogsButton_clicked();
    void on_openChartsButton_clicked();

private:

    Ui::MainWindow *ui;
    Logs *logs;
    Charts *charts;

    QString jsonString;
    QString x;
    QString y;
    QString x0;
    QString y0;


    QChart *chart_XY;

    QValueAxis *axisX_forChart_XY;
    QValueAxis *axisY_forChart_XY;

    QScatterSeries *series_X0Y0;
    QScatterSeries *series_XY;



    QTimer *tmrAxis;
    QTimer *tmr;
    QTimer *tmrXY;


    QString portName;
    QSerialPort serialPort;
    QSerialPortInfo info;

    int X_max = -1000;
    int X_min =10000;
    int Y_max = -10000;
    int Y_min =10000;

    bool ok;


};
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
 };

#endif // MAINWINDOW_H
