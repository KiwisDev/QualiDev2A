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
    /**
     * @brief BarChartView, constructor of the class
     */
    BarChartView();

    /**
     * @brief getChartView, generate the bar chart and his widget
     * @param data, data used to generates charts
     * @return widget containing charts
     */
    QWidget* getChartView(Data *data);
};

#endif // BARCHARTVIEW_H
