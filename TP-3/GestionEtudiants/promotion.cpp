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
    QTextStream inStream(&file);

    // Read data and add students to the list
    while(!inStream.atEnd()) {
        QString line =  file.readLine();
        QStringList wordList = line.split(';');

        _num = wordList.at(0).toInt();
        _firstName = wordList.at(2);
        _lastName = wordList.at(1);
        _dep = wordList.at(3).toInt();
        _bac = wordList.at(4);

        this->students.append(Student(_num, _firstName, _lastName, _dep, _bac));
    }

    // Close file
    file.close();
}
