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

std::vector<posFileRank> ChessBoard::getValidMoves(posXY sourcePosXY, ChessPiece piece) {
    std::vector<posFileRank> validMoves;
    if(piece == ChessPiece::W_Bishop || piece == ChessPiece::B_Bishop) {
        Bishop bishop;
        validMoves = bishop.getValidMoves(sourcePosXY);
    }
    else if(piece == ChessPiece::W_Rook || piece == ChessPiece::B_Rook) {
        Rook rook;
        validMoves = rook.getValidMoves(sourcePosXY);
    }
    else if(piece == ChessPiece::W_Queen || piece == ChessPiece::B_Queen) {
        Queen queen;
        validMoves = queen.getValidMoves(sourcePosXY);
    }
    else if(piece == ChessPiece::W_Knight || piece == ChessPiece::B_Knight) {
        Knight knight;
        validMoves = knight.getValidMoves(sourcePosXY);
    }
    else if(piece == ChessPiece::W_King || piece == ChessPiece::B_King) {
        King king;
        validMoves = king.getValidMoves(sourcePosXY);
    }
    else if(piece == ChessPiece::W_Pawn || piece == ChessPiece::B_Pawn) {
        Pawn pawn;
        validMoves = pawn.getValidMoves(sourcePosXY);
    }
    return validMoves;
}

std::map<posFileRank, ChessPiece> ChessBoard::m_chessBoard = ChessBoard::initializeBoard();
