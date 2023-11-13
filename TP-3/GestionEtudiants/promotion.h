#pragma once

#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>

#include "student.h"
#include "observer.h"

class Promotion : public Observable {
private:
    QList<Observer*> observerList;

public:
    QList<Student> students;

	Promotion();
    void loadFileCSV(const QString& path);
    /**
     * @brief findStudent
     * @param student
     * @return the index of the student in the QList, -1 if the student does not exists
     */
    int findStudent(QString student);

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObserver();
};

