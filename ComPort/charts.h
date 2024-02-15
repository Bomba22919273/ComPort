#ifndef CHARTS_H
#define CHARTS_H

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

namespace Ui {
class Charts;
}

class Charts : public QWidget
{
    Q_OBJECT

public:
    explicit Charts(QWidget *parent = nullptr);
    ~Charts();

public slots:
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void charts_is_open();
    void drawAxis_X();
    void drawAxis_Y();
    void clearAxis();
    void initDrawChart_X();
    void initDrawChart_Y();
private:
    Ui::Charts *ui;

    QChart *chart_X;
    QChart *chart_Y;

    QSplineSeries *series_X;
    QSplineSeries *series_Y;

    QDateTimeAxis *axisX_forChart_X;
    QDateTimeAxis *axisX_forChart_Y;

    QValueAxis *axisY_forChart_X;
    QValueAxis *axisY_forChart_Y;


    double gravity;
    double springTemperature;

    int number_X;
    int number_Y;
    int rangeMin_X = 5000;
    int rangeMin_Y = 5000;
    int rangeMax_X = -5000;
    int rangeMax_Y = -5000;
};

#endif // CHARTS_H
