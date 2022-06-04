#include "Bishop.h"

Bishop::Bishop(string input1, int row1, int col1)
: Piece(input1, row1, col1) {
}
Bishop::~Bishop() {}
bool Bishop::validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board){
    if ((destCol - srcCol == destRow - srcRow) || (destCol - srcCol == srcRow - destRow)){
        int rowOff = (destRow - srcRow > 0) ? 1 : -1;
        int colOff = (destCol - srcCol > 0) ? 1 : -1;
        int i, j;
        for (i = srcRow + rowOff, j = srcCol + colOff; i != destRow;
             i = i + rowOff, j = j + colOff){
            if (board[i][j]->returnPiece() != "--"){
                return false;
            }
        }
        return true;
    }
    return false;
}