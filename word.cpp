#include "word.h"
#include "scene.h"

word::word(QString a)
{
//    this->names = a.split(" ");



    names = a.split(" ");

    names.replaceInStrings("_"," ");

    Scene::SceneInstance->Dictionary.append(this);

}

word::~word(){
    Scene::SceneInstance->Dictionary.removeOne(this); //w razie usuwania wyrazów podczas trwania programu
}
