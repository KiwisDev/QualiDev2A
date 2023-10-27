#include "titanic.h"

#include <QFileDialog>
#include <QStandardPaths>
#include <QApplication>
#include <QDir>

#include "data.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open data", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    qDebug() << filePath;
    Data data;
    data.loadData(filePath);

    Titanic w(&data);
    w.show();
    return a.exec();
}
