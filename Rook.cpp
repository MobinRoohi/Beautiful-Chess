#include "Rook.h"

Rook::Rook(string input1, int row1, int col1)
: Piece(input1, row1, col1) {}

Rook::~Rook() {}
bool Rook::validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board){
    if (srcRow == destRow) {
        int colOff = (destCol - srcCol > 0) ? 1 : -1;
        for (int j = srcCol + colOff; j !=  destCol; j = j + colOff){
            if (board[srcRow][j]->returnPiece() != "--"){
                return false;
            }
        }
        return true;
    }
    else if (destCol == srcCol){
        int rowOff = (destRow - srcRow > 0) ? 1 : -1;
        for (int i = srcRow + rowOff; i !=  destRow; i = i + rowOff){
            if (board[i][srcCol]->returnPiece() != "--"){
                return false;
            }
        }
        return true;
    }
    return false;
}