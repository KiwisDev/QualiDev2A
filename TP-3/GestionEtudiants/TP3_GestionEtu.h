#pragma once

#include <QMainWindow>

#include "ui_TP3_GestionEtu.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"
#include "viewHistogram.h"
#include "promotion.h"

class TP3_GestionEtu : public QMainWindow {
    Q_OBJECT

public:
    TP3_GestionEtu(Promotion* promo, QWidget *parent = nullptr);
    ~TP3_GestionEtu() {}

private:
    Promotion* promo;
    Ui::TP3_GestionEtuClass ui;

    ViewList* listView;
    ViewForms* listForm;
    ViewPieChart* pieChartView;
    ViewHistogram* histogramView;
};
