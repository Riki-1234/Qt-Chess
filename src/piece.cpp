#include "piece.hpp"

bool Piece::isFriendly(ChessPiece sourcePiece, ChessPiece destPiece) {
    if (std::count(w_pieces.begin(), w_pieces.end(), sourcePiece) && std::count(w_pieces.begin(), w_pieces.end(), destPiece)
       || std::count(b_pieces.begin(), b_pieces.end(), sourcePiece) && std::count(b_pieces.begin(), b_pieces.end(), destPiece)) {
        return true;
    }
    return false;
}
