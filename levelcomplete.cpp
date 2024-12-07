#include "levelcomplete.h"
#include "ui_levelcomplete.h"
#include "QMessageBox"

levelcomplete::levelcomplete(int x, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::levelcomplete), game(nullptr)
{
    ui->setupUi(this);
    h =x;
}

levelcomplete::~levelcomplete()
{
    delete ui;
    if (game) delete game;
}

void levelcomplete::on_pushButton_clicked()
{
    if(!game){
        game = new Game(3, h);
        game->startGame();
    }
    this->hide();
}


void levelcomplete::on_pushButton_2_clicked()
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

