#ifndef  MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QMutex>
#include <QThread>
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




protected:


private slots:

    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void updateDateTime();
    void draw_axis_X();
    void draw_axis_Y();
    void draw_axis_XY0();
    void clearAxis();
    void initDraw_XY0();
    void initDraw_X();
    void initDraw_Y();
    void initDraw_XY();
    void receiveMessage();
    void on_RefreshButton_clicked();
    void on_ConnectButton_clicked();
    void on_DisconnectButton_clicked();
    void on_ClearButton_clicked();
    void on_StopButton_clicked();
    void clear_XY();

private:

    Ui::MainWindow *ui;


    QChart *chart_X;
    QChart *chart_Y;
    QChart *chart_XY0;
    QChart *chart_XY;
    QSplineSeries *series_X;
    QSplineSeries *series_Y;
    QScatterSeries *series_X0Y0;
    QScatterSeries *series_XY;
    QDateTimeAxis *axisX_forChart_X;
    QDateTimeAxis *axisX_forChart_Y;
    QValueAxis *axisY_forChart_X;
    QValueAxis *axisY_forChart_Y;
    QValueAxis *axisX_forChart_XY0;
    QValueAxis *axisY_forChart_XY0;
    QValueAxis *axisX_forChart_XY;
    QValueAxis *axisY_forChart_XY;
    QTimer *tmrAxis;
    QTimer *tmr;
    QTimer *tmrXY;
    int number_X;
    int number_Y;
    int number_X0;
    int number_Y0;
    int codeSize;
    int rangeMin_X = 5000;
    int rangeMin_Y = 5000;
    int rangeMin_Y0 = 5000;
    int rangeMin_X0 = 5000;

    int rangeMax_X = -5000;
    int rangeMax_Y = -5000;
    int rangeMax_X0 = -5000;
    int rangeMax_Y0 = -5000;
    QSerialPort serialPort;
    QSerialPortInfo info;
    QString buffer;
    QString code;
    QString x;
    QString y;
    QString x0;
    QString y0;
    //QString x_s = QString::number(delta_x,10);
    //QString y_s = QString::number(delta_y,10);
    QString hs;

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
    bool ok;
    int arrX[8];
    int arrForMODBus[8];
    int X_max = -1000;
    int X_min =10000;
    int Y_max = -10000;
    int Y_min =10000;




};
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
 };

#endif // MAINWINDOW_H
