#ifndef COLOR_H
#define COLOR_H
#include <QColor>

#include <QKeyEvent>

class Color
{
public:
    Color(int R, int G, int B, QString names = 0);

    QStringList synonyms;
    QColor kolor;
};

#endif // COLOR_H
