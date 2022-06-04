#include <iostream>
#include <vector>
#include "Board.h"
#include "Piece.h"


using namespace std;

int main(){
    Board obj;
//    obj.printBoard();
    string t;
    string t1, t2, t3;
    while(cin >> t){
        if (t != "fin"){
            t1 = t.substr(0, 2);
            t2 = t.substr(2, 2);
            t3 = t.substr(4, 2);
            int a, b;
            a = 8 - (int(t1[1]) - int('0'));
            b = 8 - (int(t3[1]) - int('0'));
            if (!obj.makeMove(a, int(t1[0]) - int('a'),
                              b, int(t3[0]) - int('a')))
                break;
//        obj.printBoard();
        }
        else{
            if (obj.returnTurn()){
                cout << "black win";
                break;
            }
            if (!obj.returnTurn()){
                cout << "white win";
                break;
            }
        }
    }
}

