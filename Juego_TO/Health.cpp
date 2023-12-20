#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Inicializa la puntuación a 0
    health = 3;

    // Dibuja el textp
    setPlainText(QString("Health: ") + QString::number(health)); // Salud: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Salud: 2
}

int Health::getHealth(){
    return health;
}
