#include "scene.h"
#include <QKeyEvent>

#include "Color.h"
#include "figure.h"
#include "order.h"

#include "Object.h"

Scene* Scene::SceneInstance = 0;



Scene::Scene(QWidget* parent, Qt::WindowFlags f): QWidget(parent, f)
{
    Objects = QList<Object*>();
    TempObjects = QList<Object*>();
    ScriptObjects = QList<Object*>();
    PotentialObjects = QList<word*>();
    Dictionary = QList<word*>();
    inputI = QList<word*>();
    SceneInstance = this;
    width = 32;
    height = 32;


    new Color(0,0,255,"niebiesk błękit");
    new Color(0,255,0,"zielon");
    new Color(255,0,0,"czerwon");
    new Color(255,0,255,"róż");
    new Color (255,255,0,"żółt");

    //new Color (65,105,225,"kolor_królewsk"); //tokenizator psuje - trza znaleźć inną metodę






    QPolygon temp;
    temp.setPoints(4, 0, 0, 50, 0, 50, 50, 0, 50);
    new Figure("kwadrat", temp);

    temp.setPoints(3, 25, 0, 0, 50, 50, 50);
    new Figure("trójkąt", temp);

    temp.setPoints(4, 0, 0, 100, 0, 100, 50, 0, 50);
    new Figure("prostokąt", temp);

    temp.setPoints(4, 25, 0, 75, 0, 100, 50, 0, 50);
    new Figure("trapez", temp);


    new Object("trójkąt","różowy",0,250);
    new Object("kwadrat","niebieski",550,250);
    new Object("kwadrat","zielonkawy",100,250);
    new Object("trójkąt","zielony",400,250);
    new Object("prostokąt","żółty",200,250);
    new Object("trapez","niebieski",300,250);


}


void Scene::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);


    foreach(Object* o, Objects)
    {

        painter.setPen(QPen(o->color->kolor, 2));
        painter.drawConvexPolygon(o->position);  // yaay


    }

    painter.setPen(QPen(Qt::red, 7));
    painter.drawPoint(pointer);
}



void Scene::Repaint()
{

  repaint();

};


