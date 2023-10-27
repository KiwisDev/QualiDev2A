#ifndef TITANIC_H
#define TITANIC_H

#include <QMainWindow>

#include "abstractChartView.h"
#include "pieChartView.h"
#include "barChartView.h"
#include "multiChartView.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Titanic; }
QT_END_NAMESPACE

class Titanic : public QMainWindow {
    Q_OBJECT

private:
    Ui::Titanic *ui;
    AbstractChartView *chartView;
    Data *data;

private slots:
    /**
     * @brief onActionCate, callback function of the "Catégorie" button
     */
    void onActionCate();

    /**
     * @brief onActionAgeCate, callback function of the "Age/Catégorie" button
     */
    void onActionAgeCate();

    /**
     * @brief onActionRatioHF, callback function of the "Ratio H/F" button
     */
    void onActionRatioHF();

public:
    /**
     * @brief Titanic, constructor that initialize the class
     * @param data, data that will be used to generates charts
     * @param parent, parent of the application
     */
    Titanic(Data *data, QWidget *parent = nullptr);

    /**
     * @brief ~Titanic, destructor that destruct the object
     */
    ~Titanic();
};
#endif // TITANIC_H
