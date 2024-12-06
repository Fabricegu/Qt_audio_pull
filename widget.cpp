#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString chemin = QFileDialog::getOpenFileName(nullptr,"Chemin vers le fichier");
    qDebug()<<chemin;
    QFileInfo fi(chemin);
    qint64 taille = fi.size();
    qDebug()<<taille;

    QFile fichierSon(chemin);
       if (fichierSon.open(QIODevice::ReadOnly)){
           qDebug()<<"c'est bon";
           data = fichierSon.readAll();
           qDebug()<<data.size();
           QByteArray head = data;
           head.truncate(headerSize);
           qDebug()<<head[0];
           qDebug()<<head[1];
           qDebug()<<head[2];
           qDebug()<<head[3];
           data.remove(0, headerSize );
           if (data.isEmpty()) {
               qDebug()<<"rien a dire dsur la partie raw";
           }

            qDebug()<<"taille du raw = "<<data.size();
           /*
           QFile fichierTest("test.raw");
           if (fichierTest.open(QIODevice::WriteOnly)){
               qDebug()<<"bon pour ecriture";
               //data.remove(0, 31*16384);
               //QByteArray data2 = data.left(5*16384);
               //data = data2;
               fichierTest.write(data);
               fichierTest.close();
           }
            */
       }

      qDebug()<<"taille des datas"<<data.size();
    if (data.isEmpty()) {
        qDebug()<<"rien a dire";
    }
    AudioOut monSon(data);
}

