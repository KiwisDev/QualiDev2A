#ifndef DATA_H
#define DATA_H

#include <QList>
#include <QDir>
#include <QFile>
#include <QTextStream>

#include "passenger.h"

class Data {
private:
    QList<Passenger> passengers;
public:
    /**
     * @brief Data
     */
    Data();

    /**
     * @brief Load data from file
     * @param path
     */
    void loadData(QString path);
};

#endif // DATA_H
