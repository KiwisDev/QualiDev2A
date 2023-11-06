#pragma once

#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>
#include <QTextStream>

#include "student.h"

class Promotion {
public:
    QList<Student> students;

	Promotion();
    void loadFileCSV(const QString& path);
};

