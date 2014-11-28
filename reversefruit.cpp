#include "reversefruit.h"
#include "snake.h"
#include "scene.h"

ReverseFruit::ReverseFruit(int PosX, int PosY):Pickup(PosX, PosY)
{
    image = QImage (":/reversefruit.png");
}

void ReverseFruit::OnCollision(){
    Scene::SceneInstance->MainSnake->Reverse();
    Scene::SceneInstance->Objects.removeOne(this);
    delete this;
}
