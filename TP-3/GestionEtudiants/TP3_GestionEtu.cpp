#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* promo, QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);

    listView = new ViewList(promo, this->ui.listWidget);
    promo->addObserver(listView);
    connect(this->ui.pushButton_delete_list, SIGNAL(clicked()), listView, SLOT(onDeleteButton()));

    listForm = new ViewForms(promo, &this->ui);
    connect(this->ui.pushButton_addStudent, SIGNAL(clicked()), listForm, SLOT(onAddButton()));
    connect(this->ui.pushButton_delete_number, SIGNAL(clicked()), listForm, SLOT(onDeleteButton()));

    pieChartView = new ViewPieChart(promo, this->ui.groupBox_department);
    promo->addObserver(pieChartView);
}
