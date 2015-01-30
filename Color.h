#ifndef Color_H
#define Color_H
#include <QColor>
#include "word.h"

#include <QKeyEvent>

class Color : public word
{
public:
    Color(int R, int G, int B, QString a);

    QColor kolor;

    QString nazwaklasy() override;
};

#endif // Color_H
