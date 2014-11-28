#ifndef Object_H
#define Object_H

#include <QKeyEvent>
#include "figure.h"
#include "color.h"

class Object
{
public:
    Object(Figure* a, Color* b, int X, int Y);
    QPointF position; // współrzędne globalne (X,Y) - tabela?

};

#endif // Object_H
