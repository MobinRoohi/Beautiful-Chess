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
    shape_circle.setRadius(30.f);
//    if (cellColor == 'W') shape_circle.setFillColor(Color::White);
//    else shape_circle.setFillColor(Color (119,149,86));

    shape_circle.setPosition(Vector2f(cellSize * cellCol + cellSize / 2 - 30, cellSize * cellRow + cellSize / 2 - 30));
    shape_circle.setFillColor(Color (169,169,169));
//    shape_circle.setOutlineThickness(15.f);
    shape_circle.setOutlineColor(Color(169,169,169));
    shape_circle.setPointCount(1000);

}

void Cell::addSelectorGraphic(char colorSrc, char colorDest) {
    if (colorDest != colorSrc && colorDest != '-') {
        shape_circle.setRadius(70);
        shape_circle.setOutlineThickness(20);
        shape_circle.setOutlineColor(Color (169,169,169));
        shape_circle.setPosition(200 * cellCol + 200 / 2 - 70, 200 * cellRow + 200 / 2 - 70);
        if ((cellRow + cellCol) % 2 == 0) {
            shape_circle.setFillColor(Color::White);
        } else {
            shape_circle.setFillColor(Color (119,149,86));
        }
    }
}

void Cell::checkGraphics(int iRow, int jCol, int sig) {
    if (sig == 1) {
        rect.setFillColor(Color::Red);
        return;
    }
    if ((cellRow + cellCol) % 2 == 0) {
        rect.setFillColor(Color::White);
        return;
    }
    rect.setFillColor(Color (119, 149, 86));
    return;

}