#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board.h"

#include <iostream>
#include <QMap>
#include <QList>
#include <QPoint>
#include <QDebug>
#include <QTime>
#include <math.h>

class Case{
public:
    Case(){
        outside_ = false;
        endOfPlayer_ = -1;
        canGoUp_ =  canGoDown_ = canGoLeft_ = canGoRight = true;
    }
    void setScore(int score) {score_ = score;}
    void setOutside(){outside_=true;}
    void setXY(int x, int y){ x_=x; y_ = y;}
    void setEndOfPlayer(int player){ endOfPlayer_ = player;}
    bool isOutside(){ return outside_;}
    int getScore(){ return score_;}

    QString draw(){
        if(outside_) return "#";
        if(endOfPlayer_>=0) return QString::number(endOfPlayer_);
        return " ";
    }

private:
    bool canGoUp_, canGoDown_, canGoLeft_, canGoRight;
    int endOfPlayer_;
    int id_;
    int x_;
    int y_;
    int score_;
    bool outside_;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void computeScores(QPoint p, int player);
    int computeScores(QPoint p1, QPoint p2);
    void resetScores();

    void drawBoard();

private:
    Ui::MainWindow *ui;
    Case board[11][6];
    QMap<int,QList<QPoint> > ends;

};

#endif // MAINWINDOW_H
