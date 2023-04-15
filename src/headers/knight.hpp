#pragma once

#include "piece.hpp"

class Knight : Piece
{
public:
    std::vector<posFileRank> getValidMoves(posXY sourcePos);
private:
    bool isValidMove(posXY sourcePos, posXY destPos);
    bool isPieceInWay(posXY position);
};
