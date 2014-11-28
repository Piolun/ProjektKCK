#ifndef FIGURE_H
#define FIGURE_H
#include <QKeyEvent>


class Figure
{
public:
    Figure(QString names, QPointF points[]);
    QString name;
    QStringList synonyms;
    QPointF points; // współrzędne lokalne tworzące daną figurę


};

#endif // FIGURE_H
