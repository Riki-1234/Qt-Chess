#include "knight.hpp"

bool Knight::isValidMove(posXY sourcePos, posXY destPos) {
    return abs (sourcePos.first - destPos.first) * abs (sourcePos.second - destPos.second) == 2;
}

bool Knight::isPieceInWay(posXY position) {
    return ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(position)] != ChessPiece::NoPiece;
}

std::vector<posFileRank> Knight::getValidMoves(posXY sourcePos) {
    std::vector<posFileRank> validMoves;
    FieldIterator it(sourcePos);

    auto rightUpMovement = [&]() -> void {
        it.moveRight();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveRight();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveUp();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    rightUpMovement();
    it.moveToSourcePos();

    auto rightDownMovement = [&]() -> void {
        it.moveRight();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveRight();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveDown();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    rightDownMovement();
    it.moveToSourcePos();

    auto leftUpMovement = [&]() -> void {
        it.moveLeft();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveLeft();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveUp();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    leftUpMovement();
    it.moveToSourcePos();

    auto leftDownMovement = [&]() -> void {
        it.moveLeft();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveLeft();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveDown();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    leftDownMovement();
    it.moveToSourcePos();

    auto upRightMovement = [&]() -> void {
        it.moveUp();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveUp();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveRight();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    upRightMovement();
    it.moveToSourcePos();

    auto upLeftMovement = [&]() -> void {
        it.moveUp();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveUp();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveLeft();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    upLeftMovement();
    it.moveToSourcePos();

    auto downRightMovement = [&]() -> void {
        it.moveDown();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveDown();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveRight();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    downRightMovement();
    it.moveToSourcePos();

    auto downLeftMovement = [&]() -> void {
        it.moveDown();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveDown();
        if(isPieceInWay(it.getCurrentPos())) {
            return;
        }
        it.moveLeft();
        if(!isFriendly(Piece::getSourcePiece(it), Piece::getDestPiece(it)) && isValidMove(sourcePos, it.getCurrentPos())) {
            validMoves.push_back(Piece::getCurrentPosFileRank(it));
        }
    };
    downLeftMovement();

    return validMoves;
}
