#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "game.h"
#include <QMessageBox>


welcomewindow::welcomewindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::welcomewindow)
    , game(nullptr)  // Initialize the game pointer to nullptr
{
    ui->setupUi(this);
}

welcomewindow::~welcomewindow() {
    delete ui;
    if (game) delete game;  // Clean up Game object
}

void welcomewindow::on_pushButtonPLAY_clicked() {
    if (!game) {
        game = new Game(3, 1, 0);  // Instantiate Game only when needed
    }
    game->startGame();

    this->hide();  // Hide welcome window when game starts
}
void welcomewindow::on_pushButtonQUIT_clicked()
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
