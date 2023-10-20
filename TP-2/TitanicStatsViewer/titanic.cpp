#include "titanic.h"
#include "ui_titanic.h"

Titanic::Titanic(Data *data, QWidget *parent) : QMainWindow(parent), ui(new Ui::Titanic) {
    this->data = data;
    ui->setupUi(this);

    connect(ui->actionCate, SIGNAL(triggered()), this, SLOT(onActionCate()));
    connect(ui->actionAgeCate, SIGNAL(triggered()), this, SLOT(onActionAgeCate()));
    connect(ui->actionRatioHF, SIGNAL(triggered()), this, SLOT(onActionRatioHF()));
}

void Titanic::onActionCate() {

}

void Titanic::onActionAgeCate() {

}

void Titanic::onActionRatioHF() {

}

Titanic::~Titanic() {
    delete ui;
}

