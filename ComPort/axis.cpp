#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::clearAxis()
{
    rangeMin_X = number_X ;
    rangeMax_X = number_X ;
    rangeMin_Y = number_Y;
    rangeMax_Y = number_Y;
}

void MainWindow::initDraw_X()
{
    QPen penY_X(Qt::darkBlue,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_X = new QChart();
    series_X = new QSplineSeries;
    axisX_forChart_X = new QDateTimeAxis();
    axisY_forChart_X = new QValueAxis();

    chart_X->legend()->hide();                             // Скрываем легенду
    chart_X->addSeries(series_X);                            // Добавляем линию на график
    axisX_forChart_X->setTickCount(10);                             // Устанавливаем количество осей
    axisY_forChart_X->setTickCount(10);
    axisX_forChart_X->setFormat("hh:mm:ss");


    axisY_forChart_X->setLinePenColor(QColor(Qt::darkBlue));        // Устанавливаем цветовой стиль оси
    axisY_forChart_X->setGridLineColor(QColor(Qt::darkBlue));
    axisY_forChart_X->setGridLineVisible(false);                    // Устанавливаем сетку оси Y не отображать
    axisY_forChart_X->setLinePen(penY_X);
    axisX_forChart_X->setLinePen(penY_X);

    chart_X->addAxis(axisX_forChart_X,Qt::AlignBottom);               // Устанавливаем положение оси координат на графике
    chart_X->addAxis(axisY_forChart_X,Qt::AlignLeft);

    series_X->attachAxis(axisX_forChart_X);                           // Добавляем данные на ось
    series_X->attachAxis(axisY_forChart_X);

    axisY_forChart_X->setTitleText("X");

    // Отображаем график в окне
    ui->graphicsView_X->setChart(chart_X);
    ui->graphicsView_X->setRenderHint(QPainter::Antialiasing);   // Устанавливаем сглаживание


}

void MainWindow::clear_XY()
{
    initDraw_XY();
    series_XY->append(number_X,number_Y);

}
void MainWindow::initDraw_XY()
{
    QPen penXY(Qt::darkGreen, 3, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_XY = new QChart();
    series_XY = new QScatterSeries();
    axisX_forChart_XY = new QValueAxis();
    axisY_forChart_XY = new QValueAxis();

    chart_XY->legend()->hide();
    chart_XY->addSeries(series_XY);
    axisX_forChart_XY->setLinePenColor(QColor(Qt::black));        // Устанавливаем цветовой стиль оси
    axisX_forChart_XY->setGridLineColor(QColor(Qt::black));
    axisY_forChart_XY->setLinePenColor(QColor(Qt::black));        // Устанавливаем цветовой стиль оси
    axisY_forChart_XY->setGridLineColor(QColor(Qt::black));

    axisX_forChart_XY->setGridLineVisible(false);                    // Устанавливаем сетку оси Y не отображать
    axisX_forChart_XY->setLinePen(penXY);
    axisY_forChart_XY->setLinePen(penXY);
    axisY_forChart_XY->setTickCount(10);
    axisX_forChart_XY->setTickCount(10);
    chart_XY->createDefaultAxes();
    chart_XY->axes(Qt::Horizontal).back()->setRange(-3000,3000);
    chart_XY->axes(Qt::Vertical).back()->setRange(-3000,3000);


    series_XY->attachAxis(axisX_forChart_XY);                           // Добавляем данные на ось
    series_XY->attachAxis(axisY_forChart_XY);

    ui->graphicsView_XY->setChart(chart_XY);

   // series_XY->append(number)

}
void MainWindow::initDraw_Y()
{
    QPen penY_Y(Qt::darkRed,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_Y = new QChart();
    series_Y = new QSplineSeries;
    axisX_forChart_Y = new QDateTimeAxis();
    axisY_forChart_Y = new QValueAxis();
    chart_Y->legend()->hide();                             // Скрываем легенду
    chart_Y->addSeries(series_Y);                            // Добавляем линию на график
    axisX_forChart_Y->setTickCount(10);                             // Устанавливаем количество осей
    axisY_forChart_Y->setTickCount(10);
    axisX_forChart_Y->setFormat("hh:mm:ss");                        // Устанавливаем формат отображения времени

    axisY_forChart_Y->setLinePenColor(QColor(Qt::darkRed));        // Устанавливаем цветовой стиль оси
    axisY_forChart_Y->setGridLineColor(QColor(Qt::darkRed));
    axisY_forChart_Y->setGridLineVisible(false);                    // Устанавливаем сетку оси Y не отображать
    axisY_forChart_Y->setLinePen(penY_Y);
    axisX_forChart_Y->setLinePen(penY_Y);

    chart_Y->addAxis(axisX_forChart_Y, Qt::AlignBottom);               // Устанавливаем положение оси координат на графике
    chart_Y->addAxis(axisY_forChart_Y, Qt::AlignLeft);


    series_Y->attachAxis(axisX_forChart_Y);                           // Добавляем данные на ось
    series_Y->attachAxis(axisY_forChart_Y);

    axisY_forChart_Y->setTitleText("Y");

    // Отображаем график в окне
    ui->graphicsView_Y->setChart(chart_Y);
    ui->graphicsView_Y->setRenderHint(QPainter::Antialiasing);   // Устанавливаем сглаживание


}

void MainWindow::initDraw_XY0()
{
    QPen penXY0(Qt::black, 3, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    chart_XY0 = new QChart();
    series_X0Y0 = new QScatterSeries();
    axisX_forChart_XY0 = new QValueAxis();
    axisY_forChart_XY0 = new QValueAxis();

    chart_XY0->legend()->hide();
    chart_XY0->addSeries(series_X0Y0);
    axisX_forChart_XY0->setLinePenColor(QColor(Qt::black));        // Устанавливаем цветовой стиль оси
    axisX_forChart_XY0->setGridLineColor(QColor(Qt::black));
    axisY_forChart_XY0->setLinePenColor(QColor(Qt::black));        // Устанавливаем цветовой стиль оси
    axisY_forChart_XY0->setGridLineColor(QColor(Qt::black));


    axisX_forChart_XY0->setLinePen(penXY0);
    axisY_forChart_XY0->setLinePen(penXY0);
    axisY_forChart_XY0->setTickCount(5);
    axisX_forChart_XY0->setTickCount(5);


    chart_XY0->addAxis(axisX_forChart_XY0, Qt::AlignBottom);
    chart_XY0->addAxis(axisY_forChart_XY0, Qt::AlignLeft);


    series_X0Y0->attachAxis(axisX_forChart_XY0);                           // Добавляем данные на ось
    series_X0Y0->attachAxis(axisY_forChart_XY0);

    ui->graphicsView_XY0->setChart(chart_XY0);


}
void MainWindow::draw_axis_XY0()
{

    if( (number_X0 >= 0 && number_X0 < 1000) || (number_X0 <= 0 && number_X0 > -1000) )
    {
        if (number_X0 > rangeMax_X0 || number_Y0 >rangeMax_Y0)
        {
            rangeMax_X0 = number_X0;
            axisX_forChart_XY0->setMax(rangeMax_X0 + 40);
            rangeMax_Y0 = number_Y0;
            axisY_forChart_XY0->setMax(rangeMax_Y0 + 40);

        }

        if (number_X0 < rangeMin_X0 || number_Y0 < rangeMin_Y0)
        {
            rangeMin_X0 = number_X0;
            axisX_forChart_XY0->setMin(rangeMin_X0 - 40);
            rangeMin_Y0 = number_Y0;
            axisY_forChart_XY0->setMin(rangeMin_Y0 - 40);

        }
    }

    if ( (number_X0 >= 1000 && number_X0 < 2000) || (number_X0 <= -1000 && number_X0 > -2000) )
    {
        if (number_X0 > rangeMax_X0 || number_Y0 >rangeMax_Y0)
        {
            rangeMax_X0 = number_X0;
            axisX_forChart_XY0->setMax(rangeMax_X0 + 70);
            rangeMax_Y0 = number_Y0;
            axisY_forChart_XY0->setMax(rangeMax_Y0 + 70);
        }

        if (number_X0 < rangeMin_X0)
        {
            rangeMin_X0 = number_X0;
            axisX_forChart_XY0->setMin(rangeMin_X0 - 70);

        }
    }
    if( (number_X0 >= 2000 && number_X0 < 5000) || (number_X0 <= -2000 && number_X0 > -5000) )
    {

        if (number_X0 > rangeMax_X0|| number_Y0 >rangeMax_Y0)
        {
            rangeMax_X0 = number_X0;
            axisX_forChart_XY0->setMax(rangeMax_X0 + 100);
            rangeMax_Y0 = number_Y0;
            axisY_forChart_XY0->setMax(rangeMax_Y0 + 100);

        }

        if (number_X0 < rangeMin_X0)
        {
            rangeMin_X0 = number_X0;
            axisX_forChart_XY0->setMin(rangeMin_X0 - 100);

        }
    }
}

void MainWindow::draw_axis_X()
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

void MainWindow::draw_axis_Y()
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
