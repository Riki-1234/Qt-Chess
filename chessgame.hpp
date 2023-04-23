#pragma once

#include "chesstypes.hpp"

class ChessGame
{
public:
    static bool isCheckMate(ChessPiece king);
    static bool isCheck(ChessPiece king);
private:
    void gameLoop();
};
