#include "King.h"

King::King(string input1, int row1, int col1) : Piece(input1, row1, col1) {}

King::~King(){}

bool King::validation(int srcRow, int srcCol, int destRow, int destCol, vector<vector<Piece*>> board) {
    int rowDelta = destRow - srcRow;
    int colDelta = destCol - srcCol;
    if (((rowDelta >= -1) && (rowDelta <= 1)) &&
        ((colDelta >= -1) && (colDelta <= 1)))
    {
        return true;
    }
    return false;
}