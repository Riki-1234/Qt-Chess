#pragma once

#include <algorithm>
#include <string>
#include <vector>

static const std::string m_files = "ABCDEFGH";
static const std::string m_ranks = "12345678";

typedef std::string posFileRank;
typedef std::pair<uint8_t, uint8_t> posXY;

enum class ChessPiece {
    NoPiece,
    W_Queen,
    B_Queen,
    W_King,
    B_King,
    W_Rook,
    B_Rook,
    W_Bishop,
    B_Bishop,
    W_Knight,
    B_Knight,
    W_Pawn,
    B_Pawn
};

static const std::vector<ChessPiece> w_pieces {
    ChessPiece::W_King, ChessPiece::W_Queen, ChessPiece::W_Bishop, ChessPiece::W_Knight, ChessPiece::W_Rook, ChessPiece::W_Pawn
};
static const std::vector<ChessPiece> b_pieces {
    ChessPiece::B_King, ChessPiece::B_Queen, ChessPiece::B_Bishop, ChessPiece::B_Knight, ChessPiece::B_Rook, ChessPiece::B_Pawn
};

template<typename T>
bool contains(const std::vector<T>& vec, const T& element) {
    if(std::count(vec.begin(), vec.end(), element)) {
        return true;
    }
    return false;
}
