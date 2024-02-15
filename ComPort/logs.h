#ifndef LOGS_H
#define LOGS_H

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
#include <QComboBox>
#include <QStringList>


namespace Ui {
class Logs;
}

class Logs : public QWidget
{
    Q_OBJECT

public:
    explicit Logs(QWidget *parent = nullptr);
    ~Logs();
    QSerialPort serialPortLogs;


private slots:
    void selectedBaudRate();

public slots:
    void logsIsOpen(QString data);
    void on_ClearButton_clicked();
    void on_DisconnectButton_clicked();
    void on_StopButton_clicked();
private:
    Ui::Logs *ui;




    QString jsonString;
    QString buffer;

};

#endif // LOGS_H
