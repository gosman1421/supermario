#ifndef LEVELCOMPLETE_H
#define LEVELCOMPLETE_H
#include "game.h"

#include <QDialog>

namespace Ui {
class levelcomplete;
}

class levelcomplete : public QDialog
{
    Q_OBJECT

public:
    explicit levelcomplete(int x, int y, QWidget *parent = nullptr);
    ~levelcomplete();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::levelcomplete *ui;
    Game *game;
    int h;
    int u;
};

#endif // LEVELCOMPLETE_H
