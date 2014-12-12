#include "word.h"
#include "scene.h"

word::word(QString a)
{
    this->names = a.split(" ");
    //QStringList names = a.split(" ");

    Scene::SceneInstance->Dictionary.append(this);

}
