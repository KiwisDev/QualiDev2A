#ifndef CONTROLLERDELETE_H
#define CONTROLLERDELETE_H

#include "controller.h"

class ControllerDelete : public Controller {
public:
    ControllerDelete(Promotion* promo);
    void control(QList<QString> args);
};

#endif // CONTROLLERDELETE_H
