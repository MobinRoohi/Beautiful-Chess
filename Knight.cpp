#include "Knight.h"

Knight::Knight(string input1, int row1, int col1) :
Piece(input1, row1, col1) {}
Knight::~Knight() {}
bool Knight::validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board){
    if ((srcCol == destCol + 1) || (srcCol == destCol - 1)){
        if ((srcRow == destRow + 2) || (srcRow == destRow - 2)){
            return true;
        }
    }
    if ((srcCol == destCol + 2) || (srcCol == destCol - 2)){
        if ((srcRow == destRow + 1) || (srcRow == destRow - 1)){
            return true;
        }
    }
    return false;
}