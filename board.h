#ifndef BOARD_H
#define BOARD_H

#include <casetriangle.h>
#include <QDebug>

class Board
{
public:
    Board();
    void addWall(int id1, int id2);
    int getBestScore(int id, int player);

private:
    CaseTriangle *cases[54];
};

#endif // BOARD_H
