#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
class Score : public QGraphicsTextItem{
public:
    Score(int s, QGraphicsItem * parent = 0);
    void increasescore();
    void decrementscore();
    int getscore();
    void resetscore();
private:
    int score;
};

#endif // SCORE_H
