#include "chesssquare.hpp"

ChessSquare::ChessSquare(QWidget *parent) : QPushButton(parent) {
    setPieceOnSquare(ChessPiece::NoPiece);
}

std::map<ChessPiece, QString> ChessSquare::m_chessPieceImages = {
    {ChessPiece::NoPiece, ""},
    {ChessPiece::W_Queen, "assets/pieces/w_queen.png"},
    {ChessPiece::B_Queen, "assets/pieces/b_queen.png"},
    {ChessPiece::W_King, "assets/pieces/w_king.png"},
    {ChessPiece::B_King, "assets/pieces/b_king.png"},
    {ChessPiece::W_Rook, "assets/pieces/w_rook.png"},
    {ChessPiece::B_Rook, "assets/pieces/b_rook.png"},
    {ChessPiece::W_Bishop, "assets/pieces/w_bishop.png"},
    {ChessPiece::B_Bishop, "assets/pieces/b_bishop.png"},
    {ChessPiece::W_Knight, "assets/pieces/w_knight.png"},
    {ChessPiece::B_Knight, "assets/pieces/b_knight.png"},
    {ChessPiece::W_Pawn, "assets/pieces/w_pawn.png"},
    {ChessPiece::B_Pawn, "assets/pieces/b_pawn.png"}
};

void ChessSquare::setPieceOnSquare(ChessPiece piece) {
    m_pieceOnSquare = piece;
    updateImage();
}

void ChessSquare::updateImage() {
    setIcon(QIcon(m_chessPieceImages.at(m_pieceOnSquare)));
    setIconSize(QSize(48, 256));
}

ChessPiece ChessSquare::getPieceOnSquare() const {
    return m_pieceOnSquare;
}

QString ChessSquare::getPieceOnSquareName() const {
    QString pieceName = m_chessPieceImages.at(m_pieceOnSquare);
    if(pieceName.contains('/')) {
        size_t nameStartIndex = pieceName.lastIndexOf('/');
        pieceName.remove(0, nameStartIndex + 1);
    }
    return pieceName;
}

std::string ChessSquare::squarePosition() const {
    std::string position = objectName().toStdString();
    position.erase(0, 6);
    return position;
}
