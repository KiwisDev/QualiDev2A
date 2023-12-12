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
    , netmanagerLocation (new QNetworkAccessManager(this))             // Network Manager, for http requests
    , netmanagerIcon (new QNetworkAccessManager(this))                 // Network Manager, for http requests
{
    ui->setupUi(this);

    this->lon = 5.4133;
    this->lat = 46.0398;
    this->icon;

    // Weather report View
    reportView = new ViewReport(weatherReport,ui);
    // Pollution Forecast View
    pollutionView = new ViewPollution(dbmanager, ui->groupBox_pollution);

    if(this->dbmanager->isOpen()) {
        this->dbmanager->createTable();
    }
    else {
        qDebug() << "DB is not opened at table creation time";
    }

    connect(netmanagerWeather, SIGNAL(finished(QNetworkReply*)), this, SLOT(weatherReplyFinished(QNetworkReply*)));
    connect(netmanagerPollution, SIGNAL(finished(QNetworkReply*)), this, SLOT(pollutionReplyFinished(QNetworkReply*)));
    connect(netmanagerLocation, SIGNAL(finished(QNetworkReply*)), this, SLOT(locationReplyFinished(QNetworkReply*)));
    connect(netmanagerIcon, SIGNAL(finished(QNetworkReply*)), this, SLOT(iconReplyFinished(QNetworkReply*)));

    weatherRequest();
    pollutionRequest();

    connect(ui->pushButton_weather_request, &QPushButton::pressed, this, &TP5_WeatherStation::weatherRequest);
    connect(ui->pushButton_weather_request, &QPushButton::pressed, this, &TP5_WeatherStation::pollutionRequest);
    connect(ui->actionChanger_ville, &QAction::triggered, this, &TP5_WeatherStation::locationRequest);
}

TP5_WeatherStation::~TP5_WeatherStation() {
    delete ui;
    delete dbmanager;
    if (netmanagerWeather != nullptr)
        netmanagerWeather->deleteLater();
}

void TP5_WeatherStation::weatherRequest() {
    QString stringURL =
        "https://api.openweathermap.org/data/2.5/weather?lat=" + QString::number(this->lat) + "&lon=" + QString::number(this->lon) + "&units=metric&lang=fr&appid=265705b3133eada0132261b3ca61a96f";
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
        this->weatherReport->setIconCode(weatherObj["icon"].toString());
    }
    else { // Failed to connect API

    }

    reply->deleteLater();

    iconRequest();

    this->weatherReport->notifyObserver();
}

void TP5_WeatherStation::iconRequest() {
    QString stringURL =
        "https://openweathermap.org/img/wn/" + this->weatherReport->getIconCode() + "@2x.png";
    QUrl url(stringURL);

    QNetworkRequest request;
    request.setUrl(url);
    netmanagerIcon->get(request);
}

void TP5_WeatherStation::iconReplyFinished(QNetworkReply *reply) {
    // -- Manage response -- //
    if(reply->error() != QNetworkReply::NoError) { // Error in reply

    }
    else if(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200) { // Success
        icon.loadFromData(reply->readAll());
        ui->label_8->setPixmap(this->icon);
        ui->label_8->setScaledContents(true);
        ui->label_8->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    }
    else { // Failed to connect API

    }

    reply->deleteLater();
}

void TP5_WeatherStation::pollutionRequest() {
    QString stringURL =
        "https://api.openweathermap.org/data/2.5/air_pollution/forecast?lat=" + QString::number(this->lat) + "&lon=" + QString::number(this->lon) + "&units=metric&lang=fr&appid=265705b3133eada0132261b3ca61a96f";
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
        if(this->dbmanager->isOpen()) {
            this->dbmanager->removeAllData();
            for(auto l:list) {
                QJsonObject element = l.toObject();
                int aqi = element["main"].toObject()["aqi"].toInt();
                int dt = element["dt"].toInt();

                this->dbmanager->addData(dt, aqi);

                QDateTime time = QDateTime::fromSecsSinceEpoch(dt);
            }
        }
        else {
            qDebug() << "DB is not open at insertion time";
        }
    }
    else { // Failed to connect API

    }

    reply->deleteLater();

    this->dbmanager->notifyObserver();
}

void TP5_WeatherStation::locationRequest() {
    bool ok;
    QString city = QInputDialog::getText(this, "Changer la localisation", "Ville :", QLineEdit::Normal, "", &ok);

    if(ok && !city.isEmpty()) {
        QString stringURL =
            "http://api.openweathermap.org/geo/1.0/direct?q=" + city +"&limit=5&appid=265705b3133eada0132261b3ca61a96f";
        QUrl url(stringURL);

        QNetworkRequest request;
        request.setUrl(url);
        request.setRawHeader("Accept", "application/json");
        netmanagerLocation->get(request);
    }
}

void TP5_WeatherStation::locationReplyFinished(QNetworkReply *reply) {
    // -- Manage response -- //
    if(reply->error() != QNetworkReply::NoError) { // Error in reply

    }
    else if(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200) { // Success
        QByteArray datas = reply->readAll();

        QJsonDocument jsonReply = QJsonDocument::fromJson(datas);
        QJsonArray jsonArray = jsonReply.array();

        QJsonObject jsonObj = jsonArray[0].toObject();
        this->lat = jsonObj["lat"].toDouble();
        this->lon = jsonObj["lon"].toDouble();
    }
    else { // Failed to connect API

    }

    reply->deleteLater();

    this->weatherRequest();
    this->pollutionRequest();
}
