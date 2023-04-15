#include "pawn.hpp"

bool Pawn::isValidMove(posXY sourcePos, posXY destPos) {
    return true;
}

std::vector<posFileRank> Pawn::getValidMoves(posXY sourcePos) {
    std::vector<posFileRank> validMoves;
    FieldIterator it(sourcePos);

    if(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())] == ChessPiece::B_Pawn) {
        if(it.getSourcePos().second == 2) {
            it.moveUp();
            if(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
                validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            }
            it.moveUp();
            if(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
                validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            }
        }
        else {
            it.moveUp();
            if(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
                validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            }
        }
        it.moveToSourcePos();
        it.moveDiagonalUpLeft();
        if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])
           && ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] != ChessPiece::NoPiece) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }

        it.moveToSourcePos();
        it.moveDiagonalUpRight();
        if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])
                       && ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] != ChessPiece::NoPiece) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    }
    else if(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())] == ChessPiece::W_Pawn) {
        if(it.getSourcePos().second == 7) {
            it.moveDown();
            if(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
                validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            }
            it.moveDown();
            if(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
                validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            }
        }
        else {
            it.moveDown();
            if(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] == ChessPiece::NoPiece) {
                validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
            }
        }
        it.moveToSourcePos();
        it.moveDiagonalDownLeft();
        if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])
           && ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] != ChessPiece::NoPiece) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }

        it.moveToSourcePos();
        it.moveDiagonalDownRight();
        if(!isFriendly(ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getSourcePos())], ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())])
           && ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(it.getCurrentPos())] != ChessPiece::NoPiece) {
            validMoves.push_back(ChessBoard::posXYToPosFileRank(it.getCurrentPos()));
        }
    }
    return validMoves;
}
