#include "board.h"

Board::Board()
{

    for(int i=0;i<54;i++){
        CaseTriangle *c = new CaseTriangle(i);
        cases[i] = c;
    }

    //TODO, case avec id=-1 pour les bords
    CaseTriangle *side = new CaseTriangle(-1);
    //Row 1
    cases[0]->setNeighbour( cases[3], cases[4] );
    cases[1]->setNeighbour( cases[4], cases[5] );
    cases[2]->setNeighbour( cases[5], cases[6] );
    cases[3]->setNeighbour( cases[0], cases[7] );
    cases[4]->setNeighbour( cases[0], cases[1], cases[8] );
    cases[5]->setNeighbour( cases[1], cases[2], cases[9] );
    cases[6]->setNeighbour( cases[2], cases[10] );
    //Row 2
    cases[7]->setNeighbour( cases[3], cases[11], cases[12] );
    cases[8]->setNeighbour( cases[4], cases[12], cases[13] );
    cases[9]->setNeighbour( cases[5], cases[13], cases[14] );
    cases[10]->setNeighbour( cases[6], cases[14], cases[15] );
    cases[11]->setNeighbour( cases[7], cases[16] );
    cases[12]->setNeighbour( cases[7], cases[8], cases[17] );
    cases[13]->setNeighbour( cases[8], cases[9], cases[18] );
    cases[14]->setNeighbour( cases[9], cases[10], cases[19] );
    cases[15]->setNeighbour( cases[10], cases[20] );
    //Row 3
    cases[16]->setNeighbour( cases[11], cases[21], cases[22] );
    cases[17]->setNeighbour( cases[12], cases[22], cases[23] );
    cases[18]->setNeighbour( cases[13], cases[23], cases[24] );
    cases[19]->setNeighbour( cases[14], cases[24], cases[25] );
    cases[20]->setNeighbour( cases[15], cases[25], cases[26] );
    cases[21]->setNeighbour( cases[16], cases[27] );
    cases[22]->setNeighbour( cases[16], cases[17], cases[28] );
    cases[23]->setNeighbour( cases[17], cases[18], cases[29] );
    cases[24]->setNeighbour( cases[18], cases[19], cases[30] );
    cases[25]->setNeighbour( cases[19], cases[20], cases[31] );
    cases[26]->setNeighbour( cases[20], cases[32] );
    //Row 4
    cases[27]->setNeighbour( cases[21], cases[33] );
    cases[28]->setNeighbour( cases[22], cases[33], cases[34] );
    cases[29]->setNeighbour( cases[23], cases[34], cases[35] );
    cases[30]->setNeighbour( cases[24], cases[35], cases[36] );
    cases[31]->setNeighbour( cases[25], cases[36], cases[37] );
    cases[32]->setNeighbour( cases[26], cases[37] );
    cases[33]->setNeighbour( cases[27], cases[28], cases[38] );
    cases[34]->setNeighbour( cases[28], cases[29], cases[39] );
    cases[35]->setNeighbour( cases[29], cases[30], cases[40] );
    cases[36]->setNeighbour( cases[30], cases[31], cases[41] );
    cases[37]->setNeighbour( cases[31], cases[32], cases[42] );
    //Row 5
    cases[38]->setNeighbour( cases[33], cases[43] );
    cases[39]->setNeighbour( cases[34], cases[43], cases[44] );
    cases[40]->setNeighbour( cases[35], cases[44], cases[45] );
    cases[41]->setNeighbour( cases[36], cases[45], cases[46] );
    cases[42]->setNeighbour( cases[37], cases[46] );
    cases[43]->setNeighbour( cases[38], cases[39], cases[47] );
    cases[44]->setNeighbour( cases[39], cases[40], cases[48] );
    cases[45]->setNeighbour( cases[40], cases[41], cases[49] );
    cases[46]->setNeighbour( cases[41], cases[42], cases[50] );
    //Row 6
    cases[47]->setNeighbour( cases[43], cases[51] );
    cases[48]->setNeighbour( cases[44], cases[51], cases[52] );
    cases[49]->setNeighbour( cases[45], cases[52], cases[53] );
    cases[50]->setNeighbour( cases[46], cases[53] );
    cases[51]->setNeighbour( cases[47], cases[48] );
    cases[52]->setNeighbour( cases[48], cases[49] );
    cases[53]->setNeighbour( cases[49], cases[50] );

    addWall(45,49);
    addWall(44,48);
    addWall(46,50);

    //Test
    getPath(1,0);
}

void Board::addWall(int id1, int id2)
{
    for(int i=0;i<54;i++)
        cases[i]->addWall(id1,id2);

}

int Board::getBestScore(int player)
{
    QList<int> c = ends(player);

    int min = cases[c.at(0)]->getScore();
    if(c.at(1)<min) min = cases[c.at(1)]->getScore();
    if(c.at(2)<min) min = cases[c.at(2)]->getScore();

    return min;
}

QList<int> Board::getPath(int id, int player)
{
    cases[id]->setScore(1);

    QList<int> e = ends(player);
    int min = getBestScore(player);

    int best = e.at(rand()%3);
    while(cases[best]->getScore()!=min){
        best = e.at(rand()%3);
    }
    qDebug() << "Goto " << best;

    CaseTriangle *n = cases[best];

    QList<int> path;
    while(n->getID()!=id){
        path.push_front( n->getID() );
        n = n->min();
    }
    qDebug() << path;

}

QList<int> Board::ends(int player)
{
    QList<int> list;
    switch(player){
    case 0: list << 51 << 52 << 53;
    case 1: list << 32 << 42 << 50;
    case 2: list << 6 << 15 << 26;
    case 3: list << 0 << 1 << 2;
    case 4: list << 3 << 11 << 21;
    case 5: list << 27 << 38 << 47;
    }
    return list;
}
