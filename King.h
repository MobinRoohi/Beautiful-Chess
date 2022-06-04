#ifndef BEAUTIFULCHESS_KING_H
#define BEAUTIFULCHESS_KING_H
#include <iostream>
#include <vector>
#include "Piece.h"

class King: public Piece{
public:
    King(string input1, int row1, int col1);
    ~King();
    bool validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board);
};
#endif //BEAUTIFULCHESS_KING_H
