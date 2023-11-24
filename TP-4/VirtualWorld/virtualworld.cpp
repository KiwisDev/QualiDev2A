#include "virtualworld.h"
#include "controller.h"
#include "view.h"
#include <QDebug>

VirtualWorld::VirtualWorld(QWidget *parent, ShapeManager* sm) : QMainWindow(parent), shapeManager(sm) {
    ui.setupUi(this);

    // Paint View
    paintview = new PaintView(shapeManager);
    shapeManager->addObserver(paintview);
    ui.graphicsView->setScene(paintview);
    paintview->setParent(ui.graphicsView);

    // Tree View
    treeview = new TreeView(shapeManager, ui.treeWidget);
    shapeManager->addObserver(treeview);

    // Connect buttons
    connect(ui.Object_AddButton, &QPushButton::pressed, this, &VirtualWorld::addShape);
}

VirtualWorld::~VirtualWorld() {
    delete shapeManager;
}

void VirtualWorld::addShape() {
    ControllerAdd(shapeManager, ui.radioButton_Circle, ui.radioButton_Square, ui.radioButton_Rectangle).control();
}
