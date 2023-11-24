#include "shapefactory.h"
#include <iostream>

ShapeFactory::ShapeFactory() {}

Shape* ShapeFactory::getShape(QRadioButton* c, QRadioButton* sq, QRadioButton* r) {
    if(c->isChecked()) {
        return new Circle(QPointF(0, 0), 20.0d);
    }

    if(sq->isChecked()) {
        return new Square(QPointF(0, 0), 40.0d);
    }

    if(r->isChecked()) {
        return new Rectangle(QPointF(0, 0), 80.0d, 40.0d);
    }

    return new Circle(QPointF(0, 0), 20.0d);
}
