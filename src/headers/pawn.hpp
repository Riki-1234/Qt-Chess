#pragma once

#include "piece.hpp"

class Pawn : Piece
{
public:
    Pawn(posXY sourcePos);
    std::vector<posFileRank> getValidMoves();
private:
    posXY m_sourcePos;
};
