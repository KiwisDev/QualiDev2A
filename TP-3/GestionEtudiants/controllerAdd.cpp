#include "controllerAdd.h"

ControllerAdd::ControllerAdd(Promotion* promo) : Controller(promo) {}

void ControllerAdd::control(QList<QString> args) {
    Student student(args[0].toInt(), args[1], args[2], args[4].toInt(), args[3]);
    promo->students.push_back(student);

    promo->notifyObserver();
}
