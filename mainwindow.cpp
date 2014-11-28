#include "mainwindow.h"
#include "ui_mainwindow.h"

QString output = "Standardowy output Kappa";


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
    QString input = ui->textEdit->toPlainText();



    QString myString("Ala ma kota");
    QStringList myStringList = myString.split(" ");

    output = myStringList.join(" - ")  + "\n" + QString::number(myStringList.size()) + "\n" + input;


    int pozycja = myStringList.indexOf(input);
    if (pozycja !=-1){
    output = output + "\n" + myStringList.at(pozycja) + " na pozycji numer " + QString::number(pozycja) + ".\n";
    }

    ui->textBrowser->setText(output);
    ui->textEdit->setText("");



    Scene::SceneInstance->repaint();
}


