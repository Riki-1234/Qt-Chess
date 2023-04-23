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

posFileRank Piece::getSourcePosFileRank(const FieldIterator& iterator) {
    return ChessBoard::posXYToPosFileRank(iterator.getSourcePos());
}

ChessPiece Piece::getPieceAtPos(posFileRank position) {
    return ChessBoard::m_chessBoard[position];
}

void Piece::setPieceAtPos(posFileRank position, ChessPiece newPiece) {
    ChessBoard::m_chessBoard[position] = newPiece;
}

bool Piece::isEnPassant(ChessPiece firstPawn, posFileRank firstPawnPos, posFileRank secondPawnPos) {
    if(firstPawnPos[1] == '4' && secondPawnPos[1] == '4' && std::count(w_pieces.begin(), w_pieces.end(), firstPawn)) {
        return true;
    }
    else if(firstPawnPos[1] == '5' && secondPawnPos[1] == '5' && std::count(w_pieces.begin(), w_pieces.end(), firstPawn)) {
        return true;
    }
    return false;
}
