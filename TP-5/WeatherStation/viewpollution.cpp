#include "viewpollution.h"
#include <QDebug>
#include <QDateTime>

ViewPollution::ViewPollution(DbManager* dbm, QWidget* widget) :dbm(dbm), widget(widget) {
    this->dbm->addObserver(this);

    series = new QLineSeries();

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Simple date/line chart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //    chart->createDefaultAxes();
    axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("HH:mm");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Air Quality Indice");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGridLayout *chartLayout = new QGridLayout;
    chartLayout->addWidget(chartView, 0, 0);
    chartLayout->setContentsMargins(0, 0, 0, 0);

    // update chart
    widget->setLayout(chartLayout);

    ViewPollution::update();
}

void ViewPollution::update() {
    if(this->dbm->isOpen()) {
        QMap<int, int> data = this->dbm->getAllData();
        series->clear();

        int maxValue = 0;
        for(QMap<int, int>::iterator it = data.begin(); it != data.end(); it++) {
            series->append(it.key()*1000, it.value());
            if(it.value() > maxValue)
                maxValue = it.value();
        }

        QMap<int, int>::iterator it = data.begin();
        QDateTime dt0;
        dt0.setMSecsSinceEpoch(it.key()*1000);

        it = data.end()-1;
        QDateTime dt1;
        dt1.setMSecsSinceEpoch(it.key()*1000);
        axisX->setRange( dt0,dt1);
        axisY->setRange(0,maxValue+2);

        widget->repaint();
    }
    else {
        qDebug() << "DB is not open at update time";
    }
}
