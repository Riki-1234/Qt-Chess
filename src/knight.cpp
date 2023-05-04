#include "knight.hpp"

Knight::Knight(posXY sourcePos) :
    m_sourcePos(sourcePos) {}

bool Knight::isValidMove(posXY sourcePos, posXY destPos) {
    return abs (sourcePos.first - destPos.first) * abs (sourcePos.second - destPos.second) == 2;
}

std::vector<posFileRank> Knight::getValidMoves() {
    std::vector<posFileRank> validMoves;
    FieldIterator it(m_sourcePos);

    auto rightUpMovement = [&]() -> void {
        it.moveRight();
        it.moveRight();
        it.moveUp();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(m_sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    rightUpMovement();
    it.moveToSourcePos();

    auto rightDownMovement = [&]() -> void {
        it.moveRight();
        it.moveRight();
        it.moveDown();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(m_sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    rightDownMovement();
    it.moveToSourcePos();

    auto leftUpMovement = [&]() -> void {
        it.moveLeft();
        it.moveLeft();
        it.moveUp();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(m_sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    leftUpMovement();
    it.moveToSourcePos();

    auto leftDownMovement = [&]() -> void {
        it.moveLeft();
        it.moveLeft();
        it.moveDown();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(m_sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    leftDownMovement();
    it.moveToSourcePos();

    auto upRightMovement = [&]() -> void {
        it.moveUp();
        it.moveUp();
        it.moveRight();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(m_sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    upRightMovement();
    it.moveToSourcePos();

    auto upLeftMovement = [&]() -> void {
        it.moveUp();
        it.moveUp();
        it.moveLeft();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(m_sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    upLeftMovement();
    it.moveToSourcePos();

    auto downRightMovement = [&]() -> void {
        it.moveDown();
        it.moveDown();
        it.moveRight();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(m_sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    downRightMovement();
    it.moveToSourcePos();

    auto downLeftMovement = [&]() -> void {
        it.moveDown();
        it.moveDown();
        it.moveLeft();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(m_sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    downLeftMovement();

    return validMoves;
}
