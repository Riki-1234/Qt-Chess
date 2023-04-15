#include "bishop.hpp"

bool Bishop::isValidMove(posXY sourcePos, posXY destPos) {
    return (sourcePos.first - sourcePos.second == destPos.first - destPos.second)
            || (sourcePos.first + sourcePos.second == destPos.first + destPos.second);
}

std::vector<posFileRank> Bishop::getValidMoves(posXY sourcePos) {
    std::vector<posFileRank> validMoves;
    FieldIterator it(sourcePos);
    do {
        it.moveDiagonalUpRight();
        if(isValidMove(it.getSourcePos(), it.getCurrentPos()) && ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
        else if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            break;
        }
        else {
            break;
        }
    } while(it);
    it.moveToSourcePos();

    do {
        it.moveDiagonalUpLeft();
        if(isValidMove(it.getSourcePos(), it.getCurrentPos()) && ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
        else if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            break;
        }
        else {
            break;
        }
    } while(it);
    it.moveToSourcePos();

    do {
        it.moveDiagonalDownLeft();
        if(isValidMove(it.getSourcePos(), it.getCurrentPos()) && ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
        else if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            break;
        }
        else {
            break;
        }
    } while(it);
    it.moveToSourcePos();

    do {
        it.moveDiagonalDownRight();
        if(isValidMove(it.getSourcePos(), it.getCurrentPos()) && ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
        else if(isValidMove(it.getSourcePos(), it.getCurrentPos())
                && !isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            break;
        }
        else {
            break;
        }
    } while(it);

    return validMoves;
}
