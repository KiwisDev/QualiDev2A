#pragma once
#include "shapemanager.h"
#include "shapefactory.h"
#include <QPointF>
#include <QRadioButton>

class ControllerAdd {
private:
	ShapeManager* shapeManager;
    QRadioButton* circle, *square, *rectangle;

public:
    ControllerAdd(ShapeManager* sm = nullptr, QRadioButton* c = nullptr, QRadioButton* sq = nullptr, QRadioButton* r = nullptr);
	void control();
};


class ControllerMoveShape {
private:
	ShapeManager* shapeManager;

public:
	ControllerMoveShape(ShapeManager* = nullptr);
    void control(const QVector<QGraphicsItem *> &);
};


class ControllerGroup {
private:
    ShapeManager* shapeManager;

public:
    ControllerGroup(ShapeManager* sm = nullptr);
    void control(const QVector<QGraphicsItem*> & items);
};
