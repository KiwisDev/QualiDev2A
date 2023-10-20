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
     * @brief Passenger
     * @param _iden
     * @param _class
     * @param _age
     * @param _sex
     * @param _survived
     */
    Passenger(QString _iden, int _class, int _age, int _sex, int _survived);

    /**
     * @brief getIden
     * @return _iden
     */
    QString getIden() const;

    /**
     * @brief getClass
     * @return _class
     */
    int getClass() const;

    /**
     * @brief getAge
     * @return _age
     */
    int getAge() const;

    /**
     * @brief getSex
     * @return _sex
     */
    int getSex() const;

    /**
     * @brief getSurvived
     * @return _survived
     */
    int getSurvived() const;
};

#endif // PASSENGER_H
