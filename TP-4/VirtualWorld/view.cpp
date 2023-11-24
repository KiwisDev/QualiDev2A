#include "view.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

// -- Tree view --

TreeView::TreeView(ShapeManager* sm, QTreeWidget* tw) : Observer(), shapeManager(sm), treeview(tw) {}

void TreeView::updateModel() {
    // Clear Treeview
    treeview->clear();

    // Generate Data
    QStringList labels;
    labels << "id" << "type";
    treeview->setHeaderLabels(labels);

    QVector<Shape*> shapes = shapeManager->getShapes();
    for (Shape* shape : shapes) {
        QTreeWidgetItem* item = new QTreeWidgetItem(treeview);
        item->setText(0, QString::number(shape->id));
        item->setText(1, shape->type());


        QTreeWidgetItem* itemChild1 = new QTreeWidgetItem(item);
        itemChild1->setText(0, "ChildId1");
        itemChild1->setText(1, "ChildType1");

        QTreeWidgetItem* itemChild2 = new QTreeWidgetItem(item);
        itemChild2->setText(0, "ChildId2");
        itemChild2->setText(1, "ChildType2");
    }
}

// -- Paintview --

PaintView::PaintView( ShapeManager* sm) : QGraphicsScene(), Observer(), shapeManager(sm) {}

void PaintView::drawForeground(QPainter* painter, const QRectF& rect) {
    if (toolbox.isEmpty()) return;

    QGraphicsView* gv = (QGraphicsView*)this->parent();

    QPointF p1 = gv->mapToScene(QPoint(10, 10));

    painter->save();

    painter->setBrush(QBrush(QColor(229,255,204)));
    painter->setPen(Qt::black);

    painter->drawRect(p1.x() + 10, p1.y() + 10, toolbox.size() * 10, 20);
    painter->drawText(int(p1.x() + 14), int(p1.y() + 12), toolbox.size() * 10, 20, Qt::AlignLeft, toolbox);

    painter->restore();

}

void PaintView::updateModel() {
    // Clear
    clear();

    // Get models
    QVector<Shape*> shapes = shapeManager->getShapes();

    for (Shape* shape : shapes) {
        QGraphicsItem* item = shape->getGraphicsItem();
        if (item != nullptr) {
            item->setAcceptDrops(true);
            item->setFlag(QGraphicsItem::ItemIsSelectable);
            addItem(item);
        }
    }

    update();
}

void PaintView::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    if (mouseEvent->button() == Qt::LeftButton) {
        mousePos = mouseEvent->scenePos();
        toolbox = "mousePressEvent (" + QString::number(mousePos.x()) + "," + QString::number(mousePos.y()) + ")";

        for (auto s : items(mousePos)) {
            s->setSelected(!s->isSelected());
            s->setOpacity( 1.1-s->opacity()); //assuming default opacity=1. switch from 1. to 0.1, and conversely
        }
    }

    update();
}

void PaintView::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    if ( selectedItems().size() > 0 && (mouseEvent->buttons() & Qt::LeftButton)) {
        QPointF mousePosNew = mouseEvent->scenePos();

        toolbox = "mouseMoveEvent (" + QString::number(mousePosNew.x()) + "," + QString::number(mousePosNew.y()) + ")";
        QPointF mouseD = mousePosNew - mousePos;
        for (QGraphicsItem* item : selectedItems()) {
            item->setCursor(QCursor(Qt::ClosedHandCursor));
            item->moveBy(mouseD.x(), mouseD.y());
        }
        mousePos = mousePosNew;
    }

    update();
}

void PaintView::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    toolbox = "mouseReleaseEvent";

    // Call Controller to modify the model
    (new ControllerMoveShape(shapeManager))->control(selectedItems());

    for (QGraphicsItem* item : selectedItems()) {
        item->setCursor(QCursor(Qt::ArrowCursor));
        item->setSelected(false);
    }

    update();
}