#ifndef MENUINICIAL_H
#define MENUINICIAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MenuInicial;
}
QT_END_NAMESPACE

class MenuInicial : public QMainWindow
{
    Q_OBJECT

public:
    MenuInicial(QWidget *parent = nullptr);
    ~MenuInicial();
 void comenzarJuego();
private:
    Ui::MenuInicial *ui;
};
#endif // MENUINICIAL_H





