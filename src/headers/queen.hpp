#pragma once

#include "piece.hpp"

class Queen : Piece
{
public:
    Queen(posXY sourcePos);
    std::vector<posFileRank> getValidMoves();
private:
    posXY m_sourcePos;
};
