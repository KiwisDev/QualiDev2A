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
 * @brief WeatherReport class
 * @author FJa
 */
class WeatherReport : public Observable {
private:
    QString main,description; //> text report
    double temp,temp_min,temp_max; //> temperatures
    double lon,lat; //> localisation
    QString iconCode; //> icon code

    QVector<Observer*> observerList;
public:
    /**
     * @brief Constructor
     *
     * Constructor sets up all the data to 0.0
     */
    WeatherReport();

    /**
     * @brief Return the description of the current weather
     */
    const QString& getDescription() const {return description;}

    /**
     * @brief Return the temperature of the current weather
     */
    double getTemp() const {return temp;}

    /**
     * @brief Return the minimal temperature of the current weather
     */
    double getTempMin() const {return temp_min;}

    /**
     * @brief Return the maximal emperature of the current weather
     */
    double getTempMax() const {return temp_max;}

    /**
     * @brief Return the longitude of the current weather
     */
    double getLon() const {return lon;}

    /**
     * @brief Return the latitude of the current weather
     */
    double getLat() const {return lat;}

    /**
     * @brief Return the icon code of the current weather
     */
    const QString& getIconCode() const {return iconCode;}

    /**
     * @brief Set the description for the current weather
     * @param desc - description to set
     */
    void setDesciption(const QString& desc) {description = desc;}

    /**
     * @brief Set the temperature for the current weather
     * @param t - temperature to set
     */
    void setTemp(double t) {temp = t;}

    /**
     * @brief Set the minimal temperature for the current weather
     * @param t - minimal temperature to set
     */
    void setTempMin(double t) {temp_min = t;}

    /**
     * @brief Set the maximal temperature for the current weather
     * @param t - maximal temperature to set
     */
    void setTempMax(double t) {temp_max = t;}

    /**
     * @brief Set the longitude for the current weather
     * @param l - longitude to set
     */
    void setLon(double l) {lon = l;}

    /**
     * @brief Set the latitude for the current weather
     * @param l - latitude to set
     */
    void setLat(double l) {lat = l;}

    /**
     * @brief Set the icon code for the current weather
     * @param code - icon code to set
     */
    void setIconCode(const QString& code) {iconCode = code;}

    /**
     * @brief Add observer to the observer list
     * @param observer - observer object to add
     */
    void addObserver(Observer* observer) override;

    /**
     * @brief Remove observer to the observer list
     * @param observer - observer to remove from the list
     */
    void removeObserver(Observer* observer) override;

    /**
     * @brief Call the 'update' function of all the observers of the list
     */
    void notifyObserver() const override;
};

#endif // WEATHERREPORT_H
