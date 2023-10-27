#include "pieChartView.h"

PieChartView::PieChartView() : AbstractChartView() {}

QWidget* PieChartView::getChartView(Data *data) {
    int femaleCount = 0, maleCount = 0;

    for(int i=0; i<data->passengers.size(); i++)
        (data->passengers.at(i).getSex() == 0) ? ++femaleCount : ++maleCount;

    QPieSeries *series = new QPieSeries();
    series->append("Female", femaleCount);
    series->append("Male", maleCount);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Ratio H/F");
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(800);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
