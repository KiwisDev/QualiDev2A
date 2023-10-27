#ifndef MULTICHARTVIEW_H
#define MULTICHARTVIEW_H

#include <QGridLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QHorizontalStackedBarSeries>

#include "abstractChartView.h"

class MultiChartView : public AbstractChartView {
private:
    QWidget* getPopCateView(Data *data);
    QWidget* getSurvCateView(Data *data);
    QWidget* getPopAgeView(Data *data);
    QWidget* getSurvAgeView(Data *data);

public:
    MultiChartView();
    QWidget* getChartView(Data *data);
};

#endif // MULTICHARTVIEW_H
