// MyRect.cpp
#include "MyRect.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0) // Se agrega un limite a la pantalla izquierda para la nave
            setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right){
        // Se agrega un limite a la pantalla derecha para la nave
        if(pos().x() + 100 < 800)
            setPos(x()+10,y());
    }

    else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void MyRect::spawn(){
    // Crea un enemigo
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
