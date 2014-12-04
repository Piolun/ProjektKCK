#include <QKeyEvent>

#include "Color.h"

Color::Color(int R, int G, int B, QString names)
{
    QStringList synonyms = names.split(" ");

    kolor = QColor (R,G,B);
}
