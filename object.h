#ifndef Object_H
#define Object_H

#include <QKeyEvent>
#include "figure.h"
#include "Color.h"
#include <QPolygon>

class Object
{
public:
    Object(QString a, QString b, int X, int Y);
    QPolygon position; // współrzędne globalne (X,Y) - tabela?
    Color* color;
    Figure* figure;

    QString fname;
    QString cname;

    int xMin = std::numeric_limits<int>::max();
    int xMax = std::numeric_limits<int>::min();
    int yMin = std::numeric_limits<int>::max();
    int yMax = std::numeric_limits<int>::min();

    QList<QPoint> Bottomcenter;
    QList<QPoint> Topcenter;

    ~Object();

};

#endif // Object_H
