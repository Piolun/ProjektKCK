#ifndef Object_H
#define Object_H

#include <QKeyEvent>
#include "figure.h"
#include "color.h"
#include <QPolygon>

class Object
{
public:
    Object(Figure* a, Color* b, int X, int Y);
    QPolygon position; // współrzędne globalne (X,Y) - tabela?
    QColor color;

};

#endif // Object_H
