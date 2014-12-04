#ifndef FIGURE_H
#define FIGURE_H
#include <QKeyEvent>
#include <QPolygon>

class Figure
{
public:
    Figure(QString names, QPolygon points);
    QString name;
    QStringList synonyms;
    QPolygon polygon; // współrzędne lokalne tworzące daną figurę


};

#endif // FIGURE_H
