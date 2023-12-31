#ifndef ABSTRACTCHARTVIEW_H
#define ABSTRACTCHARTVIEW_H

#include <QWidget>

#include "data.h"

class AbstractChartView {
public:
    /**
     * @brief AbstractChartView, empty constructor of the abstract class
     */
    AbstractChartView();

    /**
     * @brief getChartView, virtual function
     * @param data, data used to generates charts
     * @return widget containing charts
     */
    virtual QWidget* getChartView(Data *data) = 0;
};

#endif // ABSTRACTCHARTVIEW_H
