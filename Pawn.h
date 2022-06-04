#ifndef BEAUTIFULCHESS_PAWN_H
#define BEAUTIFULCHESS_PAWN_H
#include "Piece.h"

class Pawn : public Piece{
public:
    Pawn(string input1, int row1, int col1);
    ~Pawn();
    bool validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board);
};
#endif //BEAUTIFULCHESS_PAWN_H
