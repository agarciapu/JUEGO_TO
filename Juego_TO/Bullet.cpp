#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game;


Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/bala3.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // si la bala colisiona con un enemigo se destruyen ambos
    QList<QGraphicsItem*> itemsEnColision = collidingItems(); // Devuelve lista de elementos Q que estan colisionando
    for (int i = 0, n = itemsEnColision.size(); i < n; ++i) {
        if(typeid(*(itemsEnColision[i])) == typeid(Enemy)){
            //incrementa el puntaje
            game->score->increase();

            // Remueve entonces ambos
            scene()->removeItem(itemsEnColision[i]);
            scene()->removeItem(this);

            // Elimina entonces ambos
            delete itemsEnColision[i];
            delete this;
            return; // Para que no se presente errores
        }
    }

    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
