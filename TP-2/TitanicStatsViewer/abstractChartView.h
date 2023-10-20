#ifndef ABSTRACTCHARTVIEW_H
#define ABSTRACTCHARTVIEW_H

#include <QWidget>

#include "data.h"

class AbstractChartView {
public:
    AbstractChartView();
    virtual QWidget* getChartView(Data *data) = 0;
};

#endif // ABSTRACTCHARTVIEW_H
