#include "titanic.h"
#include "ui_titanic.h"

Titanic::Titanic(Data *data, QWidget *parent) : QMainWindow(parent), ui(new Ui::Titanic) {
    this->data = data;
    ui->setupUi(this);
}

Titanic::~Titanic() {
    delete ui;
}

