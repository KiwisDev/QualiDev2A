#pragma once

#include <QString>

/**
 * @brief The Student class
 */
class Student {
private:
    int num;
    QString firstName;
    QString lastName;
    int dep;
    QString bac;

public:
    /**
     * @brief Student constuctor
     * @param num, number of the student
     * @param firstName, first name of the student
     * @param lastName, last name of the student
     * @param dep, department of the student
     * @param bac, bac of the student
     */
    Student(int num, const QString& firstName, const QString& lastName, int dep, const QString& bac);
};

