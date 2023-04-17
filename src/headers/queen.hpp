#pragma once

#include "piece.hpp"

class Queen : Piece
{
public:
    std::vector<posFileRank> getValidMoves(posXY sourcePos);
};
