#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::wheelEvent(QWheelEvent *event)
{
    int delta = event->angleDelta().y();

    if(ui->graphicsView_X->underMouse())
    {
        if (delta > 0) { chart_X->zoomIn(); }
        else { chart_X->zoomOut(); }

        event->accept();
    }

    if(ui->graphicsView_Y->underMouse())
    {
        if (delta > 0) { chart_Y->zoomIn(); }
        else { chart_Y->zoomOut(); }

        event->accept();
    }


    if(ui->graphicsView_XY0->underMouse())
    {
        if (delta > 0) { chart_XY0->zoomIn(); }
        else { chart_XY0->zoomOut(); }

        event->accept();
    }

    if(ui->graphicsView_XY->underMouse())
    {
        if (delta > 0) { chart_XY->zoomIn(); }
        else { chart_XY->zoomOut(); }

        event->accept();
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(ui->graphicsView_X->underMouse())
    {
        switch (event->key())
        {
        case Qt::Key_Plus:
            chart_X->zoomIn();
            break;
        case Qt::Key_Minus:
            chart_X->zoomOut();
            break;
        case Qt::Key_4:
            chart_X->scroll(-10,0);
            break;
        case Qt::Key_6:
            chart_X->scroll(10,0);
            break;
        case Qt::Key_8:
            chart_X->scroll(0,10);
            break;
        case Qt::Key_2:
            chart_X->scroll(0,-10);
            break;
        case Qt::Key_5:
            chart_X->zoomReset();
            break;
        default:
            break;
        }
    }

    if(ui->graphicsView_Y->underMouse())
    {
        switch (event->key())
        {
        case Qt::Key_Plus:
            chart_Y->zoomIn();
            break;
        case Qt::Key_Minus:
            chart_Y->zoomOut();
            break;
        case Qt::Key_4:
            chart_Y->scroll(-10,0);
            break;
        case Qt::Key_6:
            chart_Y->scroll(10,0);
            break;
        case Qt::Key_8:
            chart_Y->scroll(0,10);
            break;
        case Qt::Key_2:
            chart_Y->scroll(0,-10);
            break;
        case Qt::Key_5:
            chart_Y->zoomReset();
            break;
        default:
            break;
        }
    }

    if(ui->graphicsView_XY0->underMouse())
    {
        switch (event->key())
        {
        case Qt::Key_Plus:
            chart_XY0->zoomIn();
            break;
        case Qt::Key_Minus:
            chart_XY0->zoomOut();
            break;
        case Qt::Key_4:
            chart_XY0->scroll(-10,0);
            break;
        case Qt::Key_6:
            chart_XY0->scroll(10,0);
            break;
        case Qt::Key_8:
            chart_XY0->scroll(0,10);
            break;
        case Qt::Key_2:
            chart_XY0->scroll(0,-10);
            break;
        case Qt::Key_5:
            chart_XY0->zoomReset();
            break;
        default:
            break;
        }
    }
}
