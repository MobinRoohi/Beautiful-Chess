#ifndef BEAUTIFULCHESS_CELL_H
#define BEAUTIFULCHESS_CELL_H
#include "Board.h"
using namespace sf;

class Cell {
public:
    char cellColor;
    int cellRow;
    int cellCol;
    bool cellSelector;
    bool cellSelected;
    string cellPiece;
    RectangleShape rect;
    Color colorGreen;
    Sprite sprite;
    Texture texture;
    string path;
    float scaler1;
    float scaler2;
    CircleShape shape_circle;

    Cell(string cellPiece, int cellRow, int cellCol, float cellSize);


};
#endif //BEAUTIFULCHESS_CELL_H
