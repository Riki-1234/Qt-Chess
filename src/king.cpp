#include "king.hpp"

bool King::isValidMove(posXY sourcePos, posXY destPos) {
    return true;
}

std::vector<posFileRank> King::getValidMoves(posXY sourcePos) {
    std::vector<posFileRank> validMoves;
    FieldIterator it(sourcePos);

    it.moveRight();
    if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
        validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
    }
    it.moveToSourcePos();

    it.moveLeft();
    if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
        validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
    }
    it.moveToSourcePos();

    it.moveUp();
    if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
        validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
    }
    it.moveToSourcePos();

    it.moveDown();
    if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
        validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
    }
    it.moveToSourcePos();

    it.moveDiagonalUpRight();
    if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
        validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
    }
    it.moveToSourcePos();

    it.moveDiagonalUpLeft();
    if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
        validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
    }
    it.moveToSourcePos();

    it.moveDiagonalDownRight();
    if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
        validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
    }
    it.moveToSourcePos();

    it.moveDiagonalDownLeft();
    if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
        validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
    }

    return validMoves;
}
