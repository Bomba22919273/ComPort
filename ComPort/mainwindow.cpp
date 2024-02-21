#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->lcdNumber->setDigitCount(19);

    charts = new Charts;
    connect(this, &MainWindow::openCharts, charts, &Charts::chartsIsOpen );
    connect(this, &MainWindow::drawChartGravity, charts, &Charts::dataChartGravity);


    logs = new Logs;
    connect(this, &MainWindow::openLogs, logs, &Logs::showLogs );
    //connect(this, &MainWindow::connectSerialPort, logs, &Logs::settingsSerialPort);
    connect(this, &MainWindow::dataChartSpringTemp, charts, &Charts::dataChartSpringTemp);

    tmr = new QTimer(this);
    tmr->start();
    tmr->setInterval(200);

    connect(tmr,SIGNAL(timeout()), this, SLOT(updateDateTime()));



    tmrAxis = new QTimer(this);
    tmrAxis -> setInterval(5000);
    connect(tmrAxis, SIGNAL(timeout()), this, SLOT(clearAxis()));
    tmrAxis ->start();

    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox_CP->addItems(stringPorts);


    initDrawChartDataInc();

}

void MainWindow::receiveMessage()
{


//JSON_______________________________________________________________________________

    QByteArray data;


    data.append(serialPort.readAll());
    if (data.contains("\n")) {
        QString receivedData(data);
        receivedData.remove('\r');
        QStringList jsonStrings = receivedData.split('\n');
        foreach (jsonString, jsonStrings) {
            QByteArray jsonData = jsonString.toUtf8();
            QJsonParseError error;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);
            QJsonObject jsonObject = jsonDoc.object();

            if (error.error == QJsonParseError::NoError) {

                jsonString = QString::fromUtf8(jsonDoc.toJson(QJsonDocument::Compact));
                ui->textBrowser->append(jsonString);

                emit openLogs(jsonString);
}


            QJsonValue inclinometerXValue = jsonObject.value("inclinometerX");
            if (inclinometerXValue.isDouble()) {
                double inclinometerX = inclinometerXValue.toDouble();
                QString x_s = QString::number(inclinometerX);
                ui->textBrowser_X->setText(x_s);
                number_X= x_s.toInt();

            }

            QJsonValue inclinometerYValue = jsonObject.value("inclinometerY");
            if (inclinometerYValue.isDouble()) {
                double inclinometerY = inclinometerYValue.toDouble();
                QString y_s = QString::number(inclinometerY);
                ui->textBrowser_Y->setText(y_s);
                number_Y= y_s.toInt();
            }

            QJsonValue SpringTemperatureValue = jsonObject.value("springTemperature");
            if (SpringTemperatureValue.isDouble()) {
                double SpringTemperature = SpringTemperatureValue.toDouble();
                QString st_s = QString::number(SpringTemperature);
                ui->textBrowser_ST->setText(st_s);

                //emit dataChartSpringTemp(st_s);



            }


            QJsonValue GravityValue = jsonObject.value("gravity");
            if ( GravityValue.isDouble()) {
                double  Gravity = GravityValue.toDouble();
                QString grav_s = QString::number( Gravity);
                ui->textBrowser_Gravity->setText(grav_s);

                //emit drawChartGravity(grav_s);

            }
        }

       ui->textBrowser->append("\n");
       data.clear();
  }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_openLogsButton_clicked()
{
    logs->show();
}

void MainWindow::on_openChartsButton_clicked()
{
    charts->show();

    emit openCharts();
}
