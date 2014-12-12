#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Już nie nakurwianie węgorza");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString output = "";
    //Standardowy output Kappa

    QString input = ui->textEdit->toPlainText();


/*
    QString myString("Ala ma kota");
    QStringList myStringList = myString.split(" ");


    output = myStringList.join(" - ")  + "\n" + QString::number(myStringList.size()) + "\n" + input;


    int pozycja = myStringList.indexOf(input);
    if (pozycja !=-1){
    output = output + "\n" + myStringList.at(pozycja) + " na pozycji numer " + QString::number(pozycja) + ".\n";
    }
*/



     foreach(word* o, Scene::SceneInstance->Dictionary){
        int c = o->names.size();
        for (int y = 0; y < c; y++){
        output = output + "\n " + o->names[y];
            if(input == o->names[y]){
                output = output + "<------ o to ten tutaj! " + input + " !";
            }  else if (input == "IDDQD") {
                Color* zolty = new Color (255,255,0,"zolty");
                input = "";
            }
        }
    }




    ui->textBrowser->setText(output);
    output = "";
    ui->textEdit->setText("");





    Scene::SceneInstance->repaint();
}


