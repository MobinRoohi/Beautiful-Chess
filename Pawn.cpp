#include "Pawn.h"

Pawn::Pawn(string input1, int row1, int col1) :
Piece(input1, row1, col1) {
}
Pawn::~Pawn() {}
bool Pawn::validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board){
    if (board[destRow][destCol]->returnPiece() == "--"){
        if (srcCol == destCol){
            if (pieceColor == 'W'){
                if (destRow == srcRow - 1){
                    return true;
                }
            }
            else {
                if (destRow == srcRow + 1){
                    return true;
                }
            }
        }
    }
    else {
        if ((srcCol == destCol - 1) || (srcCol == destCol + 1)){
            if (pieceColor == 'W'){
                if (destRow == srcRow - 1){
                    return true;
                }
            }
            else{
                if (destRow == srcRow + 1){
                    return true;
                }
            }
        }
    }
    if (srcCol == destCol){
        if ((pieceColor == 'W') && (srcRow == 6) &&
            (board[srcRow - 2][srcCol]->returnPiece() == "--")){
            if (srcRow - destRow == 2)
                return true;
        }
        else if ((pieceColor == 'B') && (srcRow == 1) &&
                 (board[srcRow + 2][srcCol]->returnPiece() == "--")){
            if (srcRow - destRow == -2)
                return true;
        }
    }
    return false;
}

