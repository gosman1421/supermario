#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QDialog>
#include "game.h"
namespace Ui {
class welcomewindow;
}

class welcomewindow : public QDialog
{
    Q_OBJECT

public:
    explicit welcomewindow(QWidget *parent = nullptr);
    ~welcomewindow();

private slots:
    void on_pushButtonPLAY_clicked();
    void on_pushButtonQUIT_clicked();

private:
    Ui::welcomewindow *ui;
    Game *game;  // Declare a persistent Game object
};
#endif
