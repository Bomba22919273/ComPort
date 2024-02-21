#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charts.h"
#include "ui_charts.h"


void Charts::wheelEvent(QWheelEvent *event)
{
    int delta = event->angleDelta().y();

    if(ui->graphicsViewGravity->underMouse())
    {
        if (delta > 0) { chartGravity->zoomIn(); }
        else { chartGravity->zoomOut(); }

        event->accept();
    }

    if(ui->graphicsViewSpringTemp->underMouse())
    {
        if (delta > 0) { chartSpringTemp->zoomIn(); }
        else { chartSpringTemp->zoomOut(); }

        event->accept();
    }

//    if(ui->graphicsView_XY->underMouse())
//    {
//        if (delta > 0) { chart_XY->zoomIn(); }
//        else { chart_XY->zoomOut(); }

//        event->accept();
//    }

}

void Charts::keyPressEvent(QKeyEvent *event)
{
    if(ui->graphicsViewGravity->underMouse())
    {
        switch (event->key())
        {
        case Qt::Key_Plus:
            chartGravity->zoomIn();
            break;
        case Qt::Key_Minus:
            chartGravity->zoomOut();
            break;
        case Qt::Key_4:
            chartGravity->scroll(-10,0);
            break;
        case Qt::Key_6:
            chartGravity->scroll(10,0);
            break;
        case Qt::Key_8:
            chartGravity->scroll(0,10);
            break;
        case Qt::Key_2:
            chartGravity->scroll(0,-10);
            break;
        case Qt::Key_5:
            chartGravity->zoomReset();
            break;
        default:
            break;
        }
    }

    if(ui->graphicsViewSpringTemp->underMouse())
    {
        switch (event->key())
        {
        case Qt::Key_Plus:
            chartSpringTemp->zoomIn();
            break;
        case Qt::Key_Minus:
            chartSpringTemp->zoomOut();
            break;
        case Qt::Key_4:
            chartSpringTemp->scroll(-10,0);
            break;
        case Qt::Key_6:
            chartSpringTemp->scroll(10,0);
            break;
        case Qt::Key_8:
            chartSpringTemp->scroll(0,10);
            break;
        case Qt::Key_2:
            chartSpringTemp->scroll(0,-10);
            break;
        case Qt::Key_5:
            chartSpringTemp->zoomReset();
            break;
        default:
            break;
        }
    }


}
