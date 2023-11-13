#include "viewPieChart.h"

ViewPieChart::ViewPieChart(Promotion* promo, QGroupBox* groupBox) {
    this->promo = promo;
    this->groupBox = groupBox;

    update();
}

void ViewPieChart::update() {
    delete(groupBox->layout());
    QVBoxLayout* layout = new QVBoxLayout();

    int depCount[97]; // index 0 is for unknow or error
    for(int i=0; i<97; i++) {
        depCount[i] = 0;
    }

    for(int i=0; i<this->promo->students.size(); i++) {
        int numDep = this->promo->students[i].getDep();
        if(numDep > 0 && numDep < 97) {
            depCount[numDep]++;
        } else {
            depCount[0]++;
        }
    }

    QPieSeries *series = new QPieSeries();
    for(int i=1; i<97; i++) {
        if(depCount[i] > 0) {
            series->append(QString::number(i), depCount[i]);
        }
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("");

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);
    groupBox->setLayout(layout);
}
