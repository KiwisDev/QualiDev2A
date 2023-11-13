#include "viewForms.h"

ViewForms::ViewForms(Promotion* promo, Ui::TP3_GestionEtuClass* ui) {
    this->promo = promo;
    this->ui = ui;

    // Add bac :

    this->ui->lineEdit_add_BAC->addItem("Autre");
    this->ui->lineEdit_add_BAC->addItem("ES");
    this->ui->lineEdit_add_BAC->addItem("Etr");
    this->ui->lineEdit_add_BAC->addItem("L");
    this->ui->lineEdit_add_BAC->addItem("S");
    this->ui->lineEdit_add_BAC->addItem("STMG");
    this->ui->lineEdit_add_BAC->addItem("STI");

    // Add Dep :

    for(int i=1; i<97; i++) {
        this->ui->lineEdit_add_department->addItem(QString::number(i));
    }

}

void ViewForms::onAddButton() {
    this->controller = new ControllerAdd(promo);

    QList<QString> args;

    args.push_back(this->ui->lineEdit_add_number->text());
    args.push_back(this->ui->lineEdit_add_firstname->text());
    args.push_back(this->ui->lineEdit_add_lastname->text());
    args.push_back(this->ui->lineEdit_add_BAC->currentText());
    args.push_back(this->ui->lineEdit_add_department->currentText());

    this->controller->control(args);

    delete(this->controller);
}

void ViewForms::onDeleteButton() {
    this->controller = new ControllerDeleteNum(promo);

    QList<QString> args;

    args.push_back(this->ui->lineEdit_remove_number->text());

    this->controller->control(args);

    delete(this->controller);
}
