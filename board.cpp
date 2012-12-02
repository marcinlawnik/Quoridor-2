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
    cases[1]->setScore(1);

    for(int i=0;i<54;i++)
        qDebug() << i << cases[i]->getScore();
}

void Board::addWall(int id1, int id2)
{
    for(int i=0;i<54;i++)
        cases[i]->addWall(id1,id2);

}

int Board::getBestScore(int id, int player)
{
    cases[id]->setScore(1);
    if(player==0){
        return min( cases[51]->getScore(), min( cases[52]->getScore(), cases[53]->getScore() ));
    }
    if(player==1){
        return min( cases[32]->getScore(), min( cases[42]->getScore(), cases[50]->getScore() ));
    }
    if(player==2){
        return min( cases[6]->getScore(), min( cases[15]->getScore(), cases[26]->getScore() ));
    }
    if(player==3){
        return min( cases[0]->getScore(), min( cases[1]->getScore(), cases[2]->getScore() ));
    }
    if(player==4){
        return min( cases[3]->getScore(), min( cases[11]->getScore(), cases[21]->getScore() ));
    }
    if(player==5){
        return min( cases[27]->getScore(), min( cases[38]->getScore(), cases[47]->getScore() ));
    }
}
