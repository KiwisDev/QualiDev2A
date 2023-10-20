#include "data.h"

Data::Data() {}

void Data::loadData(QString path) {
    // Create variables to get temporary readed files
    QString _iden;
    int _class, _age, _sex, _survived;

    // Load file from given path
    QFile file(QDir::currentPath() + "/../TitanicStatsViewer/" + path);

    // Open file in ReadOnly mode
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << QString("Failed to open file in read only");
        exit(1);
    }
    QTextStream inStream(&file);

    // Skip 5 firsts lines
    for(int i=0; i<5; i++) {
        inStream.readLine();
    }

    // Read lines and add passengers to the list
    while(!inStream.atEnd()) {
        inStream >> _iden;
        inStream >> _class;
        inStream >> _age;
        inStream >> _sex;
        inStream >> _survived;

        this->passengers.append(Passenger(_iden, _class, _age, _sex, _survived));
    }

    // Close file
    file.close();
}
