#include "Cell.h"

Cell::Cell(string cellPiece, int cellRow, int cellCol, float cellSize) {
    cellColor = ((cellCol + cellRow) % 2 == 0) ? 'W' : 'B';
    this->cellRow = cellRow;
    this->cellCol = cellCol;
    cellSelector = false;
    cellSelected = false;
    this->cellPiece = cellPiece;
    Color colorGreen(119, 149, 86);
    rect.setSize(Vector2f(cellSize, cellSize));
    if (cellColor == 'W') rect.setFillColor(Color::White);
    else rect.setFillColor(colorGreen);
    rect.setPosition(Vector2f(cellSize * cellRow, cellSize * cellCol));
}
