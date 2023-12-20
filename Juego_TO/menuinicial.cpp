#include "menuinicial.h"
#include "./ui_menuinicial.h"
#include "Game.h"
Game * game;

MenuInicial::MenuInicial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuInicial)
{
    ui->setupUi(this);



     connect(ui->Button_iniciar, &QPushButton::clicked, this, &MenuInicial::comenzarJuego);
}

MenuInicial::~MenuInicial()
{
    delete ui;
}
void MenuInicial::comenzarJuego() {
    game = new Game();
    game->show();

}
