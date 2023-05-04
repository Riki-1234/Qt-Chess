#pragma once

#include <QMainWindow>
#include <memory>
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
    void timeChangeTopTimer();
    void timeChangeBottomTimer();
    void changeValidButtonsToDefaultColor();
    void highlightValidMoves(ChessPiece piece, posFileRank sourcePos);
    void setupTimers();
    void startOneStopOtherTimer();
    void setUnderLinesInvisible();

    ChessSquare* m_sourceButton;
    QIcon m_sourceButtonIcon;
    std::vector<std::string> m_fieldNames;
    std::vector<posFileRank> m_validMoves;
    std::vector<std::pair<posFileRank, QString>> m_originalStyleSheets;
    QTimer* m_topTimer;
    QTimer* m_bottomTimer;
    int m_remainingTimeTop = 20 * 60;
    int m_remainingTimeBottom = 20 * 60;
    ChessPiece m_king = ChessPiece::NoPiece;
private slots:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};
