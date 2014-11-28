#include "scene.h"
#include "drawable.h"
#include <QKeyEvent>

#include "color.h"

#include "figure.h"
#include "Object.h"


Scene* Scene::SceneInstance = 0;

Scene::Scene(QWidget* parent, Qt::WindowFlags f): QWidget(parent, f)
{
    Objects = QList<Object*>();
    SceneInstance = this;
    width = 32;
    height = 32;


}


//    grabKeyboard();


/*
void Scene::timerEvent(QTimerEvent* timerEvent){

    emit moveSnake();
    CheckAllCollisions();
    repaint();
}
*/


void Scene::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);


    /*
    //nie działało
    QTransform up;
    QTransform down;
    down.rotate(180);
    QTransform left;
    left.rotate(90);
    QTransform right;
    right.rotate(270);



    int Xtrojkat=50;
    int Ytrojkat=50;
    QImage trojkat(":/trójkątrównoboczny.png");

    int Xkwadrat=100;
    int Ykwadrat=50;
    QImage kwadrat(":/kwadrat.png");

    int Xokrag=150;
    int Yokrag=50;
    QImage okrag(":/okrąg.png");

    painter.drawImage(QPoint(Xtrojkat,Ytrojkat), trojkat);
    painter.drawImage(QPoint(Xkwadrat,Ykwadrat), kwadrat);
    painter.drawImage(QPoint(Xokrag,Yokrag), okrag);
    */


    //color* Zielony = new color(0, 255, 0);

    Color* niebieski = new Color(0,0,255);
    Color* zielony = new Color (0,255,0);
    Color* czerwony = new Color (255,0,0);
    Color* rozowy = new Color (255,0,255);

    painter.setPen(QPen(rozowy->kolor, 5)); // 5 - grubość pędzla

    static const QPointF points[4] = {
        QPointF(10.0, 80.0),
        QPointF(20.0, 10.0),
        QPointF(80.0, 30.0),
        QPointF(90.0, 70.0)
    };
    painter.drawConvexPolygon(points, 4);


    painter.setPen(QPen(zielony->kolor,5)); // 5 - grubość pędzla

    static const QPointF pointz[4] = {
        QPointF(50.0, 190.0),
        QPointF(120.0, 190.0),
        QPointF(120.0, 280.0),
        QPointF(50.0, 280.0)
    };

    painter.drawConvexPolygon(pointz, 4);


    foreach(Object* o, Objects)
    {


        //painter.drawConvexPolygon(o->position, 4);  // ._.
    }

}




void Scene::Repaint()
{

  repaint();

};


