#pragma once
#include <QPointF>
#include <QGraphicsItem>

class Shape {
public:
    Shape(QPointF p);

    QPointF pos;

    int id;
    static int current_id;

    virtual QGraphicsItem* getGraphicsItem() const = 0;
    virtual QString type() const = 0;
};


class Circle : public Shape {
private:
	double radius;

public: 
	Circle();
    Circle(QPointF p, double r);

	QGraphicsItem* getGraphicsItem() const;
	QString type() const;
};


class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(QPointF p, double w, double h);

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;
};


class Square : public Shape {
private:
    double width;

public:
    Square();
    Square(QPointF p, double w);

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;
};


class Group : public Shape {
private:
    QVector<Shape*> shapeList;

public:
    Group();
    Group(QPointF p);

    void addShape(Shape* s);
    void deleteShape(Shape* s);
    QVector<Shape*> shapes();

    QString type() const;
    QGraphicsItemGroup* getGraphicsItem() const;
};
