#include "chessboard.hpp"
#include "chessgame.hpp"
#include "bishop.hpp"
#include "rook.hpp"
#include "queen.hpp"
#include "pawn.hpp"
#include "knight.hpp"
#include "king.hpp"
#include <utility>
#include <random>

std::map<posFileRank, ChessPiece> ChessBoard::initializeBoard(PieceColor pieceColor) {
    std::map<posFileRank, ChessPiece> chessBoard;
    for(int i = 0; i < m_files.length(); i++) {
        for(int j = 0; j < m_ranks.length(); j++) {
            chessBoard.insert(std::pair<posFileRank, ChessPiece>(std::string(1, m_files[i]) + std::string(1, m_ranks[j]), ChessPiece::NoPiece));
        }
    }


    chessBoard["A1"] = pieceColor == PieceColor::Black ? ChessPiece::B_Rook : ChessPiece::W_Rook;
    chessBoard["B1"] = pieceColor == PieceColor::Black ? ChessPiece::B_Knight : ChessPiece::W_Knight;
    chessBoard["C1"] = pieceColor == PieceColor::Black ? ChessPiece::B_Bishop : ChessPiece::W_Bishop;
    chessBoard["D1"] = pieceColor == PieceColor::Black ? ChessPiece::B_King : ChessPiece::W_King;
    chessBoard["E1"] = pieceColor == PieceColor::Black ? ChessPiece::B_Queen : ChessPiece::W_Queen;
    chessBoard["F1"] = pieceColor == PieceColor::Black ? ChessPiece::B_Bishop : ChessPiece::W_Bishop;
    chessBoard["G1"] = pieceColor == PieceColor::Black ? ChessPiece::B_Knight : ChessPiece::W_Knight;
    chessBoard["H1"] = pieceColor == PieceColor::Black ? ChessPiece::B_Rook : ChessPiece::W_Rook;

    for(int i = 0; i < m_files.length(); i++) {
        chessBoard[std::string(1, m_files[i]) + std::string(1, '2')] = pieceColor == PieceColor::Black ? ChessPiece::B_Pawn : ChessPiece::W_Pawn;
    }

    chessBoard["A8"] = pieceColor == PieceColor::Black ? ChessPiece::W_Rook : ChessPiece::B_Rook;
    chessBoard["B8"] = pieceColor == PieceColor::Black ? ChessPiece::W_Knight : ChessPiece::B_Knight;
    chessBoard["C8"] = pieceColor == PieceColor::Black ? ChessPiece::W_Bishop : ChessPiece::B_Bishop;
    chessBoard["D8"] = pieceColor == PieceColor::Black ? ChessPiece::W_King : ChessPiece::B_King;
    chessBoard["E8"] = pieceColor == PieceColor::Black ? ChessPiece::W_Queen : ChessPiece::B_Queen;
    chessBoard["F8"] = pieceColor == PieceColor::Black ? ChessPiece::W_Bishop : ChessPiece::B_Bishop;
    chessBoard["G8"] = pieceColor == PieceColor::Black ? ChessPiece::W_Knight : ChessPiece::B_Knight;
    chessBoard["H8"] = pieceColor == PieceColor::Black ? ChessPiece::W_Rook : ChessPiece::B_Rook;

    for(int i = 0; i < m_files.length(); i++) {
        chessBoard[std::string(1, m_files[i]) + std::string(1, '7')] = pieceColor == PieceColor::Black ? ChessPiece::W_Pawn : ChessPiece::B_Pawn;
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
            std::vector<posFileRank> oneEnemyPieceValidMoves;
            if(it->second != ChessPiece::B_Pawn || it->second != ChessPiece::W_Pawn) {
                oneEnemyPieceValidMoves = ChessBoard::getValidMoves(ChessBoard::posFileRankToPosXY(it->first), it->second);
            }
            else {
                Pawn pawn(ChessBoard::posFileRankToPosXY(it->first));
                oneEnemyPieceValidMoves = pawn.getAttackMoves();
            }
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

bool ChessBoard::isMovePossible(bool isTopTimerActive, bool isBottomTimerActive, ChessPiece piece, ChessPiece king) {
    if(ChessGame::isCheckMate(ChessPiece::B_King) || ChessGame::isCheckMate(ChessPiece::W_King)) {
        return false;
    }
    if(ChessGame::isCheck(piece) && piece != king) {
        return false;
    }
    if(contains(b_pieces, piece) && ChessGame::getCurrentPlayer() != PieceColor::Black) {
        return false;
    }
    if(!isTopTimerActive && ChessBoard::getPieceColor() != PieceColor::Black && contains(b_pieces, piece)) {
        return false;
    }
    else if(!isTopTimerActive && ChessBoard::getPieceColor() == PieceColor::Black && contains(w_pieces, piece)) {
        return false;
    }
    else if(!isBottomTimerActive && ChessBoard::getPieceColor() != PieceColor::Black && contains(w_pieces, piece)) {
        return false;
    }
    else if(!isBottomTimerActive && ChessBoard::getPieceColor() == PieceColor::Black && contains(b_pieces, piece)) {
        return false;
    }
    return true;
}

PieceColor ChessBoard::m_pieceColor = PieceColor::NoColor;

PieceColor ChessBoard::decidePieceColor() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 2);

    int option = dis(gen);
    return m_pieceColor = option == 1 ? PieceColor::White : PieceColor::Black;
}

PieceColor ChessBoard::getPieceColor() {
    return m_pieceColor;
}

std::map<posFileRank, ChessPiece> ChessBoard::m_chessBoard = ChessBoard::initializeBoard(decidePieceColor());
