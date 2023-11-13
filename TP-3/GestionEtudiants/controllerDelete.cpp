#include "controllerDelete.h"

ControllerDelete::ControllerDelete(Promotion* promo) : Controller(promo) {}

void ControllerDelete::control(QList<QString> args) {
    for(int i=0; i<args.size(); i++) {

        int studentId = this->promo->findStudent(args[i]);

        if(studentId == -1) { // abort modification if student does not exists
            return;
        }

        this->promo->students.removeAt(studentId);
    }

    this->promo->notifyObserver();
}
