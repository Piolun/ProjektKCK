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


    Color* niebieski = new Color(0,0,255);
    Color* zielony = new Color (0,255,0);
    Color* czerwony = new Color (255,0,0);
    Color* rozowy = new Color (255,0,255);
    Color* zolty = new Color (255,255,0);



    QPolygon temp;
    temp.setPoints(4, 0, 0, 100, 0, 100, 100, 0, 100);
    Figure* kwadrat = new Figure("kwadrat", temp);

    Object* kwadrat1 = new Object(kwadrat,rozowy,0,0);
    Object* kwadrat2 = new Object(kwadrat,niebieski,30,30);
    Object* kwadrat3 = new Object(kwadrat,zielony,100,100);


    foreach(Object* o, Objects)
    {

        painter.setPen(QPen(o->color, 5));
        painter.drawConvexPolygon(o->position);  // yaay
    }

}




void Scene::Repaint()
{

  repaint();

};


