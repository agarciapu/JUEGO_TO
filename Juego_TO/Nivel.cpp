#include "Nivel.h"
#include <QFont>

Nivel::Nivel(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Inicializa el nivel en 1
    nivel = 1;

    // Dibuja el textp
    setPlainText(QString("Nivel: ") + QString::number(nivel));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",18));
}

void Nivel::aumentar(){
    nivel++;
    setPlainText(QString("Nivel: ") + QString::number(nivel));
}

int Nivel::getNivel(){
    return nivel;
}
