#include "Object.h"
#include "figure.h"
#include "scene.h"

Object::Object(Figure* a, Color* b, int posX, int posY )
{
    //position = QPointF(a->points.rx()+posX,a->points.ry()+posY); //Jak się bawić tabelkami? ._.





    Scene::SceneInstance->Objects.append(this);

}
