#include "titanic.h"

#include <QApplication>
#include <QDir>

#include "data.h"

int main(int argc, char *argv[]) {
    Data data;
    data.loadData("stats/titanic.dbf");

    QApplication a(argc, argv);
    Titanic w(&data);
    w.show();
    return a.exec();
}
