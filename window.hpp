#pragma once

#include <QMainWindow>
#include <memory>
#include <vector>
#include <string>
#include "chesstypes.hpp"

class ChessSquare;

QT_BEGIN_NAMESPACE
namespace Ui { class window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

    void updateBoard();
private:
    Ui::window *ui;
    void allowClicks();

    ChessSquare* m_sourceButton;
    QIcon m_sourceButtonIcon;
    std::vector<std::string> m_fieldNames;
    void highlightValidMoves(ChessPiece piece, posFileRank sourcePos);
    std::vector<posFileRank> m_validMoves;
    void changeValidButtonsToDefaultColor();
    std::vector<std::pair<posFileRank, QString>> m_originalStyleSheets;
private slots:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};
