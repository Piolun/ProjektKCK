#ifndef SCENE_H
#define SCENE_H
#include <QList>
#include <QWidget>
#include <QPainter>
#include "drawable.h"
#include "color.h"
#include "object.h"



class Scene:public QWidget
{
Q_OBJECT
public:
    Scene(QWidget* parent = 0, Qt::WindowFlags f = 0);

    static Scene* SceneInstance;

    //color* Zielony;


    QList<Object*> Objects;
    QList<word*> Dictionary;
    void CheckAllCollisions();

    void Repaint();
private:
    int height;
    int width;
protected:
    void paintEvent(QPaintEvent* paintEvent);
};

#endif // SCENE_H
