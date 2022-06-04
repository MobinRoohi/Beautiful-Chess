#ifndef BEAUTIFULCHESS_EMPTY_H
#define BEAUTIFULCHESS_EMPTY_H
#include "Piece.h"

class Empty : public Piece{
public:
    Empty(string input1, int row1, int col1);
    ~Empty();
    bool validation(int, int, int, int, vector<vector<Piece*>>);
};

#endif //BEAUTIFULCHESS_EMPTY_H
