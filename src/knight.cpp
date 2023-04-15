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
        if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    };
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
        if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    };

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
        if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    };
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
        if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    };

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
        if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    };
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
        if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    };

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
        if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    };
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
        if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    };

    rightUpMovement();
    it.moveToSourcePos();
    rightDownMovement();
    it.moveToSourcePos();
    leftUpMovement();
    it.moveToSourcePos();
    leftDownMovement();
    it.moveToSourcePos();

    upRightMovement();
    it.moveToSourcePos();
    upLeftMovement();
    it.moveToSourcePos();
    downRightMovement();
    it.moveToSourcePos();
    downLeftMovement();

    return validMoves;
}
