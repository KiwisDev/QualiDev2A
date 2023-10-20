#ifndef TITANIC_H
#define TITANIC_H

#include <QMainWindow>

#include "abstractChartView.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Titanic; }
QT_END_NAMESPACE

class Titanic : public QMainWindow {
    Q_OBJECT

private:
    Ui::Titanic *ui;
    //AbstractChartView chartView;
    Data *data;

private slots:
    void onActionCate();
    void onActionAgeCate();
    void onActionRatioHF();

public:
    Titanic(Data *data, QWidget *parent = nullptr);
    ~Titanic();
};
#endif // TITANIC_H
