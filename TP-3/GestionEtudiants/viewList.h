#pragma once

#include <QListWidget>
#include <QList>
#include <QListWidgetItem>
#include <QStringList>

#include "promotion.h"
#include "controllerDelete.h"
#include "observer.h"

class ViewList : public QObject, public Observer {
    Q_OBJECT

private:
    Promotion* promo;
    QListWidget* listWidget;
    Controller* controller;

    void update();

public slots:
    void onDeleteButton();

public:
    ViewList(Promotion* promo, QListWidget* listWidget);
};

