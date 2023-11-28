#include "controller.h"
#include "shapemanager.h"
#include "shape.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

ControllerAdd::ControllerAdd(ShapeManager* sm, QRadioButton* c, QRadioButton* sq, QRadioButton* r) : shapeManager(sm) {
    this->circle = c;
    this->square = sq;
    this->rectangle = r;
}

void ControllerAdd::control() {
    if (shapeManager == nullptr) return;

    shapeManager->add(ShapeFactory::getShape(this->circle, this->square, this->rectangle));

	// Add Shape
    //shapeManager->add(new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100));
	//shapeManager->add(new Circle(QPointF(0., 0.), 100.));
}


ControllerMoveShape::ControllerMoveShape(ShapeManager* sm) : shapeManager(sm) {}

void ControllerMoveShape::control(const QVector<QGraphicsItem*>& items) {
	if (shapeManager == nullptr) return;

	// Move Shape
    for (QGraphicsItem* item : items) {
		QVariant variant = item->data(0);
		int id = variant.toInt();

		bool selected = shapeManager->selectShape(id);
        if (selected) {
			QRectF rect = item->boundingRect();
			shapeManager->moveShape(item->scenePos() + rect.center());
		}
	}

	shapeManager->notifyObserver();
}


ControllerGroup::ControllerGroup(ShapeManager *sm) : shapeManager(sm) {}

void ControllerGroup::control(const QVector<QGraphicsItem *> & items) {
    if (shapeManager == nullptr) return;

    // Group Shape
    Group* group = new Group();

    for (QGraphicsItem* item : items) {
        QVariant variant = item->data(0);
        int id = variant.toInt();

        group->addShape(shapeManager->getShapes()[id]);
    }

    shapeManager->add(group);
}
