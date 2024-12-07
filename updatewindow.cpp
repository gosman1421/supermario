#include "updatewindow.h"
#include "ui_updatewindow.h"
#include "game.h"
#include "QMessageBox"
#include "welcomewindow.h"
updatewindow::updatewindow(int m, int l, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::updatewindow)
    , game(nullptr)
{
    ui->setupUi(this);
    mas= m;
    lev= l;
}

updatewindow::~updatewindow()
{
    delete ui;
    if (game) delete game;
}
void updatewindow::on_pushButton_clicked()
    {

        if(!game){
            game = new Game(mas, lev);
            game->startGame();
        }


        this->hide();  // Hide welcome window when game starts
    }

void updatewindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Quit Game",
        "Are you sure you want to quit?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        QApplication::quit();  // Exit the application
    } else {

        qDebug() << "Quit canceled.";
    }
}



