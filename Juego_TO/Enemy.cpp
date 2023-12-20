#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    daño=false;
        // Configurar la posición x aleatoria
        int random_number = rand() % 700;
    setPos(random_number, 0);

    // Elegir una imagen diferente según un número aleatorio
    int imageNumber = rand() % 20; // Números entre 0 y 4
    qDebug() << "arriba del switch" << alternativaB;
    // Utilizar diferentes imágenes según el número aleatorio
    switch (imageNumber) {

    case 0:
        if(alternativaA == false){
            setPixmap(QPixmap(":/images/estrellaA.png"));
            alternativaA = true;
            daño=true;
        }
        qDebug() << "A:" << alternativaA;
        break;
    case 1:
        if(alternativaB == false){
            setPixmap(QPixmap(":/images/estrellaB.png"));
            alternativaB = true;
            daño=true;
        }
        qDebug() << "B:" << alternativaB;
        break;
    case 2:
        if(alternativaC == false){
            setPixmap(QPixmap(":/images/estrellaC.png"));
            alternativaC = true;
            daño=true;
        }
        qDebug() << "C:" << alternativaC;
        break;
    case 3:
        if(alternativaD == false){
            setPixmap(QPixmap(":/images/estrellaD.png"));
            alternativaD = true;
            daño=true;
        }
        qDebug() << "D:" << alternativaD;
        break;
    case 4:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 5:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 6:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 7:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 8:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 9:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 10:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 11:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 12:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 13:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 14:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 15:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 16:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 17:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 18:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 19:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    case 20:
        setPixmap(QPixmap(":/images/asteroid2.png"));
        break;
    }

    // Establecer el punto de origen para transformaciones
    setTransformOriginPoint(50, 50);

    // Conectar el temporizador para invocar move() del enemigo periódicamente
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Iniciar el temporizador
    timer->start(50);  // El enemigo se moverá cada 50 milisegundos
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen

    // Si el enemigo es un asteroide y se sale de la pantalla, disminuye la salud
    if (pos().y() > 600) {
        game->health->decrease(daño);
            scene()->removeItem(this);
        delete this;

    }
}
