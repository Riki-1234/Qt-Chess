#pragma once

#include <QPushButton>
#include <map>
#include "chesstypes.hpp"

class ChessSquare : public QPushButton
{
    Q_OBJECT
public:
    ChessSquare(QWidget *parent = nullptr);

    void setPieceOnSquare(ChessPiece piece);
    ChessPiece getPieceOnSquare() const;
    QString getPieceOnSquareName() const;
    std::string squarePosition() const;
private:
    static std::map<ChessPiece, QString> m_chessPieceImages;
    ChessPiece m_pieceOnSquare;
    void updateImage();
};
