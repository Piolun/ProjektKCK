#ifndef FIGURE_H
#define FIGURE_H
#include <QKeyEvent>
#include <QPolygon>
#include "word.h"

class Figure : public word
{
public:
    Figure(QString names, QPolygon points);
    QPolygon polygon; // współrzędne lokalne tworzące daną figurę


};

#endif // FIGURE_H
