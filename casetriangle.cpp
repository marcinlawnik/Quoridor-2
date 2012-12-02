#include "casetriangle.h"

CaseTriangle::CaseTriangle(int id)
{
    id_ = id;
    score_ = 0;
}

int CaseTriangle::getID()
{
    return id_;
}

void CaseTriangle::setNeighbour(CaseTriangle *c1, CaseTriangle *c2)
{
    nbNeighbour = 2;
    n1 = c1;
    n2 = c2;
    n3 = new CaseTriangle(-1);
}
void CaseTriangle::setNeighbour(CaseTriangle *c1, CaseTriangle *c2, CaseTriangle *c3)
{
    nbNeighbour = 3;
    n1 = c1;
    n2 = c2;
    n3 = c3;
}

void CaseTriangle::computeScore()
{
    int score = 0;
    int s1 = n1->getScore();
    int s2 = n2->getScore();
    if(s1>0) score = s1;
    if(s2>0 && s2<score) score = s2;
    if(nbNeighbour==3){
        int s3 = n3->getScore();
        if(s3>0 && s3<score) score = s3;
    }
    score_ = score + 1;
}

void CaseTriangle::setScore(int score)
{
    score_ = score;
    int s1 = n1->getScore();
    int s2 = n2->getScore();
    int s3 = n3->getScore();
    if(n1->isValid() && (s1==0 || s1>score+1)) n1->setScore(score_+1);
    if(n2->isValid() && (s2==0 || s2>score+1)) n2->setScore(score_+1);
    if(n3->isValid() && (s3==0 || s3>score+1)) n3->setScore(score_+1);
}

int CaseTriangle::getScore()
{
    return score_;
}

void CaseTriangle::addWall(int id1, int id2)
{
    if(id_==id1){
        if(n1->getID()==id2)
            n1 = new CaseTriangle(-1);
        if(n2->getID()==id2)
            n2 = new CaseTriangle(-1);
        if(n3->getID()==id2)
            n3 = new CaseTriangle(-1);
    }
    if(id_==id2){
        if(n1->getID()==id1)
            n1 = new CaseTriangle(-1);
        if(n2->getID()==id1)
            n2 = new CaseTriangle(-1);
        if(n3->getID()==id1)
            n3 = new CaseTriangle(-1);
    }

}
