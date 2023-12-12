#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TP5_WeatherStation.h"
#include "weatherreport.h"
#include "dbmanager.h"
#include "viewreport.h"
#include "viewpollution.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QInputDialog>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class TP5_WeatherStationClass; }
QT_END_NAMESPACE

/**
 * @brief TP5_WeatherStation class
 * @author Fja
 */
class TP5_WeatherStation : public QMainWindow {
    Q_OBJECT

public:
    TP5_WeatherStation(DbManager *dbm, QWidget* parent = nullptr);
    ~TP5_WeatherStation();

private:
    Ui::TP5_WeatherStationClass* ui;

    double lon, lat;
    QPixmap icon;

    WeatherReport* weatherReport;
    DbManager* dbmanager;
    QNetworkAccessManager* netmanagerWeather;
    QNetworkAccessManager* netmanagerPollution;
    QNetworkAccessManager* netmanagerLocation;
    QNetworkAccessManager* netmanagerIcon;

    ViewReport *reportView;
    ViewPollution *pollutionView;

public slots:
    /**
     * @brief Send a request to the weather OpenWeatherMap API to get the current weather
     */
    void weatherRequest();

    /**
     * @brief Process recived data from the weather API and update model
     * @param reply - recived data from the API
     */
    void weatherReplyFinished(QNetworkReply* reply);

    /**
     * @brief Send a request to OpenWeatherMap to get the current weather icon
     */
    void iconRequest();

    /**
     * @brief Process recived data from OpenWeatherMap to display it on screen
     * @param reply - recived data from the OpenWeatherMAp
     */
    void iconReplyFinished(QNetworkReply* reply);

    /**
     * @brief Send a request to the pollution OpenWeatherMap API to get the pollution data
     */
    void pollutionRequest();

    /**
     * @brief Process recived data from the pollution OpenWeatherMap API and update model
     * @param reply - recived data frol the API
     */
    void pollutionReplyFinished(QNetworkReply* reply);

    /**
     * @brief Send a request to the Geocoding API to get the GPS values of a city
     */
    void locationRequest();

    /**
     * @brief Process recived data from the Geocoding API and update models
     * @param reply
     */
    void locationReplyFinished(QNetworkReply* reply);
};
