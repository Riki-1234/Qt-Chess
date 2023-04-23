#include "pawn.hpp"

Pawn::Pawn(posXY sourcePos) :
    m_sourcePos(sourcePos) {}

std::vector<posFileRank> Pawn::getValidMoves() {
    std::vector<posFileRank> validMoves;
    FieldIterator it(m_sourcePos);

    if(Piece::getSourcePiece(it) == ChessPiece::B_Pawn) {
        if(it.getSourcePos().second == 2) {
            it.moveUp();
            if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }

            it.moveUp();
            if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            it.moveUp();
            if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        it.moveToSourcePos();

        it.moveDiagonalUpLeft();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && Piece::getDestPiece(it) != ChessPiece::NoPiece) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
        it.moveToSourcePos();

        it.moveDiagonalUpRight();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && Piece::getDestPiece(it) != ChessPiece::NoPiece) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    else if(Piece::getSourcePiece(it) == ChessPiece::W_Pawn) {
        if(it.getSourcePos().second == 7) {
            it.moveDown();
            if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
            it.moveDown();
            if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            it.moveDown();
            if(Piece::getDestPiece(it) == ChessPiece::NoPiece) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        it.moveToSourcePos();

        it.moveDiagonalDownLeft();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && Piece::getDestPiece(it) != ChessPiece::NoPiece) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
        it.moveToSourcePos();

        it.moveDiagonalDownRight();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && Piece::getDestPiece(it) != ChessPiece::NoPiece) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    return validMoves;
}
