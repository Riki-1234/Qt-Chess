#pragma once

#include "chesstypes.hpp"

class ChessGame
{
public:
    static bool isCheckMate(ChessPiece piece);
    static bool isCheck(ChessPiece piece);
    static PieceColor getCurrentPlayer();
    static void setCurrentPlayer(PieceColor color);
    static void gameLoop();
    static void gameStart();
private:
    static PieceColor m_currentPlayer;
};
