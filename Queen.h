#ifndef BEAUTIFULCHESS_QUEEN_H
#define BEAUTIFULCHESS_QUEEN_H
#include <iostream>
#include <vector>
#include "Piece.h"

class Queen: public Piece {
public:
    Queen(string input1, int row1, int col1);
    ~Queen();
    bool validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board);
};
#endif //BEAUTIFULCHESS_QUEEN_H
