#include <iostream>
#include <cmath>

#include "QList"
#include "QFile"
#include "QTextStream"

using namespace std;

int main() {
    // Odd list

    QList<int> impairs;
    for(int i=0; i<100; i++) {
        impairs.append(2*i+1);
    }

    // Open file - WriteOnly

    QString path("C:/Users/gaelv/Documents/Cours/QualiDev2A/File/files/out.txt");
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly)) {
        cout << "Failed to open file in WriteOnly mode" << endl;
        exit(1);
    }

    // Write file

    QTextStream outStream(&file);

    for(int i=0; i<impairs.size(); i++) {
        outStream << impairs.at(i) << "," << pow(impairs.at(i), 2) << "\n";
    }

    file.close();

    // Open file - ReadOnly

    if(!file.open(QIODevice::ReadOnly)) {
        cout << "Failed to open file in ReadOnly mode" << endl;
        exit(2);
    }

    // Read file

    QTextStream inStream(&file);

    int cpt = 0;
    while(!inStream.atEnd()) {
        cpt++;
        QString line = inStream.readLine();
        QStringList separator = line.split(",");
        cout << separator.at(1).toStdString() << " : " << cpt << endl;
    }

    return 0;
}
