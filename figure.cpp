#include "figure.h"


Figure::Figure(QString a,QPolygon points):word(a)
{
    polygon = QPolygon(points);
}

QString Figure::nazwaklasy(){
    return "figura";
}

/*

    painter.setPen(QPen(rozowy->kolor, 5)); // 5 - grubość pędzla

    static const QPointF points[4] = {
        QPointF(10.0, 80.0),
        QPointF(20.0, 10.0),
        QPointF(80.0, 30.0),
        QPointF(90.0, 70.0)
    };
    painter.drawConvexPolygon(points, 4); // painter działa tylko wewnątrz scene.cpp :/

*/
