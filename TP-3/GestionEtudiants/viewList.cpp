#include "viewList.h"

ViewList::ViewList(Promotion* promo, QListWidget* listWidget) {
    this->promo = promo;
    this->listWidget = listWidget;

    update();
}

void ViewList::update() {
    this->listWidget->clear();
    for(Student student : promo->students)
        listWidget->addItem(student.toQString());
}

void ViewList::onDeleteButton() {
    this->controller = new ControllerDelete(promo);

    QList<QListWidgetItem*> selectedItems = this->listWidget->selectedItems();
    QList<QString> studentsList;
    for(auto item : selectedItems) {
        studentsList.push_back(item->text());
    }

    this->controller->control(studentsList);

    delete(this->controller);
}
