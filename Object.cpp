#include "Object.h"
#include "figure.h"
#include "scene.h"

Object::Object(QString a, QString b, int posX, int posY )
{

    Figure* figure;
    Color* d;


    foreach(word* w, Scene::SceneInstance->Dictionary){

        for (int i=0; i< w->names.size(); i++){
            if(b.contains(w->names[i])){
                d = static_cast<Color*>(w);
            }
        }

        for (int i=0; i< w->names.size(); i++){
            if(a.contains(w->names[i])){
                figure = static_cast<Figure*>(w);
            }
        }

    }

    fname = figure->names[0];
    cname = d->names[0];

    position = figure->polygon;
    position.translate(posX, posY);
    color = d;



    foreach (QPoint p, position) {

        xMin = qMin(xMin, p.x());
        xMax = qMax(xMax, p.x());
        yMin = qMin(yMin, p.y());
        yMax = qMax(yMax, p.y());

        if (Bottomcenter.empty() || p.y() == Bottomcenter[0].y()){
            Bottomcenter.append(p);
        } else if (p.y() > Bottomcenter[0].y()){
            Bottomcenter.clear();
            Bottomcenter.append(p);
        }

        if (Topcenter.empty() || p.y() == Topcenter[0].y()){
            Topcenter.append(p);
        } else if (p.y() < Topcenter[0].y()){
            Topcenter.clear();
            Topcenter.append(p);
        }
    }


    for (int i = 1; i <= Bottomcenter.size()-1; i++){
        Bottomcenter[0].rx() += Bottomcenter[i].x();
    }

    Bottomcenter[0].rx() = Bottomcenter[0].rx() /  Bottomcenter.size();


    for (int i = 1; i <= Topcenter.size()-1; i++){
        Topcenter[0].rx() += Topcenter[i].x();
    }

    Topcenter[0].rx() = Topcenter[0].rx() /  Topcenter.size();


    while (Bottomcenter.size() > 1){
        Bottomcenter.removeLast();
    }


    while (Topcenter.size() > 1){
        Topcenter.removeLast();
    }


    Scene::SceneInstance->Objects.append(this);

}

Object::~Object()
{
    Scene::SceneInstance->Objects.removeOne(this);
}
