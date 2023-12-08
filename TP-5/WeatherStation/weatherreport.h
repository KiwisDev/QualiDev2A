#ifndef WEATHERREPORT_H
#define WEATHERREPORT_H

#include <QDebug>

#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <QString>
#include <QVector>

#include "observer.h"

/**
 * @brief The WeatherReport class
 * @author FJa
 */
class WeatherReport : public Observable {
private:
    QString main,description; //> text report
    double temp,temp_min,temp_max; //> temperatures
    double lon,lat; //> localisation

    QVector<Observer*> observerList;
public:
    WeatherReport();

    // getters
    const QString& getDescription() const {return description;}
    double getTemp() const {return temp;}
    double getTempMin() const {return temp_min;}
    double getTempMax() const {return temp_max;}
    double getLon() const {return lon;}
    double getLat() const {return lat;}

    void setDesciption(const QString& desc) {description = desc;}
    void setTemp(double t) {temp = t;}
    void setTempMin(double t) {temp_min = t;}
    void setTempMax(double t) {temp_max = t;}
    void setLon(double l) {lon = l;}
    void setLat(double l) {lat = l;}

    void addObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObserver() const override;
};

#endif // WEATHERREPORT_H
