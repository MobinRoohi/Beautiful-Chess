#include <iostream>
#include <vector>

#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Empty.h"


Board::Board(){
    getBoard();
    WHITES_TURN = true;
}

bool Board::returnTurn() {
    return WHITES_TURN;
}

void Board::getBoard(){ // For inputting the chess board!
    string temp;
    for (int i = 0; i < 8; i++) {
        std::vector<Piece*> v;
        for (int j = 0; j < 8; j++) {
            cin >> temp;
            if (temp[0] == 'K') {
                Piece *a = new King(temp, i, j);
                v.push_back(a);
            }
            if (temp[0] == 'Q') {
                Piece *b = new Queen(temp, i, j);
                v.push_back(b);
            }
            if (temp[0] == 'R') {
                Piece *c = new Rook(temp, i, j);
                v.push_back(c);
            }
            if (temp[0] == 'B') {
                Piece *d = new Bishop(temp, i, j);
                v.push_back(d);
            }
            if (temp[0] == 'N') {
                Piece *e = new Knight(temp, i, j);
                v.push_back(e);
            }
            if (temp[0] == 'P') {
                Piece *f = new Pawn(temp, i, j);
                v.push_back(f);
            }
            if (temp[0] == '-'){
                Piece *g = new Empty(temp, i, j);
                v.push_back(g);
            }
        }
        board.push_back(v);
    }
}

void Board::printBoard(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << board[i][j]->returnPiece() << ' ';
        }
        cout << endl;
    }
}

bool Board::check(bool sig){
    int rowIndex_king, colIndex_king;
    int boolInt1 = (sig) ? 1: -1;
    int boolInt2 = (WHITES_TURN) ? 1: -1;
    bool checkBool = (boolInt1 * boolInt2 * -1 > 0) ? true: false;
    char kingColor = (checkBool) ? 'W': 'B';
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j]->returnPiece() != "--") {
                if (board[i][j]->returnPiece()[1] == kingColor) {
                    if (board[i][j]->returnPiece()[0] == 'K') {
                        rowIndex_king = i;
                        colIndex_king = j;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j]->returnPiece() != "--") {
                if (board[i][j]->returnPiece()[1] != kingColor) {
                    if (board[i][j]->legalMove(i, j, rowIndex_king, colIndex_king, board)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


bool Board::checkmate(char checkedColor){
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; j++) {
            if (i == 0 && j == 4)
                int x;
            if (board[i][j]->returnPiece() != "--" && board[i][j]->returnPiece()[1] == checkedColor){
                for (int n = 0; n < 8; n++){
                    for (int m = 0; m < 8; m++){
                        if (!(m == j && n == i) && board[i][j]->legalMove(i, j, n, m, board)){
                            vector<vector<Piece*>> board_Copy = board;
                            board[n][m] = board[i][j];
                            board[i][j] = new Empty("--", i, j);
                            if (i == 1 && j == 4 && n == 3 && m == 4)
                                int y;
                            if (check(true)){
                                board = board_Copy;
                            }
                            else{
                                board = board_Copy;
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Board::makeMove(int srcRow, int srcCol, int destRow, int destCol){
    char color = board[srcRow][srcCol]->returnPiece()[1];
    if ((color == 'W' && WHITES_TURN) || color == 'B' && !WHITES_TURN){
    }
    else{
        cout << "not your turn\n";
        return true;
    }
    vector<vector<Piece*>> board_Copy = board;
    if (board[srcRow][srcCol]->move(srcRow, srcCol, destRow, destCol, board)){
        if (!check(false)){
            char color_checked = (WHITES_TURN) ? 'B': 'W';
            if (check(true)){
                if(checkmate(color_checked)){
                    if (color_checked == 'W'){
                        cout << "done\n";
                        cout << "black win";
                        return false;
                    }
                    cout << "done\n";
                    cout << "white win";
                    return false;
                }
                else{
                    WHITES_TURN = !WHITES_TURN;
                    cout << "done\n";
                    return true;
                }
            }
            else{
                WHITES_TURN = !WHITES_TURN;
                cout << "done\n";
                return true;
            }
        }
        else{
            cout << "try again\n";
            board = board_Copy;
            return true;
        }
    }
    else{
        cout << "try again\n";
        return true;
    }
    return true;
}

