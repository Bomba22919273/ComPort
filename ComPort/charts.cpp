#include "charts.h"
#include "ui_charts.h"

Charts::Charts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Charts)
{
    ui->setupUi(this);


}

Charts::~Charts()
{
    delete ui;
}

void Charts::chartsIsOpen()
{
    displayAxisSpringTemp();
    displayAxisGravity();
}

void Charts::dataChartSpringTemp(QString dataSpringTemp)
{
    QDateTime currentTime_ST = QDateTime::currentDateTime();
    chartGravity->axisX()->setMin(QDateTime::currentDateTime().addSecs(-15 * 1));       // За секунду до текущего времени системы
    chartGravity->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
    springTemperature = dataSpringTemp.toDouble();
    seriesGravity->append(currentTime_ST.toMSecsSinceEpoch(), springTemperature);
}

void Charts::dataChartGravity(QString dataGravity)
{
    QDateTime currentTime_gravity = QDateTime::currentDateTime();
    chartSpringTemp->axisX()->setMin(QDateTime::currentDateTime().addSecs(-15 * 1));       // За секунду до текущего времени системы
    chartSpringTemp->axisX()->setMax(QDateTime::currentDateTime().addSecs(0));
    gravity = dataGravity.toDouble();
    seriesSpringTemp->append(currentTime_gravity.toMSecsSinceEpoch(), gravity);
}
