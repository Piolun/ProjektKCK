#ifndef COLOR_H
#define COLOR_H
#include <QColor>
#include "word.h"

#include <QKeyEvent>

class Color : public word
{
public:
    Color(int R, int G, int B, QString a);

    QColor kolor;
};

#endif // COLOR_H
