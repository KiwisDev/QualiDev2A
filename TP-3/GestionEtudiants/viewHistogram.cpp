#include "viewHistogram.h"
#include <iostream>

ViewHistogram::ViewHistogram(Promotion* promo, QGroupBox* groupBox) {
    this->promo = promo;
    this->groupBox = groupBox;

    update();
}

void ViewHistogram::update() {
    delete(groupBox->layout());
    QVBoxLayout* layout = new QVBoxLayout();

    int bacCount[7]; // index 0 is for unknow or error
    for(int i=0; i<7; i++) {
        bacCount[i] = 0;
    }

    for(int i=0; i<this->promo->students.size(); i++) {
        QString bac = this->promo->students[i].getBac();
        std::cout << bac.toStdString() << std::endl;

        if(bac == "Autre")
            bacCount[0]++;
        else if(bac == "ES")
            bacCount[1]++;
        else if(bac == "Etr")
            bacCount[2]++;
        else if(bac == "L")
            bacCount[3]++;
        else if(bac == "S")
            bacCount[4]++;
        else if(bac == "STMG")
            bacCount[5]++;
        else if(bac == "STI")
            bacCount[6]++;
    }

    QBarSet* barSet = new QBarSet("Bac");
    *barSet << bacCount[0] << bacCount[1] << bacCount[2] << bacCount[3] << bacCount[4] << bacCount[5] << bacCount[6];

    QBarSeries* series = new QBarSeries();
    series->append(barSet);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("");

    QStringList categories;
    categories << "Autre" << "ES" << "Etr" << "L" << "S" << "STMG" << "STI";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setRange(0, bacCount[3]);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(false);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);
    groupBox->setLayout(layout);
}
