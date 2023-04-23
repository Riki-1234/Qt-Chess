#pragma once

#include "piece.hpp"

class Bishop : Piece
{
public:
    Bishop(posXY sourcePos);
    std::vector<posFileRank> getValidMoves();
private:
    posXY m_sourcePos;
};
