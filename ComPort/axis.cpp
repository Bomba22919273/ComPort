#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charts.h"
#include "ui_charts.h"

void Charts::updateAxis(int number_X, int number_Y)
{
    rangeMin_X = number_X ;
    rangeMax_X = number_X ;
    rangeMin_Y = number_Y;
    rangeMax_Y = number_Y;
}

void MainWindow::clearAxis( )
{
    initDrawChartDataInc();
    seriesDataInc->append(number_X,number_Y);

}

void Charts::displayAxisSpringTemp()
{
    QPen penY_X(Qt::darkBlue,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chartGravity = new QChart();
    seriesGravity = new QSplineSeries;
    axisX_Gravity = new QDateTimeAxis();
    axisY_Gravity = new QValueAxis();

    chartGravity->legend()->hide();
    chartGravity->addSeries(seriesGravity);
    axisX_Gravity->setTickCount(10);
    axisY_Gravity->setTickCount(10);
    axisX_Gravity->setFormat("hh:mm:ss");
    axisY_Gravity->setRange(0,4);


    axisY_Gravity->setLinePenColor(QColor(Qt::darkBlue));
    axisY_Gravity->setGridLineColor(QColor(Qt::darkBlue));
    axisY_Gravity->setGridLineVisible(false);
    axisY_Gravity->setLinePen(penY_X);
    axisX_Gravity->setLinePen(penY_X);

    chartGravity->addAxis(axisX_Gravity,Qt::AlignBottom);
    chartGravity->addAxis(axisY_Gravity,Qt::AlignLeft);

    seriesGravity->attachAxis(axisX_Gravity);
    seriesGravity->attachAxis(axisY_Gravity);

    axisY_Gravity->setTitleText("Spring Temperature");


    ui->graphicsViewGravity->setChart(chartGravity);
    ui->graphicsViewGravity->setRenderHint(QPainter::Antialiasing);


}

void Charts::displayAxisGravity()
{
    QPen penY_Y(Qt::darkRed,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chartSpringTemp = new QChart();
    seriesSpringTemp = new QSplineSeries;
    axisX_SpringTemp = new QDateTimeAxis();
    axisY_SpingTemp = new QValueAxis();
    chartSpringTemp->legend()->hide();
    chartSpringTemp->addSeries(seriesSpringTemp);
    axisX_SpringTemp->setTickCount(10);
    axisY_SpingTemp->setTickCount(10);
    axisX_SpringTemp->setFormat("hh:mm:ss");
    axisY_SpingTemp->setRange(0,4);


    axisY_SpingTemp->setLinePenColor(QColor(Qt::darkRed));
    axisY_SpingTemp->setGridLineColor(QColor(Qt::darkRed));
    axisY_SpingTemp->setGridLineVisible(false);
    axisY_SpingTemp->setLinePen(penY_Y);
    axisX_SpringTemp->setLinePen(penY_Y);

    chartSpringTemp->addAxis(axisX_SpringTemp, Qt::AlignBottom);
    chartSpringTemp->addAxis(axisY_SpingTemp, Qt::AlignLeft);


    seriesSpringTemp->attachAxis(axisX_SpringTemp);
    seriesSpringTemp->attachAxis(axisY_SpingTemp);

    axisY_SpingTemp->setTitleText("Gravity");

    // Отображаем график в окне
    ui->graphicsViewSpringTemp->setChart(chartSpringTemp);
    ui->graphicsViewSpringTemp->setRenderHint(QPainter::Antialiasing);


}

void MainWindow::initDrawChartDataInc()
{
    QPen penXY(Qt::darkGreen, 3, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chartDataInc = new QChart();
    seriesDataInc = new QScatterSeries();
    axisX_DataInc = new QValueAxis();
    axisY_DataInc = new QValueAxis();
    chartDataInc->legend()->hide();
    chartDataInc->addSeries(seriesDataInc);

    axisX_DataInc->setGridLineVisible(true);
    axisX_DataInc->setLinePen(penXY);
    axisX_DataInc->setGridLineColor(QColor(Qt::black));
    axisX_DataInc->setLinePenColor(QColor(Qt::black));
    axisX_DataInc->setTickCount(10);
    axisX_DataInc->setTitleText("Inclinometr X");

    axisY_DataInc->setLinePen(penXY);
    axisY_DataInc->setLinePenColor(QColor(Qt::black));
    axisY_DataInc->setGridLineColor(QColor(Qt::black));
    axisY_DataInc->setTickCount(10);
    axisY_DataInc->setTitleText("Inclinometr Y");

    chartDataInc->createDefaultAxes();
    chartDataInc->axes(Qt::Horizontal).back()->setRange(-2500,2500);
    chartDataInc->axes(Qt::Vertical).back()->setRange(-2500,2500);


    seriesDataInc->attachAxis(axisX_DataInc);
    seriesDataInc->attachAxis(axisY_DataInc);

    ui->graphicsViewDataInc->setChart(chartDataInc);



}


void Charts::scalingAxisSpringTemp(int number_X)
{
    if( (number_X >= 0 && number_X < 1000) || (number_X <= 0 && number_X > -1000) )
    {
        if (number_X > rangeMax_X)
        {
            rangeMax_X = number_X;
            axisY_Gravity->setMax(rangeMax_X+40);

        }
        if (number_X < rangeMin_X)
        {
            rangeMin_X = number_X;
            axisY_Gravity->setMin(rangeMin_X-40);

        }
    }

    if ( (number_X >= 1000 && number_X < 2000) || (number_X <= -1000 && number_X > -2000) )
    {
        if (number_X > rangeMax_X)
        {
            rangeMax_X = number_X;
            axisY_Gravity->setMax(rangeMax_X+70);

        }
        if (number_X < rangeMin_X)
        {
            rangeMin_X = number_X;
            axisY_Gravity->setMin(rangeMin_X-70);

        }
    }
    if( (number_X >= 2000 && number_X < 5000) || (number_X <= -2000 && number_X > -5000) )
    {

        if (number_X > rangeMax_X)
        {
            rangeMax_X = number_X;
            axisY_Gravity->setMax(rangeMax_X+100);

        }
        if (number_X < rangeMin_X)
        {
            rangeMin_X = number_X;
            axisY_Gravity->setMin(rangeMin_X-100);

        }
    }
}

void Charts::scalingAxisGravity(int number_Y)
{
    if( (number_Y >= 0 && number_Y < 1000) || (number_Y <= 0 && number_Y > -1000) )
    {
        if (number_Y > rangeMax_Y)
        {
            axisY_SpingTemp->setMax(number_Y+30);
            rangeMax_Y = number_Y;
        }
        if (number_Y < rangeMin_Y)
        {
            axisY_SpingTemp->setMin(number_Y-30);
            rangeMin_Y = number_Y;
        }
    }
    if ( (number_Y >= 1000 && number_Y < 2000) || (number_Y <= -1000 && number_Y > -2000) )
    {
        if (number_Y > rangeMax_Y)
        {
            axisY_SpingTemp->setMax(number_Y+70);
            rangeMax_Y = number_Y;
        }
        if (number_Y < rangeMin_Y)
        {
            axisY_SpingTemp->setMin(number_Y-70);
            rangeMin_Y = number_Y;
        }
    }
    if( (number_Y >= 2000 && number_Y < 5000) || (number_Y <= -2000 && number_Y > -5000) )
    {
        if (number_Y > rangeMax_Y)
        {
            axisY_SpingTemp->setMax(number_Y+100);
            rangeMax_Y = number_Y;
        }
        if (number_Y < rangeMin_Y)
        {
            axisY_SpingTemp->setMin(number_Y-100);
            rangeMin_Y = number_Y;
        }
    }
}
