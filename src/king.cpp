#include "king.hpp"
#include "chessgame.hpp"

King::King(posXY sourcePos) :
    m_sourcePos(sourcePos) {}

std::vector<posFileRank> King::getValidMoves() {
    std::vector<posFileRank> validMoves;
    FieldIterator it(m_sourcePos);

    it.moveRight();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        if(ChessGame::isCheck(Piece::getSourcePiece(it.getSourcePos()))) {
            if(!ChessBoard::isEnemyAttackingPiece(Piece::getSourcePosFileRank(it), Piece::getCurrentPosFileRank(it))) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    it.moveToSourcePos();

    it.moveLeft();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        if(ChessGame::isCheck(Piece::getSourcePiece(it.getSourcePos()))) {
            if(!ChessBoard::isEnemyAttackingPiece(Piece::getSourcePosFileRank(it), Piece::getCurrentPosFileRank(it))) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    it.moveToSourcePos();

    it.moveUp();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        if(ChessGame::isCheck(Piece::getSourcePiece(it.getSourcePos()))) {
            if(!ChessBoard::isEnemyAttackingPiece(Piece::getSourcePosFileRank(it), Piece::getCurrentPosFileRank(it))) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    it.moveToSourcePos();

    it.moveDown();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        if(ChessGame::isCheck(Piece::getSourcePiece(it.getSourcePos()))) {
            if(!ChessBoard::isEnemyAttackingPiece(Piece::getSourcePosFileRank(it), Piece::getCurrentPosFileRank(it))) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    it.moveToSourcePos();

    it.moveDiagonalUpRight();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        if(ChessGame::isCheck(Piece::getSourcePiece(it.getSourcePos()))) {
            if(!ChessBoard::isEnemyAttackingPiece(Piece::getSourcePosFileRank(it), Piece::getCurrentPosFileRank(it))) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    it.moveToSourcePos();

    it.moveDiagonalUpLeft();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        if(ChessGame::isCheck(Piece::getSourcePiece(it.getSourcePos()))) {
            if(!ChessBoard::isEnemyAttackingPiece(Piece::getSourcePosFileRank(it), Piece::getCurrentPosFileRank(it))) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    it.moveToSourcePos();

    it.moveDiagonalDownRight();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        if(ChessGame::isCheck(Piece::getSourcePiece(it.getSourcePos()))) {
            if(!ChessBoard::isEnemyAttackingPiece(Piece::getSourcePosFileRank(it), Piece::getCurrentPosFileRank(it))) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }
    it.moveToSourcePos();

    it.moveDiagonalDownLeft();
    if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it))) {
        if(ChessGame::isCheck(Piece::getSourcePiece(it.getSourcePos()))) {
            if(!ChessBoard::isEnemyAttackingPiece(Piece::getSourcePosFileRank(it), Piece::getCurrentPosFileRank(it))) {
                validMoves.push_back(Piece::getCurrentPosFileRank(it));
            }
        }
        else {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    }

    return validMoves;
}
