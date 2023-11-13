#ifndef CONTROLLERADD_H
#define CONTROLLERADD_H

#include "controller.h"

class ControllerAdd : public Controller {
public:
    ControllerAdd(Promotion* promo);
    void control(QList<QString> args);
};

#endif // CONTROLLERADD_H
