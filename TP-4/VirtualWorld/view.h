#pragma once
#include "shapemanager.h"
#include "controller.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTreeWidget>


class PaintView : public QGraphicsScene, public Observer {
	Q_OBJECT

private:
	ShapeManager* shapeManager;
	QPointF mousePos;
	QString toolbox;

public:
	PaintView(ShapeManager* = nullptr);

	void updateModel() override;

protected:
	void drawForeground(QPainter* painter, const QRectF& rect) override;

public slots:
	void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
};

class TreeView : public Observer {
private:
	ShapeManager* shapeManager;
	QTreeWidget* treeview;

public:
	TreeView(ShapeManager* = nullptr, QTreeWidget* = nullptr);

    void updateModel() override;
};
