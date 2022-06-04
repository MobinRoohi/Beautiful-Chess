#include "Queen.h"

Queen::Queen(string input1, int row1, int col1)
: Piece(input1, row1, col1) {}

Queen::~Queen() {}

bool Queen::validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board){
    if (srcRow == destRow){
        int colOff = (destCol - srcCol > 0) ? 1 : -1;
        for (int i = srcCol + colOff; i != destCol; i += colOff){
            if (board[srcRow][i]->returnPiece() != "--"){
                return false;
            }
        }
        return true;
    }
    else if (destCol == srcCol){
        int rowOff = (destRow - srcRow > 0) ? 1 : -1;
        for (int i = srcRow + rowOff; i != destRow; i += rowOff){
            if (board[i][srcCol]->returnPiece() != "--"){
                return false;
            }
        }
        return true;
    }
    else if ((destCol - srcCol == destRow - srcRow) || (destCol - srcCol == srcRow - destRow)){
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

