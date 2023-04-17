#pragma once

#include "chesstypes.hpp"
#include <map>

class ChessBoard
{
public:
    ChessBoard();
    static std::map<posFileRank, ChessPiece> m_chessBoard;
    static posXY posFileRankToPosXY(posFileRank position);
    static posFileRank posXYToPosFileRank(posXY position);
    static std::vector<posFileRank> getValidMoves(posXY sourcePos, ChessPiece piece);
private:
    static std::map<posFileRank, ChessPiece> initializeBoard();
};
