#include <QKeyEvent>

#include "Color.h"
#include "word.h"

Color::Color(int R, int G, int B, QString a):word(a)
{
    kolor = QColor (R,G,B);
}

QString Color::nazwaklasy(){
    return "kolor";
}
