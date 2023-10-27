#include "barChartView.h"

BarChartView::BarChartView() : AbstractChartView() {}

QWidget* BarChartView::getChartView(Data *data) {
    int periStat[4];    for(int i=0; i<4; i++) periStat[i] = 0;
    int survStat[4];    for(int i=0; i<4; i++) survStat[i] = 0;

    for(int i=0; i<data->passengers.size(); i++) {
        if(data->passengers.at(i).getSurvived() == 0) {
            periStat[data->passengers.at(i).getClass()]++;
        } else {
            survStat[data->passengers.at(i).getClass()]++;
        }
    }

    QBarSet *peri = new QBarSet("Péri");         for(int i=0; i<4; i++) peri->append(periStat[i]);
    QBarSet *surv = new QBarSet("Survivant");    for(int i=0; i<4; i++) surv->append(survStat[i]);

    QBarSeries *series = new QBarSeries();
    series->append(peri);
    series->append(surv);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Survivant / Catégorie");

    QStringList categories;
    categories << "Equipage" << "Première" << "Seconde" << "Troisième";
    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    axisY->applyNiceNumbers();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(800);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
