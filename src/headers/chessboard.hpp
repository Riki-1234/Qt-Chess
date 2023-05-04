#pragma once

#include "chesstypes.hpp"
#include <map>

class ChessBoard
{
public:
    static std::map<posFileRank, ChessPiece> m_chessBoard;

    static PieceColor decidePieceColor();
    static PieceColor getPieceColor();
    static posXY posFileRankToPosXY(posFileRank position);
    static posFileRank posXYToPosFileRank(posXY position);
    static std::vector<posFileRank> getValidMoves(posXY sourcePos, ChessPiece piece);
    static std::vector<posFileRank> getEnemyMoves(const std::vector<ChessPiece>& enemyPieces);
    static bool isEnemyAttackingPiece(posFileRank sourcePos, posFileRank destPos);
    static std::map<posFileRank, ChessPiece> initializeBoard(PieceColor pieceColor);
    static bool isMovePossible(bool isTopTimerActive, bool isBottomTimerActive, ChessPiece piece, ChessPiece king);
private:
    static PieceColor m_pieceColor;
};
