#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "shape.h"
#include <QRadioButton>

class ShapeFactory {
private:
    ShapeFactory();

public:
    static Shape* getShape(QRadioButton* c, QRadioButton* sq, QRadioButton* r);
};

#endif // SHAPEFACTORY_H
