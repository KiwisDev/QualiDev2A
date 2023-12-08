#include "weatherreport.h"
#include <QDateTime>
#include <QTimeZone>

WeatherReport::WeatherReport()
    : temp(0.0),temp_min(0.0),temp_max(0.0),
      lon(0.0),lat(0.0)
{ }

void WeatherReport::addObserver(Observer *observer) {
    this->observerList.push_back(observer);
}

void WeatherReport::removeObserver(Observer *observer) {
    this->observerList.removeOne(observer);
}

void WeatherReport::notifyObserver() const {
    for(int i=0; i<this->observerList.size(); i++) {
        this->observerList[i]->update();
    }
}
