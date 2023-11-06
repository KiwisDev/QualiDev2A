#include <QApplication>

#include "TP3_GestionEtu.h"
#include "promotion.h"
#include "student.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Promotion* promo = new Promotion();
    promo->loadFileCSV("C:/Users/gaelv/Documents/Cours/QualiDev2A/TP-3/GestionEtudiants/data/promoDUT.csv");

    TP3_GestionEtu w;
    w.show();

    return a.exec();
}
