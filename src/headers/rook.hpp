#pragma once

#include "piece.hpp"

class Rook : Piece
{
public:
    Rook(posXY sourcePos);
    std::vector<posFileRank> getValidMoves();
private:
    posXY m_sourcePos;
};
