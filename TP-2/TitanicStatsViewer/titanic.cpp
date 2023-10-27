#include "titanic.h"
#include "ui_titanic.h"

Titanic::Titanic(Data *data, QWidget *parent) : QMainWindow(parent), ui(new Ui::Titanic) {
    this->data = data;
    this->chartView = new PieChartView();

    ui->setupUi(this);

    connect(ui->actionCate, SIGNAL(triggered()), this, SLOT(onActionCate()));
    connect(ui->actionAgeCate, SIGNAL(triggered()), this, SLOT(onActionAgeCate()));
    connect(ui->actionRatioHF, SIGNAL(triggered()), this, SLOT(onActionRatioHF()));

    this->setCentralWidget(this->chartView->getChartView(this->data));
}

void Titanic::onActionCate() {
    delete(this->chartView);
    this->chartView = new BarChartView();
    this->setCentralWidget(this->chartView->getChartView(this->data));
}

void Titanic::onActionAgeCate() {
    delete(this->chartView);
    this->chartView = new MultiChartView();
    this->setCentralWidget(this->chartView->getChartView(this->data));

}

void Titanic::onActionRatioHF() {
    delete(this->chartView);
    this->chartView = new PieChartView();
    this->setCentralWidget(this->chartView->getChartView(this->data));

}

Titanic::~Titanic() {
    delete ui;
}

