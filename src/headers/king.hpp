#pragma once

#include "piece.hpp"

class King : Piece
{
public:
    std::vector<posFileRank> getValidMoves(posXY sourcePos);
};
