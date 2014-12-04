#include "Object.h"
#include "figure.h"
#include "scene.h"

Object::Object(Figure* a, Color* b, int posX, int posY )
{
    position = a->polygon;
    position.translate(posX, posY);
    color = b->kolor;



    Scene::SceneInstance->Objects.append(this);

}
