#include "student.h"

Student::Student(int num, const QString& firstName, const QString& lastName, int dep, const QString& bac) {
    this->num = num;
    this->firstName = firstName;
    this->lastName = lastName;
    this->dep = dep;
    this->bac = bac;
}
