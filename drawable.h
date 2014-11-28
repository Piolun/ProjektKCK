#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QImage>
#include <QPair>
#include <QPoint>


class Drawable: public QObject
{
    Q_OBJECT
public:
    Drawable(int posX, int posY);
    QPoint position;
    QImage image;
};

#endif // DRAWABLE_H
