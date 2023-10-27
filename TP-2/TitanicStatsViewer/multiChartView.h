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
    /**
     * @brief getPopCateView, generate an horizontal bar chart
     * @param data, data used to generate charts
     * @return widget containing charts
     */
    QWidget* getPopCateView(Data *data);

    /**
     * @brief getSurvCateView, generate an horizontal stackable bar chart
     * @param data, data used to generate charts
     * @return widget containing charts
     */
    QWidget* getSurvCateView(Data *data);

    /**
     * @brief getPopAgeView, generate an horizontal bar chart
     * @param data, data used to generate charts
     * @return widget containing charts
     */
    QWidget* getPopAgeView(Data *data);

    /**
     * @brief getSurvAgeView, generate an horizontal stackable bar chart
     * @param data, data used to generate charts
     * @return widget containing charts
     */
    QWidget* getSurvAgeView(Data *data);

public:
    /**
     * @brief MultiChartView, constructor of the class
     */
    MultiChartView();

    /**
     * @brief getChartView, generate the grid layout widget with charts
     * @param data, data used to generates charts
     * @return widget containing charts
     */
    QWidget* getChartView(Data *data);
};

#endif // MULTICHARTVIEW_H
