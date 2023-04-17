#include "king.hpp"

std::vector<posFileRank> King::getValidMoves(posXY sourcePos) {
    std::vector<posFileRank> validMoves;
    FieldIterator it(sourcePos);

    it.moveRight();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        validMoves.push_back(Piece::getCurrentPosFileRank(it));
    }
    it.moveToSourcePos();

    it.moveLeft();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        validMoves.push_back(Piece::getCurrentPosFileRank(it));
    }
    it.moveToSourcePos();

    it.moveUp();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        validMoves.push_back(Piece::getCurrentPosFileRank(it));
    }
    it.moveToSourcePos();

    it.moveDown();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        validMoves.push_back(Piece::getCurrentPosFileRank(it));
    }
    it.moveToSourcePos();

    it.moveDiagonalUpRight();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        validMoves.push_back(Piece::getCurrentPosFileRank(it));
    }
    it.moveToSourcePos();

    it.moveDiagonalUpLeft();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        validMoves.push_back(Piece::getCurrentPosFileRank(it));
    }
    it.moveToSourcePos();

    it.moveDiagonalDownRight();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        validMoves.push_back(Piece::getCurrentPosFileRank(it));
    }
    it.moveToSourcePos();

    it.moveDiagonalDownLeft();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        validMoves.push_back(Piece::getCurrentPosFileRank(it));
    }

    return validMoves;
}
