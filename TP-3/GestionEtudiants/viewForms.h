#pragma once

#include <QList>
#include <QGroupBox>

#include "ui_TP3_GestionEtu.h"
#include "promotion.h"
#include "controllerAdd.h"
#include "controllerDeleteNum.h"
#include "observer.h"

class ViewForms : public QObject {
    Q_OBJECT

private:
    Promotion* promo;
    Ui::TP3_GestionEtuClass* ui;
    Controller* controller;

public slots:
    void onAddButton();
    void onDeleteButton();

public:
    ViewForms(Promotion* promo, Ui::TP3_GestionEtuClass* ui);
};

