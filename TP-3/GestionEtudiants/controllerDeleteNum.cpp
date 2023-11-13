#include "controllerDeleteNum.h"

ControllerDeleteNum::ControllerDeleteNum(Promotion* promo) : Controller(promo) {}

void ControllerDeleteNum::control(QList<QString> args) {
    int id = args[0].toInt();

    for(int i=0; i<this->promo->students.size(); i++) {
        if(this->promo->students[i].getNum() == id) {
            this->promo->students.removeAt(i);
            break;
        }
    }

    this->promo->notifyObserver();
}
