#include <iostream>
#include <vector>

#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Empty.h"

Piece::Piece(string input, int row, int col) {
    pieceType = input[0];
    pieceColor = input[1];
    this->row = row;
    this->col = col;
}

string Piece::returnPiece() {
    string temp = "";
    temp += this->pieceType; temp += this->pieceColor;
    return temp;
}

bool Piece::legalMove(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board) {
    if (board[destRow][destCol]->returnPiece() == "--" ||
        this->pieceColor != board[destRow][destCol]->pieceColor) {
        return board[srcRow][srcCol]->validation(srcRow, srcCol, destRow, destCol, board);
    }
    return false;
}

bool Piece::move(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> &board){
    if (legalMove(srcRow, srcCol, destRow, destCol, board)){
        string temp = board[srcRow][srcCol]->returnPiece();
        board[srcRow][srcCol] = new Empty("--", srcRow, srcCol);
        if (temp[0] == 'K') {
            board[destRow][destCol] = new King(temp, destRow, destCol);
            return true;
        }if (temp[0] == 'Q') {
            board[destRow][destCol] = new Queen(temp, destRow, destCol);
            return true;
        }if (temp[0] == 'R') {
            board[destRow][destCol] = new Rook(temp, destRow, destCol);
            return true;
        }if (temp[0] == 'B') {
            board[destRow][destCol] = new Bishop(temp, destRow, destCol);
            return true;
        }if (temp[0] == 'N') {
            board[destRow][destCol] = new Knight(temp, destRow, destCol);
            return true;
        }if (temp[0] == 'P') {
            board[destRow][destCol] = new Pawn(temp, destRow, destCol);
            return true;
        }if (temp[0] == '-') {
            board[destRow][destCol] = new Empty(temp, destRow, destCol);
            return true;
        }

    }
    return false;
}