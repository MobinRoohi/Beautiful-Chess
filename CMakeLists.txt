cmake_minimum_required(VERSION 3.21)
project(beautifulChess)

set(CMAKE_CXX_STANDARD 14)

add_executable(beautifulChess main.cpp Board.h Board.cpp Piece.h Piece.cpp King.h Queen.cpp King.cpp Queen.h Rook.cpp Rook.h Bishop.cpp Bishop.h Knight.cpp Knight.h Pawn.cpp Pawn.h Empty.cpp Empty.h)
