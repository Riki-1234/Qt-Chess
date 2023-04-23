#pragma once

#include "piece.hpp"

class King : Piece
{
public:
    King(posXY sourcePos);
    std::vector<posFileRank> getValidMoves();
private:
    posXY m_sourcePos;
};
