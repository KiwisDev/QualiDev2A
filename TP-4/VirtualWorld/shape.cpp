#include "shape.h"
#include <QGraphicsEllipseItem>

int Shape::current_id; // added

// -- Shape --

Shape::Shape(QPointF p) {
    this->pos = p;
}

// -- Circle --

Circle::Circle() : Shape(QPointF(-1, -1)) {
    this->radius = 0.0d;
    this->id = current_id++;
}

Circle::Circle(QPointF p, double r) : Shape(p) {
    this->radius = r;
    this->id = current_id++;
}


QGraphicsItem* Circle::getGraphicsItem() const {
    QGraphicsItem* item = new QGraphicsEllipseItem(pos.x()-radius, pos.y()-radius, radius*2.0d, radius*2.0d);
	item->setData(0,id);
	return item;
}


QString Circle::type() const {
	return "Circle";
}

// -- Rectangle --

Rectangle::Rectangle() : Shape(QPointF(-1, -1)){
    this->width = 0;
    this->height = 0;
    this->id = current_id++;
}

Rectangle::Rectangle(QPointF p, double w, double h) : Shape(p) {
    this->width = w;
    this->height = h;
    this->id = current_id++;
}

QGraphicsItem* Rectangle::getGraphicsItem() const {
    QGraphicsItem* item = new QGraphicsRectItem(pos.x()-width/2, pos.y()-height/2, width, height);
    item->setData(0, id);
    return item;
}

QString Rectangle::type() const {
    return "Rectangle";
}

// -- Square --

Square::Square() : Shape(QPointF(-1, -1)){
    this->width = 0;
    this->id = current_id++;
}

Square::Square(QPointF p, double w) : Shape(p) {
    this->width = w;
    this->id = current_id++;
}

QGraphicsItem* Square::getGraphicsItem() const {
    QGraphicsItem* item = new QGraphicsRectItem(pos.x()-width/2, pos.y()-width/2, width, width);
    item->setData(0, id);
    return item;
}

QString Square::type() const {
    return "Square";
}

// -- Group --

Group::Group() : Shape(QPointF(-1, -1)) {}

Group::Group(QPointF p) : Shape(p) {}

void Group::addShape(Shape *s) {
    this->shapeList.push_back(s);
}

void Group::deleteShape(Shape *s) {
    this->shapeList.removeOne(s);
}

QVector<Shape*> Group::shapes() {
    return this->shapeList;
}

QGraphicsItemGroup* Group::getGraphicsItem() const {
    QGraphicsItemGroup* itemGroup = new QGraphicsItemGroup();
    for(int i=0; i<this->shapeList.size(); i++) {
        itemGroup->addToGroup(shapeList.at(i)->getGraphicsItem());
    }
    return itemGroup;
}

QString Group::type() const {
    return "Group";
}

Tree::Tree() : Group() {
    this->addShape(new Rectangle(QPointF(0, 10), 20, 40));
    this->addShape(new Rectangle(QPointF(20, -20), 40, 20));
}
