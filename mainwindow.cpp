#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(0));
    ui->setupUi(this);

    for(int i=0;i<11;i++)
        for(int j=0;j<6;j++)
            board[i][j].setXY(i,j);

    QList<int> listX,listY;
    listX << 0 << 0 << 0 << 0 << 1 << 1 << 9 << 9 << 10 << 10 << 10 << 10;
    listY << 0 << 1 << 4 << 5 << 0 << 5 << 0 << 5 <<  0 <<  1 <<  4 <<  5;
    for(int i=0;i<listX.size();i++)
        board[listX.at(i)][listY.at(i)].setOutside();

    QList<QPoint> points;
    for(int i=3;i<9;i+=2){
        board[i][5].setEndOfPlayer(0);
        points.push_back( QPoint(i,5) );
    }
    ends.insert(0,points);
    points.clear();
    for(int i=0;i<3;i++){
        board[10-i][3+i].setEndOfPlayer(1);
        points.push_back( QPoint(10-i,3+i) );
    }
    ends.insert(1,points);
    points.clear();
    for(int i=0;i<3;i++){
        board[8+i][i].setEndOfPlayer(2);
        points.push_back( QPoint(8+i,i) );
    }
    ends.insert(2,points);
    points.clear();
    for(int i=3;i<9;i+=2){
        board[i][0].setEndOfPlayer(3);
        points.push_back( QPoint(i,0) );
    }
    ends.insert(3,points);
    points.clear();
    for(int i=0;i<3;i++){
        board[2-i][i].setEndOfPlayer(4);
        points.push_back( QPoint(2-i,i) );
    }
    ends.insert(4,points);
    points.clear();
    for(int i=0;i<3;i++){
        board[i][3+i].setEndOfPlayer(5);
        points.push_back( QPoint(i,3+i) );
    }
    ends.insert(5,points);

    std::cout << std::endl;
    std::cout << std::endl;
    for(int j=0;j<6;j++){
        for(int i=0;i<11;i++){
            std::cout << board[i][j].draw().toStdString();
        }
        std::cout << std::endl;
    }

    resetScores();
    computeScores(QPoint(5,0),0);

    drawBoard();

    Board board;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::computeScores(QPoint p, int player)
{
    qDebug() << ends.value(player);
}

int MainWindow::computeScores(QPoint p1, QPoint p2)
{
    return 0;
}

void MainWindow::resetScores()
{
    for(int i=0;i<11;i++)
        for(int j=0;j<6;j++)
            board[i][j].setScore(0);

}

void MainWindow::drawBoard()
{
    double d = 200;
    QPointF A(0,0);
    QPointF B = A + d*QPointF(cos(0*M_PI/180),d*sin(0*M_PI/180));
    QPointF C = B + d*QPointF(cos(60*M_PI/180),sin(60*M_PI/180));
    QPointF D = C + d*QPointF(cos(120*M_PI/180),sin(120*M_PI/180));
    QPointF E = D + d*QPointF(cos(180*M_PI/180),sin(180*M_PI/180));
    QPointF F = E + d*QPointF(cos(240*M_PI/180),sin(240*M_PI/180));
    QGraphicsScene *scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    QPolygonF polygon;
    polygon << A << B << C << D << E << F;
    scene->addPolygon(polygon);
    scene->addLine(QLineF(A,D));
    scene->addLine(QLineF(B,E));
    scene->addLine(QLineF(C,F));
    QPointF A1 = (2*A+B)/3;
    QPointF A2 = (A+2*B)/3;
    QPointF B1 = (2*B+C)/3;
    QPointF B2 = (B+2*C)/3;
    QPointF C1 = (2*C+D)/3;
    QPointF C2 = (C+2*D)/3;
    QPointF D1 = (2*D+E)/3;
    QPointF D2 = (D+2*E)/3;
    QPointF E1 = (2*E+F)/3;
    QPointF E2 = (E+2*F)/3;
    QPointF F1 = (2*F+A)/3;
    QPointF F2 = (F+2*A)/3;
    scene->addLine(QLineF(A1,C2));
    scene->addLine(QLineF(A2,C1));
    scene->addLine(QLineF(B1,D2));
    scene->addLine(QLineF(B2,D1));
    scene->addLine(QLineF(C1,E2));
    scene->addLine(QLineF(C2,E1));
    scene->addLine(QLineF(D1,F2));
    scene->addLine(QLineF(D2,F1));
    scene->addLine(QLineF(E1,A2));
    scene->addLine(QLineF(E2,A1));
    scene->addLine(QLineF(F1,B2));
    scene->addLine(QLineF(F2,B1));
    scene->setSceneRect(F.x(),A.y(),C.x(),D.y());
}
