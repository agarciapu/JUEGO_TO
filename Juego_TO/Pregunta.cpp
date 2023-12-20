#include "Pregunta.h"
#include <QFont>

Pregunta::Pregunta(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Inicializa el nivel en 1
    pregunta = "Qué es la encapsulación en programación orientada a objetos? \n A. Un proceso de herencia \n B.  Ocultar la implementación interna y permitir el acceso controlado \n C. Utilizar interfaces \n D. Crear instancias de objetos ";

    // Dibuja el textp
    setPlainText("Pregunta: "+ pregunta);
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",13));
}

void Pregunta::cambiar() {
    pregunta = "¿Qué es la herencia en programación orientada a objetos?";
    setPlainText("Nivel: " + pregunta);
}

QString Pregunta::getPregunta(){
    return pregunta;
}
