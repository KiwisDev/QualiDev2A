#ifndef PASSENGER_H
#define PASSENGER_H

#include <QString>

/**
 * @brief The Passenger class, used to store readen data
 */
class Passenger {
private:
    QString _iden;
    int _class, _age, _sex, _survived;
public:
    /**
     * @brief Passenger, constructor that initialize a Passenger
     * @param _iden, identity value of the passenger
     * @param _class, class value of the passenger
     * @param _age, age value of the passenger
     * @param _sex, sex value of the passenger
     * @param _survived, survived value of the passenger
     */
    Passenger(QString _iden, int _class, int _age, int _sex, int _survived);

    /**
     * @brief getIden, return the identity of the passenger
     * @return _iden, identity value of the passenger
     */
    QString getIden() const;

    /**
     * @brief getClass, return the class of the passenger
     * @return _class, class value of the passenger
     */
    int getClass() const;

    /**
     * @brief getAge, return the age of the passenger
     * @return _age, age value of the passenger
     */
    int getAge() const;

    /**
     * @brief getSex, return the sex of the passenger
     * @return _sex, sex value of the passenger
     */
    int getSex() const;

    /**
     * @brief getSurvived, return the surivavility of the passenger
     * @return _survived, survived value of the passenger
     */
    int getSurvived() const;
};

#endif // PASSENGER_H
