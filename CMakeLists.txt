cmake_minimum_required(VERSION 3.21)
project(beautifulChess)

set(CMAKE_CXX_STANDARD 14)

add_executable(beautifulChess main.cpp Board.h Board.cpp Piece.h Piece.cpp King.h Queen.cpp King.cpp Queen.h Rook.cpp Rook.h Bishop.cpp Bishop.h Knight.cpp Knight.h Pawn.cpp Pawn.h Empty.cpp Empty.h Cell.cpp Cell.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(beautifulChess sfml-system sfml-window sfml-graphics sfml-audio sfml-network)