#pragma once

#include <QGroupBox>
#include <QLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "promotion.h"
#include "observer.h"

class ViewPieChart : public Observer {
private:
    Promotion* promo;
    QGroupBox* groupBox;

    void update();

public:
    ViewPieChart(Promotion* promo, QGroupBox* groupBox);
};
