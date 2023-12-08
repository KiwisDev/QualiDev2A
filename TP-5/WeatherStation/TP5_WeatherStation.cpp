#include <QtNetwork/QNetworkAccessManager>
#include <QByteArray>

#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>

#include "TP5_WeatherStation.h"
#include "ui_TP5_WeatherStation.h"

#include "weatherreport.h"

#include <iostream>

TP5_WeatherStation::TP5_WeatherStation(DbManager *dbm, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::TP5_WeatherStationClass)
    , weatherReport (new WeatherReport) // Weather Data class
    , dbmanager (dbm)                   // DB Manager, for Pollution Data
    , netmanagerWeather (new QNetworkAccessManager(this))              // NetWork Manager, for http requests
    , netmanagerPollution (new QNetworkAccessManager(this))            // Network Manager, for http requests
{
    ui->setupUi(this);

    // Weather report View
    reportView = new ViewReport(weatherReport,ui);
    // Pollution Forecast View
    pollutionView = new ViewPollution(dbmanager, ui->groupBox_pollution);

    connect(netmanagerWeather, SIGNAL(finished(QNetworkReply*)), this, SLOT(weatherReplyFinished(QNetworkReply*)));
    connect(netmanagerPollution, SIGNAL(finished(QNetworkReply*)), this, SLOT(pollutionReplyFinished(QNetworkReply*)));

    weatherRequest();
    pollutionRequest();

    connect(ui->pushButton_weather_request, &QPushButton::pressed, this, &TP5_WeatherStation::weatherRequest);
    connect(ui->pushButton_weather_request, &QPushButton::pressed, this, &TP5_WeatherStation::pollutionRequest);
}

TP5_WeatherStation::~TP5_WeatherStation() {
    delete ui;
    delete dbmanager;
    if (netmanagerWeather != nullptr)
        netmanagerWeather->deleteLater();
}

void TP5_WeatherStation::weatherRequest() {
    QString stringURL =
        "https://api.openweathermap.org/data/2.5/weather?q=bourg-en-bresse,fr&units=metric&lang=fr&appid=265705b3133eada0132261b3ca61a96f";
    QUrl url(stringURL);

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Accept", "application/json");
    netmanagerWeather->get(request);
}

void TP5_WeatherStation::weatherReplyFinished(QNetworkReply* reply) {
    // -- Manage response -- //
    if(reply->error() != QNetworkReply::NoError) { // Error in reply

    }
    else if(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200) { // Success
        QByteArray datas = reply->readAll();

        QJsonDocument jsonReply = QJsonDocument::fromJson(datas);
        QJsonObject jsonObj = jsonReply.object();

        QJsonObject coordObj = jsonObj["coord"].toObject();
        this->weatherReport->setLat(coordObj["lat"].toDouble());
        this->weatherReport->setLon(coordObj["lon"].toDouble());

        QJsonObject mainObj = jsonObj["main"].toObject();
        this->weatherReport->setTemp(mainObj["temp"].toDouble());
        this->weatherReport->setTempMin(mainObj["temp_min"].toDouble());
        this->weatherReport->setTempMax(mainObj["temp_max"].toDouble());

        QJsonArray weatherArray = jsonObj["weather"].toArray();
        QJsonObject weatherObj = weatherArray[0].toObject();
        this->weatherReport->setDesciption(weatherObj["description"].toString());
    }
    else { // Failed to connect API

    }

    reply->deleteLater();

    this->weatherReport->notifyObserver();
}

void TP5_WeatherStation::pollutionRequest() {
    QString stringURL =
        "https://api.openweathermap.org/data/2.5/air_pollution/forecast?lat=46.0398&lon=5.4133&units=metric&lang=fr&appid=265705b3133eada0132261b3ca61a96f";
    QUrl url(stringURL);

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Accept", "application/json");
    netmanagerPollution->get(request);
}

void TP5_WeatherStation::pollutionReplyFinished(QNetworkReply* reply) {
    // -- Manage response -- //
    if(reply->error() != QNetworkReply::NoError) { // Error in reply

    }
    else if(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200) { // Success
        QByteArray datas = reply->readAll();

        QJsonDocument jsonReply = QJsonDocument::fromJson(datas);
        QJsonObject jsonObj = jsonReply.object();

        QJsonArray list = jsonObj["list"].toArray();
        for(auto l:list) {
            QJsonObject element = l.toObject();
            int aqi = element["main"].toObject()["aqi"].toInt();
            int dt = element["dt"].toInt();

            QDateTime time = QDateTime::fromSecsSinceEpoch(dt);
        }
    }
    else { // Failed to connect API

    }

    reply->deleteLater();
}
