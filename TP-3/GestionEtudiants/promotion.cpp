#include "promotion.h"

Promotion::Promotion() {}

void Promotion::loadFileCSV(const QString &path) {
    // Create variable to store temporary readed data
    QString _firstName, _lastName, _bac;
    int _num, _dep;

    // Load file from given path
    QFile file(path);

    // Open file in ReadOnly mode
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug("Unable to load file");
        exit(1);
    }

    // Read data and add students to the list
    while(!file.atEnd()) {
        QString line =  file.readLine();
        QStringList wordList = line.split(';');

        _num = wordList.at(0).toInt();
        _firstName = wordList.at(2);
        _lastName = wordList.at(1);
        _dep = wordList.at(3).toInt();
        _bac = wordList.at(4);
        _bac = _bac.first(_bac.length()-1);

        this->students.append(Student(_num, _firstName, _lastName, _dep, _bac));
    }

    // Close file
    file.close();
}

int Promotion::findStudent(QString student) {
    for(int i=0; i<this->students.size(); i++) {
        if(this->students[i].toQString() == student) {
            return i;
        }
    }

    return -1;
}

void Promotion::addObserver(Observer *observer) {
    this->observerList.push_back(observer);
}

void Promotion::removeObserver(Observer *observer) {
    this->observerList.removeOne(observer);
}

void Promotion::notifyObserver() {
    for(int i=0; i<this->observerList.size(); i++) {
        this->observerList[i]->update();
    }
}
