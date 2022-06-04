#ifndef BEAUTIFULCHESS_BOARD_H
#define BEAUTIFULCHESS_BOARD_H
#include <iostream>
#include <vector>


using namespace std;

class Piece;

class Board{
protected:
    vector<vector<Piece*>> board;
    bool WHITES_TURN;
public:
    Board();
    void getBoard();
    friend Piece;
    void printBoard();
    bool makeMove(int srcRow, int srcCol, int destRow, int destCol);
    bool check(bool);
    bool checkmate(char);
    bool returnTurn();

};

#endif
