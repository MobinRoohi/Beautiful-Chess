#ifndef BEAUTIFULCHESS_KNIGHT_H
#define BEAUTIFULCHESS_KNIGHT_H
#include "Piece.h"

class Knight: public Piece{
public:
    Knight(string input1, int row1, int col1);
    ~Knight();
    bool validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board);
};
#endif //BEAUTIFULCHESS_KNIGHT_H
