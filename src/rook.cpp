#include "rook.hpp"

std::vector<posFileRank> Rook::getValidMoves(posXY sourcePos) {
    std::vector<posFileRank> validMoves;
    FieldIterator it(sourcePos);
    do {
        it.moveRight();
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
        it.moveLeft();
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
        it.moveUp();
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
        it.moveDown();
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
