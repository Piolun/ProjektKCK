#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scene.h"


#include "QList"
#include "QVector"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("UKŁADACZ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString output = "";
    QString input = ui->textEdit->toPlainText();
    QStringList inputL = input.split(" ");

    Scene::SceneInstance->inputI.clear();
    Scene::SceneInstance->PotentialObjects.clear();
    Scene::SceneInstance->ScriptObjects.clear();
    Scene::SceneInstance->TempObjects = Scene::SceneInstance->Objects;

    output += input;
    output += "\n" + inputL.join(" - ");
    output += "\n";

    Order* uid = new Order("unid");


    for (int i=0; i<inputL.size(); i++){
        bool x=0;
        foreach(word* w, Scene::SceneInstance->Dictionary){
            for(int y=0; y < w->names.size() && x==0; y++){ //x zapobiega zinterpretowania jednego wyrazu jako kilku, wybiera (?!) ten który jest pierwszy w słowniku!
                if (inputL[i].contains(w->names[y], Qt::CaseInsensitive)){
                    output += w->names[0] + " ";
                    Scene::SceneInstance->inputI.append(w);
                    x=1;
                } else {

                }
            }
        }
        if (x==0) {
            output += uid->names[0] + " ";
            Scene::SceneInstance->inputI.append(static_cast<word*>(uid));
        }
        output += "- ";
    }


    int y = 0;

    for (int i = 0; i < Scene::SceneInstance->inputI.size(); i++) {
        if (Scene::SceneInstance->inputI[i]->nazwaklasy() == "figura" || Scene::SceneInstance->inputI[i]->nazwaklasy() == "kolor") {
            y++;

            if ((i == Scene::SceneInstance->inputI.size()-1) && y > 0){

                for (int x = 0; x < y; x++){
                    foreach (Object* o, Scene::SceneInstance->TempObjects){
                        if (((o->fname == Scene::SceneInstance->inputI[i-x]->names[0]) ||(o->cname == Scene::SceneInstance->inputI[i-x]->names[0])) == 0){
                            Scene::SceneInstance->TempObjects.removeAll(o);
                        }
                    }
                }

                if (Scene::SceneInstance->TempObjects.size() == 0){
                    for (y; y > 0; y--){
                        Scene::SceneInstance->PotentialObjects.append(Scene::SceneInstance->inputI[i-y+1]); // [i-z]
                    }
                    Scene::SceneInstance->TempObjects = Scene::SceneInstance->Objects;

                } else if (Scene::SceneInstance->TempObjects.size() == 1){
                    for (y; y > 0; y--)
                        Scene::SceneInstance->ScriptObjects = Scene::SceneInstance->TempObjects; // [i-z]
                }
                Scene::SceneInstance->TempObjects = Scene::SceneInstance->Objects;
            }

        } else {

            for (int x = 0; x < y; x++){
                foreach (Object* o, Scene::SceneInstance->TempObjects){
                    if (((o->fname == Scene::SceneInstance->inputI[i-x-1]->names[0]) ||(o->cname == Scene::SceneInstance->inputI[i-x-1]->names[0])) == 0){
                        Scene::SceneInstance->TempObjects.removeAll(o);
                    }
                }
            }

            if (Scene::SceneInstance->TempObjects.size() == 0){
                for (y; y > 0; y--){
                    Scene::SceneInstance->PotentialObjects.append(Scene::SceneInstance->inputI[i-y+1]); // [i-z]
                }
                Scene::SceneInstance->TempObjects = Scene::SceneInstance->Objects;

            } else if (Scene::SceneInstance->TempObjects.size() == 1){
                for (y; y > 0; y--)
                    Scene::SceneInstance->ScriptObjects = Scene::SceneInstance->TempObjects; // [i-z]
            }
            Scene::SceneInstance->TempObjects = Scene::SceneInstance->Objects;
        }

    }



    //    foreach(word* w, Scene::SceneInstance->inputI){
    //        QString CurrentIinput = w->nazwaklasy();

    //        if((LastIinput != "figura" || LastIinput == "kolor") && (CurrentIinput == "kolor" || CurrentIinput == "kolor"))

    //    }


    //    foreach(word* w, Scene::SceneInstance->inputI) {

    //    }

    //    if (Scene::SceneInstance->TempObjects.size() == 1){
    //        Scene::SceneInstance->OrderObjects.append((Scene::SceneInstance->TempObjects[0]));
    //    }



    if(Scene::SceneInstance->ScriptObjects.size() == 1){
        Scene::SceneInstance->pointer = Scene::SceneInstance->ScriptObjects[0]->position[0];
        if (input.contains("połóż") && Scene::SceneInstance->PotentialObjects.size() == 2 ){
            word* potential1 = Scene::SceneInstance->PotentialObjects[0];
            word* potential2 = Scene::SceneInstance->PotentialObjects[1];

            if (potential1->nazwaklasy() == "figura" && potential2->nazwaklasy() == "kolor"){
                Object* tempo = new Object(potential1->names[0],potential2->names[0],0,0);
                QPoint tempp = Scene::SceneInstance->ScriptObjects[0]->Topcenter[0] - tempo->Bottomcenter[0];
                new Object (potential1->names[0],potential2->names[0], tempp.x(), tempp.y());
                delete tempo;

            }else if (potential2->nazwaklasy() == "figura" && potential1->nazwaklasy() == "kolor"){
                Object* tempo = new Object(potential2->names[0],potential1->names[0],0,0);
                QPoint tempp = Scene::SceneInstance->ScriptObjects[0]->Topcenter[0] - tempo->Bottomcenter[0];
                new Object (potential2->names[0],potential1->names[0], tempp.x(), tempp.y());
                delete tempo;
            }
        }
    }

    //połóż żółty kwadrat na zielony kwadrat

    //połóż zielony trapez na żółty prostokąt

    //czerwony wymaga "kwadrat czerwony" a "czerwony kwadrat" nie działa (???)



    if (input.contains("usuń")){
        if (Scene::SceneInstance->ScriptObjects.size()==1){
            Scene::SceneInstance->Objects.removeOne(Scene::SceneInstance->ScriptObjects[0]);
        }
    }


    output += "\n\nDEBUG:" ;
    output += "\n\nSłownik:";

    foreach(word* w, Scene::SceneInstance->Dictionary){
        int c = w->names.size();
        for (int y = 0; y < c; y++) {
            output += "\n" + w->names[y];
        }
    }

    output += "\n\ninput po słownikowaniu:\n";

    foreach(word* w, Scene::SceneInstance->inputI){
        output += " - " + w->names[0];
    }

    output += "\n\nLista Obiektów:";

    foreach(Object* o, Scene::SceneInstance->Objects){
        output += "\n" + o->fname + " " + o->cname + " :( " + QString::number(o->xMax) + " " + QString::number(o->xMin) + " " + QString::number(o->yMax) + " " + QString::number(o->yMin) + " )";
    }

    output += "\n\nTempLista Obiektów:";
    foreach(Object* o, Scene::SceneInstance->TempObjects){
        output += "\n" + o->fname + " " + o->cname + " :( " + QString::number(o->xMax) + " " + QString::number(o->xMin) + " " + QString::number(o->yMax) + " " + QString::number(o->yMin) + " )";
    }

    output += "\n\nScriptObjects:";
    foreach(Object* o, Scene::SceneInstance->ScriptObjects){
        output += "\n" + o->fname + " " + o->cname + " :( " + QString::number(o->xMax) + " " + QString::number(o->xMin) + " " + QString::number(o->yMax) + " " + QString::number(o->yMin) + " )";
    }

    output += "\n\nPotentialObjects:";
    foreach(word* w, Scene::SceneInstance->PotentialObjects){
        output += "\n" + w->names[0];
    }

    ui->textBrowser->setText(output);
    output = "";
    ui->textEdit->setText("");





    Scene::SceneInstance->repaint();
}


