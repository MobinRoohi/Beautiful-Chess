#ifndef BEAUTIFULCHESS_BOARD_H
#define BEAUTIFULCHESS_BOARD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


using namespace std;
using namespace sf;

class Piece;
class Cell;

class Board{
protected:
    vector<vector<Piece*>> board;
    vector<vector<Cell*>> boardSFML;
    bool WHITES_TURN;
    bool CHECK_MATE;
    char winner;
    float cellSize;
    float windowSizeWidth;
    float windowSizeHeight;
public:
    Board();
    void getBoard();
    friend Piece;
    void printBoard();
    bool makeMove(int srcRow, int srcCol, int destRow, int destCol);
    bool check(bool);
    bool checkmate(char);
    bool returnTurn();
    void run();
    void drawCell(Cell *cell, RenderWindow &window);

};

#endif
