#pragma once

#include "chesstypes.hpp"
#include "fielditerator.hpp"
#include "chessboard.hpp"

class Piece
{
public:
    static bool isFriendly(ChessPiece sourcePiece, ChessPiece destPiece);
    static bool isEnPassant(ChessPiece firstPawn, posFileRank firstPawnPos, posFileRank secondPawnPos);
    static bool isKingSideCastling();
    static bool isQueenSideCastling();

    static ChessPiece getSourcePiece(const FieldIterator& iterator);
    static ChessPiece getDestPiece(const FieldIterator& iterator);
    static posFileRank getCurrentPosFileRank(const FieldIterator& iterator);
    static posFileRank getSourcePosFileRank(const FieldIterator& iterator);
    static ChessPiece getPieceAtPos(posFileRank position);

    static void setPieceAtPos(posFileRank position, ChessPiece newPiece);
protected:
    virtual std::vector<posFileRank> getValidMoves() = 0;
};
