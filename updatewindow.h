#ifndef UPDATEWINDOW_H
#define UPDATEWINDOW_H
#include "game.h"

#include <QDialog>

namespace Ui {
class updatewindow;
}

class updatewindow : public QDialog
{
    Q_OBJECT

public:
    explicit updatewindow(int m,int l, QWidget *parent = nullptr);
    ~updatewindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::updatewindow *ui;
    Game *game;
    int mas;
    int lev;
};

#endif // UPDATEWINDOW_H
