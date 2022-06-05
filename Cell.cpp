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
    rect.setPosition(Vector2f(cellSize * cellCol, cellSize * cellRow));
    if (cellPiece != "--") {
        path = "/Users/mobin/CLionProjects/beautifulChess/Pieces/" + cellPiece + ".png";
        texture.loadFromFile(path);
        texture.setSmooth(true);
        sprite.setTexture(texture);
        scaler1 = cellSize / sprite.getTexture()->getSize().x;
        scaler2 = cellSize / sprite.getTexture()->getSize().y;
        sprite.setScale(scaler1, scaler2);
        sprite.setPosition(cellSize * float(cellCol), cellSize * float(cellRow));
    }
    shape_circle.setRadius(40.f);
    shape_circle.setFillColor(Color (169,169,169));
    shape_circle.setPosition(Vector2f(cellSize * cellCol, cellSize * cellRow));
}
