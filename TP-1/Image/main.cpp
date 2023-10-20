#include <iostream>
#include <QDir>

#include "QImage"
#include "QColor"
#include "QDebug"

using namespace std;

int main() {
    qDebug() << QDir::currentPath();
    QString path("C:/Users/gaelv/Documents/Cours/QualiDev2A/Image/images/5217_star_wars.jpg");
    QImage image;

    if(!image.load(path)) {
        cout << "Failed to load image" << endl;
        exit(1);
    }

    for(int i=0; i<image.width(); i++) {
        for(int j=0; j<image.height(); j++) {
            QRgb value = image.pixel(i, j);
            int r = qRed(value); int b = qBlue(value); int g = qGreen(value);

            image.setPixel(i, j, qRgb(g, r, b));
        }
    }

    image.save(QString("C:/Users/gaelv/Documents/Cours/QualiDev2A/Image/images/5217_star_wars_green.png"));

    for(int i=0; i<image.width()/2; i++) {
        for(int j=0; j<image.height(); j++) {
            QRgb value = image.pixel(i, j);

            image.setPixel(i, j, qRgb(qGray(value), qGray(value), qGray(value)));
        }
    }

    image.save(QString("C:/Users/gaelv/Documents/Cours/QualiDev2A/Image/images/5217_star_wars_gray.png"));

    return 0;
}
