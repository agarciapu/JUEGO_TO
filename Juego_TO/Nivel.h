#ifndef NIVEL_H
#define NIVEL_H
#include <QGraphicsTextItem>

class Nivel: public QGraphicsTextItem{
public:
    Nivel(QGraphicsItem * parent=0);
    void aumentar();
    int getNivel();
private:
    int nivel;
};

#endif



