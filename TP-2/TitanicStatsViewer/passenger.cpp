#include "passenger.h"

Passenger::Passenger(QString _iden, int _class, int _age, int _sex, int _survived) {
    this->_iden = _iden;
    this->_class = _class;
    this->_age = _age;
    this->_sex = _sex;
    this->_survived = _survived;
}

QString Passenger::getIden() const {
    return _iden;
}

int Passenger::getClass() const {
    return _class;
}

int Passenger::getAge() const {
    return _age;
}

int Passenger::getSex() const {
    return _sex;
}

int Passenger::getSurvived() const {
    return _survived;
}
