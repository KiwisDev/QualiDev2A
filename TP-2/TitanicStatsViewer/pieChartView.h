#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "abstractChartView.h"

class PieChartView : public AbstractChartView {
public:
    /**
     * @brief PieChartView, constructor of the class
     */
    PieChartView();

    /**
     * @brief getChartView, generate the pie chart and his widget
     * @param data, data used to generates charts
     * @return widget containing charts
     */
    QWidget* getChartView(Data *data);
};

#endif // PIECHARTVIEW_H
