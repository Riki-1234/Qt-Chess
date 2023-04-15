#pragma once

#include <vector>
#include "chesstypes.hpp"
#include "fielditerator.hpp"
#include "chessboard.hpp"

class Piece
{
public:
    static bool isFriendly(ChessPiece sourcePiece, ChessPiece destPiece);
protected:
    virtual bool isValidMove(posXY sourcePos, posXY destPos) = 0;
};
