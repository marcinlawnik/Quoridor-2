#ifndef CASETRIANGLE_H
#define CASETRIANGLE_H
#include <QList>
#include <QMap>
#include <assert.h>


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

    CaseTriangle* min();

    int minList(QList<int> list){
        if(list.size()==0) return 0.0;
        int min = list.at(0);
        for(int i=1;i<list.size();i++)
            if(list.at(i)<min) min = list.at(i);
        return min;
    }

private:
    int id_;
    CaseTriangle *n1,*n2,*n3;
    int score_;
};

#endif // CASETRIANGLE_H
