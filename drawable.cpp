#include "drawable.h"
#include "scene.h"

Drawable::Drawable(int posX, int posY)
{
    //Scene::SceneInstance->Objects.append(this);
    this->position = QPoint(posX, posY);

}
