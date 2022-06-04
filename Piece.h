#ifndef BEAUTIFULCHESS_PIECE_H
#define BEAUTIFULCHESS_PIECE_H
#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;

class Piece{
protected:
    char pieceType;
    char pieceColor;
    int row;
    int col;
public:
    Piece(string input, int row, int col);
    string returnPiece();
    bool move(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> &board);
    bool legalMove(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board);

    virtual bool validation(int, int, int, int, vector<vector<Piece*>>) = 0;

    friend void Board::getBoard();
};
#endif //BEAUTIFULCHESS_PIECE_H
