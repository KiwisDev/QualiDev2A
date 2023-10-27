#ifndef DATA_H
#define DATA_H

#include <QList>
#include <QDir>
#include <QFile>
#include <QTextStream>

#include "passenger.h"

class Data { 
public:
    QList<Passenger> passengers;

    /**
     * @brief Data, constructor of the class
     */
    Data();

    /**
     * @brief loadData, load data from the given path
     * @param path, path to the file
     */
    void loadData(QString path);
};

#endif // DATA_H
