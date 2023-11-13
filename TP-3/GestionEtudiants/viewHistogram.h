#pragma once

#include <QGroupBox>
#include <QLayout>
#include <QStringList>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include "promotion.h"
#include "observer.h"

class ViewHistogram : public Observer {
private:
    Promotion* promo;
    QGroupBox* groupBox;

    void update();

public:
    ViewHistogram(Promotion* promo, QGroupBox* groupBox);
};

