#include "bishop.hpp"

Bishop::Bishop(posXY sourcePos) :
    m_sourcePos(sourcePos) {}

std::vector<posFileRank> Bishop::getValidMoves() {
    std::vector<posFileRank> validMoves;
    FieldIterator it(m_sourcePos);
    do {
        it.moveDiagonalUpRight();
        if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
        else if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
            break;
        }
        else {
            break;
        }
    } while(it);
    it.moveToSourcePos();

    do {
        it.moveDiagonalUpLeft();
        if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
        else if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
            break;
        }
        else {
            break;
        }
    } while(it);
    it.moveToSourcePos();

    do {
        it.moveDiagonalDownLeft();
        if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
        else if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
            break;
        }
        else {
            break;
        }
    } while(it);
    it.moveToSourcePos();

    do {
        it.moveDiagonalDownRight();
        if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
        else if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
            break;
        }
        else {
            break;
        }
    } while(it);

    return validMoves;
}
