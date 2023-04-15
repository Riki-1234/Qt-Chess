#include <memory>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QString>
#include <QFile>
#include "window.hpp"
#include "chessboard.hpp"
#include "./ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window)
{
    ui->setupUi(this);

    allowClicks();

    m_sourceButton = nullptr;

    for(int i = 0; i < m_files.length(); i++) {
        for(int j = 0; j < m_ranks.length(); j++) {
            m_fieldNames.push_back(std::string(1, m_files[i]) + std::string(1, m_ranks[j]));
        }
    }
    updateBoard();
}

void Window::mousePressEvent(QMouseEvent* event) {
    qDebug() << "Press event is called at position: " << QCursor::pos();

    QPoint buttonPos = ui->centralwidget->mapFromGlobal(QCursor::pos());
    QList<ChessSquare*> buttons = ui->centralwidget->findChildren<ChessSquare*>();
    for (ChessSquare* button : buttons) {
        if (button->geometry().contains(buttonPos)) {
            m_sourceButton = button;
            break;
        }
    }
    qDebug() << m_sourceButton;

    highlightValidMoves(m_sourceButton->getPieceOnSquare(), m_sourceButton->squarePosition());
    QPixmap pixmap(m_sourceButton->icon().pixmap(m_sourceButton->iconSize()));
    QCursor cursor(pixmap);
    setCursor(cursor);

    m_sourceButtonIcon = m_sourceButton->icon();
    qDebug() << "Chess piece: " << m_sourceButton->getPieceOnSquareName() << Qt::endl;
    m_sourceButton->setIcon(QIcon());
}

void Window::mouseReleaseEvent(QMouseEvent* event) {
    qDebug() << "Release event is called at position: " << QCursor::pos();
    unsetCursor();

    ChessSquare* targetButton = nullptr;
    QPoint buttonPos = ui->centralwidget->mapFromGlobal(QCursor::pos());
    QList<ChessSquare*> buttons = ui->centralwidget->findChildren<ChessSquare*>();
    for (ChessSquare* button : buttons) {
        if (button->geometry().contains(buttonPos)) {
            targetButton = button;
            break;
        }
    }
    qDebug() << targetButton << Qt::endl;

    if(targetButton && targetButton != m_sourceButton
       && targetButton->styleSheet() == "color: rgb(107,107,110);"
                                        "background-color: rgb(255, 255, 224);"
                                        "border-radius: 0px;"
                                        "padding: 10px;"
                                        "border: 2px solid rgb(211, 211, 211);") {
        targetButton->setIcon(m_sourceButtonIcon);
        targetButton->setPieceOnSquare(m_sourceButton->getPieceOnSquare());
        m_sourceButton->setPieceOnSquare(ChessPiece::NoPiece);
        ChessBoard::m_chessBoard[targetButton->squarePosition()] = ChessBoard::m_chessBoard[m_sourceButton->squarePosition()];
        ChessBoard::m_chessBoard[m_sourceButton->squarePosition()] = ChessPiece::NoPiece;
    }
    else {
        m_sourceButton->setIcon(QIcon(m_sourceButtonIcon));
    }
    changeValidButtonsToDefaultColor();
}

void Window::allowClicks() {
    const auto& children = ui->centralwidget->children();
    for(const auto& child : children) {
        const auto& button = qobject_cast<ChessSquare*>(child);
        if(button && button->objectName().contains("field_")) {
            button->setAttribute(Qt::WA_TransparentForMouseEvents);
            button->setWindowFlags(Qt::WindowTransparentForInput);
        }
    }
}

void Window::updateBoard() {
    const auto& children = ui->centralwidget->children();
    for(const auto& child : children) {
        const auto& button = qobject_cast<ChessSquare*>(child);
        for(const auto& fieldName : m_fieldNames) {
            if(button && button->objectName().contains(QString::fromStdString("field_") + QString::fromStdString(fieldName))) {
                if(ChessBoard::m_chessBoard[fieldName] != button->getPieceOnSquare()) {
                    button->setPieceOnSquare(ChessBoard::m_chessBoard[fieldName]);
                }
            }
        }
    }
}

void Window::highlightValidMoves(ChessPiece piece, posFileRank sourcePos) {
    m_validMoves = ChessBoard::getValidMoves(ChessBoard::posFileRankToPosXY(sourcePos), piece);
    const auto& children = ui->centralwidget->children();
    for(const auto& child : children) {
        const auto& button = qobject_cast<ChessSquare*>(child);
        for(int i = 0; i < m_validMoves.size(); i++) {
            if(button && button->objectName().contains("field_" + QString::fromStdString(m_validMoves[i]))) {
                m_originalStyleSheets.push_back({m_validMoves[i], button->styleSheet()});
                button->setStyleSheet("color: rgb(107,107,110);"
                                      "background-color: rgb(255, 255, 224);"
                                      "border-radius: 0px;"
                                      "padding: 10px;"
                                      "border: 2px solid rgb(211, 211, 211);");
            }
        }
    }
}

void Window::changeValidButtonsToDefaultColor() {
    const auto& children = ui->centralwidget->children();
    for(const auto& child : children) {
        const auto& button = qobject_cast<ChessSquare*>(child);
        for(int i = 0; i < m_originalStyleSheets.size(); i++) {
            if(button && button->objectName().contains("field_" + QString::fromStdString(m_originalStyleSheets[i].first))) {
                button->setStyleSheet(m_originalStyleSheets[i].second);
                break;
            }
        }
    }
}

Window::~Window()
{
    delete ui;
}
