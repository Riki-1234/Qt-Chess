#pragma once

#include "piece.hpp"

class Bishop : Piece
{
public:
    std::vector<posFileRank> getValidMoves(posXY sourcePos);
private:
    bool isValidMove(posXY sourcePos, posXY destPos);
};
