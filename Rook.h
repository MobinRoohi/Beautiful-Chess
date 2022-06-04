#ifndef BEAUTIFULCHESS_ROOK_H
#define BEAUTIFULCHESS_ROOK_H
#include "Piece.h"

class Rook: public Piece{
public:
    Rook(string input1, int row1, int col1);
    ~Rook();
    bool validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board);
};
#endif //BEAUTIFULCHESS_ROOK_H
