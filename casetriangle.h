#ifndef CASETRIANGLE_H
#define CASETRIANGLE_H

class CaseTriangle
{
public:
    CaseTriangle(int id);
    void setNeighbour(CaseTriangle* c1, CaseTriangle *c2);
    void setNeighbour(CaseTriangle* c1, CaseTriangle *c2, CaseTriangle *c3);
    void computeScore();

    bool isValid() { return id_>=0?true:false;}

    int getID();
    int getScore();
    void setScore(int score);

    void addWall(int id1, int id2);

private:
    int id_;
    CaseTriangle *n1,*n2,*n3;
    int nbNeighbour;
    int score_;
};

#endif // CASETRIANGLE_H
