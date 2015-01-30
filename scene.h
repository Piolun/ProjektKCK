#ifndef SCENE_H
#define SCENE_H
#include <QList>
#include <QWidget>
#include <QPainter>
#include "Color.h"
#include "object.h"
#include "order.h"



class Scene:public QWidget
{
Q_OBJECT
public:
    Scene(QWidget* parent = 0, Qt::WindowFlags f = 0);

    static Scene* SceneInstance;

    //Color* Zielony;


    QList<Object*> Objects;
    QList<Object*> TempObjects;
    QList<Object*> ScriptObjects;
    QList<word*> PotentialObjects;
    QList<word*> Dictionary;
    QList<word*> inputI;

    Order* uid;

    QPoint pointer;

    void Repaint();
private:
    int height;
    int width;
protected:
    void paintEvent(QPaintEvent* paintEvent);
};

#endif // SCENE_H
