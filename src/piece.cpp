#include "piece.hpp"

bool Piece::isFriendly(ChessPiece sourcePiece, ChessPiece destPiece) {
    if(contains(w_pieces, sourcePiece) && contains(w_pieces, destPiece) || contains(b_pieces, sourcePiece) && contains(b_pieces, destPiece)) {
        return true;
    }
    return false;
}

ChessPiece Piece::getSourcePiece(const FieldIterator& iterator) {
    return ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(iterator.getSourcePos())];
}

ChessPiece Piece::getDestPiece(const FieldIterator& iterator) {
    return ChessBoard::m_chessBoard[ChessBoard::posXYToPosFileRank(iterator.getCurrentPos())];
}

posFileRank Piece::getCurrentPosFileRank(const FieldIterator& iterator) {
    return ChessBoard::posXYToPosFileRank(iterator.getCurrentPos());
}
