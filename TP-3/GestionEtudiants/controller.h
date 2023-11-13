#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QList>

#include "promotion.h"

class Controller {
public:
    Promotion* promo;

    Controller(Promotion* promo) {
        this->promo = promo;
    }

    virtual void control(QList<QString> args) = 0;
};

#endif // CONTROLLER_H
