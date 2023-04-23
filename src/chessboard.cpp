#include "chessboard.hpp"
#include "bishop.hpp"
#include "rook.hpp"
#include "queen.hpp"
#include "pawn.hpp"
#include "knight.hpp"
#include "king.hpp"
#include <utility>

ChessBoard::ChessBoard() {}

std::map<posFileRank, ChessPiece> ChessBoard::initializeBoard() {
    std::map<posFileRank, ChessPiece> chessBoard;
    for(int i = 0; i < m_files.length(); i++) {
        for(int j = 0; j < m_ranks.length(); j++) {
            chessBoard.insert(std::pair<posFileRank, ChessPiece>(std::string(1, m_files[i]) + std::string(1, m_ranks[j]), ChessPiece::NoPiece));
        }
    }

    chessBoard["A1"] = ChessPiece::B_Rook;
    chessBoard["B1"] = ChessPiece::B_Knight;
    chessBoard["C1"] = ChessPiece::B_Bishop;
    chessBoard["D1"] = ChessPiece::B_King;
    chessBoard["E1"] = ChessPiece::B_Queen;
    chessBoard["F1"] = ChessPiece::B_Bishop;
    chessBoard["G1"] = ChessPiece::B_Knight;
    chessBoard["H1"] = ChessPiece::B_Rook;

    for(int i = 0; i < m_files.length(); i++) {
        chessBoard[std::string(1, m_files[i]) + std::string(1, '2')] = ChessPiece::B_Pawn;
    }

    chessBoard["A8"] = ChessPiece::W_Rook;
    chessBoard["B8"] = ChessPiece::W_Knight;
    chessBoard["C8"] = ChessPiece::W_Bishop;
    chessBoard["D8"] = ChessPiece::W_King;
    chessBoard["E8"] = ChessPiece::W_Queen;
    chessBoard["F8"] = ChessPiece::W_Bishop;
    chessBoard["G8"] = ChessPiece::W_Knight;
    chessBoard["H8"] = ChessPiece::W_Rook;

    for(int i = 0; i < m_files.length(); i++) {
        chessBoard[std::string(1, m_files[i]) + std::string(1, '7')] = ChessPiece::W_Pawn;
    }
    return chessBoard;
}

posXY ChessBoard::posFileRankToPosXY(posFileRank position) {
    posXY positionXY;
    constexpr uint8_t asciiOffset = 48;
    const char xIndex = position[0], yIndex = position[1];

    for(int i = 0; i < m_files.size(); i++) {
        if(xIndex == m_files[i]) {
            positionXY.first = i + 1;
            break;
        }
    }
    positionXY.second = static_cast<uint8_t>(yIndex) - asciiOffset;

    return positionXY;
}

posFileRank ChessBoard::posXYToPosFileRank(posXY position) {
    posFileRank positionFileRank{};
    positionFileRank += m_files[position.first - 1];
    std::string second = std::to_string(position.second);
    positionFileRank += second;

    return positionFileRank;
}

std::vector<posFileRank> ChessBoard::getValidMoves(posXY sourcePos, ChessPiece piece) {
    std::vector<posFileRank> validMoves;
    if(piece == ChessPiece::W_Bishop || piece == ChessPiece::B_Bishop) {
        Bishop bishop(sourcePos);
        validMoves = bishop.getValidMoves();
    }
    else if(piece == ChessPiece::W_Rook || piece == ChessPiece::B_Rook) {
        Rook rook(sourcePos);
        validMoves = rook.getValidMoves();
    }
    else if(piece == ChessPiece::W_Queen || piece == ChessPiece::B_Queen) {
        Queen queen(sourcePos);
        validMoves = queen.getValidMoves();
    }
    else if(piece == ChessPiece::W_Knight || piece == ChessPiece::B_Knight) {
        Knight knight(sourcePos);
        validMoves = knight.getValidMoves();
    }
    else if(piece == ChessPiece::W_King || piece == ChessPiece::B_King) {
        King king(sourcePos);
        validMoves = king.getValidMoves();
    }
    else if(piece == ChessPiece::W_Pawn || piece == ChessPiece::B_Pawn) {
        Pawn pawn(sourcePos);
        validMoves = pawn.getValidMoves();
    }
    return validMoves;
}

std::vector<posFileRank> ChessBoard::getEnemyMoves(const std::vector<ChessPiece>& enemyPieces) {
    std::vector<posFileRank> enemyMoves;
    for(auto it = ChessBoard::m_chessBoard.begin(); it != ChessBoard::m_chessBoard.end(); it++) {
        if(std::count(enemyPieces.begin(), enemyPieces.end(), it->second) && (it->second != ChessPiece::B_King && it->second != ChessPiece::W_King)) {
            std::vector<posFileRank> oneEnemyPieceValidMoves = ChessBoard::getValidMoves(ChessBoard::posFileRankToPosXY(it->first), it->second);
            enemyMoves.insert(enemyMoves.end(), oneEnemyPieceValidMoves.begin(), oneEnemyPieceValidMoves.end());
        }
    }
    auto duplicates = std::unique(enemyMoves.begin(), enemyMoves.end());
    enemyMoves.erase(duplicates, enemyMoves.end());

    return enemyMoves;
}

bool ChessBoard::isEnemyAttackingPiece(posFileRank sourcePos, posFileRank destPos) {
    std::vector<posFileRank> enemyMoves;
    ChessPiece piece = Piece::getPieceAtPos(sourcePos);
    if(std::count(b_pieces.begin(), b_pieces.end(), piece)) {
        enemyMoves = getEnemyMoves(w_pieces);
        for(int i = 0; i < enemyMoves.size(); i++) {
            if(destPos == enemyMoves[i]) {
                return true;
            }
        }
    }
    else if(std::count(w_pieces.begin(), w_pieces.end(), piece)) {
        enemyMoves = getEnemyMoves(b_pieces);
        for(int i = 0; i < enemyMoves.size(); i++) {
            if(destPos == enemyMoves[i]) {
                return true;
            }
        }
    }
    return false;
}

std::map<posFileRank, ChessPiece> ChessBoard::m_chessBoard = ChessBoard::initializeBoard();
