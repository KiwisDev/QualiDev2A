#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include "abstractChartView.h"

class BarChartView : public AbstractChartView {
public:
    BarChartView();
    QWidget* getChartView(Data *data);
};

#endif // BARCHARTVIEW_H
