#include "chessgame.hpp"
#include "chessboard.hpp"
#include "king.hpp"

bool ChessGame::isCheckMate(ChessPiece king) {
    posFileRank kingPos;
    for(auto it = ChessBoard::m_chessBoard.begin(); it != ChessBoard::m_chessBoard.end(); it++) {
        if(it->second == king) {
            kingPos = it->first;
        }
    }

    if(isCheck(king)) {
        King king(ChessBoard::posFileRankToPosXY(kingPos));
        auto kingMoves = king.getValidMoves();
        if(kingMoves.empty()) {
            return true;
        }
    }
    return false;
}

bool ChessGame::isCheck(ChessPiece king) {
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

void ChessGame::gameLoop() {
    while(true) {


        if(isCheckMate(ChessPiece::B_King)) {
            break;
        }
        else if(isCheckMate(ChessPiece::W_King)) {
            break;
        }
    }
}
