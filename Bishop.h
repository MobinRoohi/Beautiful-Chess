#ifndef BEAUTIFULCHESS_BISHOP_H
#define BEAUTIFULCHESS_BISHOP_H
#include "Piece.h"

class Bishop : public Piece{
public:
    Bishop(string input1, int row1, int col1);
    ~Bishop();
    bool validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board);
};

#endif //BEAUTIFULCHESS_BISHOP_H
