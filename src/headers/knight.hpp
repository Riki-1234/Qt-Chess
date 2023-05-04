#pragma once

#include "piece.hpp"

class Knight : Piece
{
public:
    Knight(posXY sourcePos);
    std::vector<posFileRank> getValidMoves();
private:
    bool isValidMove(posXY sourcePos, posXY destPos);
    posXY m_sourcePos;
};
