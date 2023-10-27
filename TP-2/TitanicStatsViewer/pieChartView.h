#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "abstractChartView.h"

class PieChartView : public AbstractChartView {
public:
    PieChartView();
    QWidget* getChartView(Data *data);
};

#endif // PIECHARTVIEW_H
