#include "chessgame.hpp"
#include "chessboard.hpp"
#include "king.hpp"

bool ChessGame::isCheckMate(ChessPiece piece) {
    ChessPiece king;
    if(contains(w_pieces, piece)) {
        king = ChessPiece::W_King;
    }
    else {
        king = ChessPiece::B_King;
    }

    posFileRank kingPos;
    for(auto it = ChessBoard::m_chessBoard.begin(); it != ChessBoard::m_chessBoard.end(); it++) {
        if(it->second == king) {
            kingPos = it->first;
        }
    }

    if(isCheck(king)) {
        King king(ChessBoard::posFileRankToPosXY(kingPos));
        auto kingMoves = king.getValidMoves();
        for(int i = 0; i < kingMoves.size(); i++) {
            if(Piece::getPieceAtPos(kingMoves[i]) == ChessPiece::NoPiece) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool ChessGame::isCheck(ChessPiece piece) {
    ChessPiece king;
    if(contains(w_pieces, piece)) {
        king = ChessPiece::W_King;
    }
    else {
        king = ChessPiece::B_King;
    }

    posFileRank kingPos;
    for(auto it = ChessBoard::m_chessBoard.begin(); it != ChessBoard::m_chessBoard.end(); it++) {
        if(it->second == king) {
            kingPos = it->first;
        }
    }

    std::vector<ChessPiece> enemyPieces;
    if(std::count(w_pieces.begin(), w_pieces.end(), king)) {
        enemyPieces = b_pieces;
    }
    else {
        enemyPieces = w_pieces;
    }

    std::vector<posFileRank> enemyMoves = ChessBoard::getEnemyMoves(enemyPieces);
    for(int i = 0; i < enemyMoves.size(); i++) {
        if(enemyMoves[i] == kingPos) {
            return true;
        }
    }
    return false;
}

PieceColor ChessGame::m_currentPlayer = PieceColor::White;

PieceColor ChessGame::getCurrentPlayer() {
    return m_currentPlayer;
}

void ChessGame::setCurrentPlayer(PieceColor color) {
    m_currentPlayer = color;
}


