#include "Empty.h"

Empty::Empty(string input1, int row1, int col1) :
Piece(input1, row1, col1) {}

Empty::~Empty(){}

bool Empty::validation(int, int, int, int, vector<vector<Piece*>>){
    return false;
}