#pragma once

#include "chesstypes.hpp"
#include "fielditerator.hpp"
#include "chessboard.hpp"

class Piece
{
public:
    static bool isFriendly(ChessPiece sourcePiece, ChessPiece destPiece);
    static ChessPiece getSourcePiece(const FieldIterator& iterator);
    static ChessPiece getDestPiece(const FieldIterator& iterator);
    static posFileRank getCurrentPosFileRank(const FieldIterator& iterator);
protected:
    virtual std::vector<posFileRank> getValidMoves(posXY sourcePos) = 0;
};
