#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charts.h"
#include "ui_charts.h"

void Charts::clearAxis()
{
    rangeMin_X = number_X ;
    rangeMax_X = number_X ;
    rangeMin_Y = number_Y;
    rangeMax_Y = number_Y;
}

void MainWindow::clearXY(int number_X, int number_Y )
{
    initDrawChart_XY();
    series_XY->append(number_X,number_Y);

}
void Charts::initDrawChart_X()
{
    QPen penY_X(Qt::darkBlue,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_X = new QChart();
    series_X = new QSplineSeries;
    axisX_forChart_X = new QDateTimeAxis();
    axisY_forChart_X = new QValueAxis();

    chart_X->legend()->hide();
    chart_X->addSeries(series_X);
    axisX_forChart_X->setTickCount(10);
    axisY_forChart_X->setTickCount(10);
    axisX_forChart_X->setFormat("hh:mm:ss");
    axisY_forChart_X->setRange(0,4);


    axisY_forChart_X->setLinePenColor(QColor(Qt::darkBlue));
    axisY_forChart_X->setGridLineColor(QColor(Qt::darkBlue));
    axisY_forChart_X->setGridLineVisible(false);
    axisY_forChart_X->setLinePen(penY_X);
    axisX_forChart_X->setLinePen(penY_X);

    chart_X->addAxis(axisX_forChart_X,Qt::AlignBottom);
    chart_X->addAxis(axisY_forChart_X,Qt::AlignLeft);

    series_X->attachAxis(axisX_forChart_X);
    series_X->attachAxis(axisY_forChart_X);

    axisY_forChart_X->setTitleText("Spring Temperature");


    ui->graphicsView_X->setChart(chart_X);
    ui->graphicsView_X->setRenderHint(QPainter::Antialiasing);


}

void Charts::initDrawChart_Y()
{
    QPen penY_Y(Qt::darkRed,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_Y = new QChart();
    series_Y = new QSplineSeries;
    axisX_forChart_Y = new QDateTimeAxis();
    axisY_forChart_Y = new QValueAxis();
    chart_Y->legend()->hide();
    chart_Y->addSeries(series_Y);
    axisX_forChart_Y->setTickCount(10);
    axisY_forChart_Y->setTickCount(10);
    axisX_forChart_Y->setFormat("hh:mm:ss");
    axisY_forChart_Y->setRange(0,4);


    axisY_forChart_Y->setLinePenColor(QColor(Qt::darkRed));
    axisY_forChart_Y->setGridLineColor(QColor(Qt::darkRed));
    axisY_forChart_Y->setGridLineVisible(false);
    axisY_forChart_Y->setLinePen(penY_Y);
    axisX_forChart_Y->setLinePen(penY_Y);

    chart_Y->addAxis(axisX_forChart_Y, Qt::AlignBottom);
    chart_Y->addAxis(axisY_forChart_Y, Qt::AlignLeft);


    series_Y->attachAxis(axisX_forChart_Y);
    series_Y->attachAxis(axisY_forChart_Y);

    axisY_forChart_Y->setTitleText("Gravity");

    // Отображаем график в окне
    ui->graphicsView_Y->setChart(chart_Y);
    ui->graphicsView_Y->setRenderHint(QPainter::Antialiasing);


}

void MainWindow::initDrawChart_XY()
{
    QPen penXY(Qt::darkGreen, 3, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_XY = new QChart();
    series_XY = new QScatterSeries();
    axisX_forChart_XY = new QValueAxis();
    axisY_forChart_XY = new QValueAxis();
    chart_XY->legend()->hide();
    chart_XY->addSeries(series_XY);

    axisX_forChart_XY->setGridLineVisible(false);
    axisX_forChart_XY->setLinePen(penXY);
    axisX_forChart_XY->setGridLineColor(QColor(Qt::black));
    axisX_forChart_XY->setLinePenColor(QColor(Qt::black));
    axisX_forChart_XY->setTickCount(10);

    axisY_forChart_XY->setLinePen(penXY);
    axisY_forChart_XY->setLinePenColor(QColor(Qt::black));
    axisY_forChart_XY->setGridLineColor(QColor(Qt::black));
    axisY_forChart_XY->setTickCount(10);

    chart_XY->createDefaultAxes();
    chart_XY->axes(Qt::Horizontal).back()->setRange(-2500,2500);
    chart_XY->axes(Qt::Vertical).back()->setRange(-2500,2500);


    series_XY->attachAxis(axisX_forChart_XY);
    series_XY->attachAxis(axisY_forChart_XY);

    ui->graphicsView_XY->setChart(chart_XY);



}


void Charts::drawAxis_X()
{
    if( (number_X >= 0 && number_X < 1000) || (number_X <= 0 && number_X > -1000) )
    {
        if (number_X > rangeMax_X)
        {
            rangeMax_X = number_X;
            axisY_forChart_X->setMax(rangeMax_X+40);

        }
        if (number_X < rangeMin_X)
        {
            rangeMin_X = number_X;
            axisY_forChart_X->setMin(rangeMin_X-40);

        }
    }

    if ( (number_X >= 1000 && number_X < 2000) || (number_X <= -1000 && number_X > -2000) )
    {
        if (number_X > rangeMax_X)
        {
            rangeMax_X = number_X;
            axisY_forChart_X->setMax(rangeMax_X+70);

        }
        if (number_X < rangeMin_X)
        {
            rangeMin_X = number_X;
            axisY_forChart_X->setMin(rangeMin_X-70);

        }
    }
    if( (number_X >= 2000 && number_X < 5000) || (number_X <= -2000 && number_X > -5000) )
    {

        if (number_X > rangeMax_X)
        {
            rangeMax_X = number_X;
            axisY_forChart_X->setMax(rangeMax_X+100);

        }
        if (number_X < rangeMin_X)
        {
            rangeMin_X = number_X;
            axisY_forChart_X->setMin(rangeMin_X-100);

        }
    }
}

void Charts::drawAxis_Y()
{
    if( (number_Y >= 0 && number_Y < 1000) || (number_Y <= 0 && number_Y > -1000) )
    {
        if (number_Y > rangeMax_Y)
        {
            axisY_forChart_Y->setMax(number_Y+30);
            rangeMax_Y = number_Y;
        }
        if (number_Y < rangeMin_Y)
        {
            axisY_forChart_Y->setMin(number_Y-30);
            rangeMin_Y = number_Y;
        }
    }
    if ( (number_Y >= 1000 && number_Y < 2000) || (number_Y <= -1000 && number_Y > -2000) )
    {
        if (number_Y > rangeMax_Y)
        {
            axisY_forChart_Y->setMax(number_Y+70);
            rangeMax_Y = number_Y;
        }
        if (number_Y < rangeMin_Y)
        {
            axisY_forChart_Y->setMin(number_Y-70);
            rangeMin_Y = number_Y;
        }
    }
    if( (number_Y >= 2000 && number_Y < 5000) || (number_Y <= -2000 && number_Y > -5000) )
    {
        if (number_Y > rangeMax_Y)
        {
            axisY_forChart_Y->setMax(number_Y+100);
            rangeMax_Y = number_Y;
        }
        if (number_Y < rangeMin_Y)
        {
            axisY_forChart_Y->setMin(number_Y-100);
            rangeMin_Y = number_Y;
        }
    }
}
