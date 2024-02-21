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

    void chartsIsOpen();

    void scalingAxisSpringTemp(int number_X);
    void scalingAxisGravity(int number_Y);

    void displayAxisSpringTemp();
    void displayAxisGravity();

    void updateAxis(int number_X, int number_Y);

    void dataChartSpringTemp(QString dataSpringTemp);
    void dataChartGravity(QString dataGravity);

private:
    Ui::Charts *ui;

    QChart *chartGravity;
    QChart *chartSpringTemp;

    QSplineSeries *seriesGravity;
    QSplineSeries *seriesSpringTemp;

    QDateTimeAxis *axisX_Gravity;
    QDateTimeAxis *axisX_SpringTemp;

    QValueAxis *axisY_Gravity;
    QValueAxis *axisY_SpingTemp;


    double gravity;
    double springTemperature;


    int rangeMin_X = 5000;
    int rangeMin_Y = 5000;
    int rangeMax_X = -5000;
    int rangeMax_Y = -5000;
};

#endif // CHARTS_H
