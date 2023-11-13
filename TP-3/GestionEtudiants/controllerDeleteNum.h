#ifndef CONTROLLERDELETENUM_H
#define CONTROLLERDELETENUM_H

#include "controller.h"

class ControllerDeleteNum : public Controller {
public:
    ControllerDeleteNum(Promotion* promo);
    void control(QList<QString> args);
};

#endif // CONTROLLERDELETENUM_H
