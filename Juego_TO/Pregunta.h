#ifndef PREGUNTA_H
#define PREGUNTA_H
#include <QGraphicsTextItem>
#include <qstring.h>

class Pregunta: public QGraphicsTextItem{
public:
    Pregunta(QGraphicsItem * parent=0);
    void cambiar();
    QString getPregunta();
private:
    QString pregunta;
};

#endif










