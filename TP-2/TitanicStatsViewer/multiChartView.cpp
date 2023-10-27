#include "multiChartView.h"

MultiChartView::MultiChartView() {}

QWidget* MultiChartView::getChartView(Data *data) {
    QGridLayout *layout = new QGridLayout();

    layout->addWidget(this->getPopCateView(data), 1, 1);
    layout->addWidget(this->getPopAgeView(data), 2, 1);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    return widget;
}

QWidget* MultiChartView::getPopCateView(Data *data) {
    int popu[4];    for(int i=0; i<4; i++) popu[i] = 0;

    for(int i=0; i<data->passengers.size(); i++) {
        popu[data->passengers.at(i).getClass()]++;
    }

    QBarSet *pop = new QBarSet("Population");   for(int i=0; i<4; i++) pop->append(popu[i]);

    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    series->append(pop);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Population / Catégorie");

    QStringList categories;
    categories << "Equipage" << "Première" << "Seconde" << "Troisième";
    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(categories);
    chart->addAxis(axisY, Qt::AlignLeft);

    QValueAxis *axisX = new QValueAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisX->applyNiceNumbers();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

QWidget* MultiChartView::getPopAgeView(Data *data) {
    int popu[2];    for(int i=0; i<2; i++) popu[i] = 0;

    for(int i=0; i<data->passengers.size(); i++) {
        popu[data->passengers.at(i).getAge()]++;
    }

    QBarSet *pop = new QBarSet("Population");   for(int i=0; i<2; i++) pop->append(popu[i]);

    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    series->append(pop);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Population / Age");

    QStringList categories;
    categories << "Enfant" << "Adulte";
    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(categories);
    chart->addAxis(axisY, Qt::AlignLeft);

    QValueAxis *axisX = new QValueAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisX->applyNiceNumbers();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
