#pragma once

#include "piece.hpp"

class Rook : Piece
{
public:
    std::vector<posFileRank> getValidMoves(posXY sourcePos);
private:
    bool isValidMove(posXY sourcePos, posXY destPos);
};
