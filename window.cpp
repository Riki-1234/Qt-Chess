#include <memory>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QString>
#include <QFile>
#include <QTimer>
#include <QThread>
#include "window.hpp"
#include "chessboard.hpp"
#include "piece.hpp"
#include "chessgame.hpp"
#include "./ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window)
{
    ui->setupUi(this);
    ui->centralwidget->setMinimumWidth(967);
    ui->centralwidget->setMinimumHeight(739);

    allowClicks();
    setUnderLinesInvisible();
    setupTimers();

    m_sourceButton = nullptr;

    for(int i = 0; i < m_files.length(); i++) {
        for(int j = 0; j < m_ranks.length(); j++) {
            m_fieldNames.push_back(std::string(1, m_files[i]) + std::string(1, m_ranks[j]));
        }
    }
    updateBoard();
}

void Window::mousePressEvent(QMouseEvent* event) {
    if(event->button() == Qt::RightButton) {
        m_sourceButton->setIcon(QIcon(m_sourceButtonIcon));
    }

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

    if(contains(w_pieces, m_sourceButton->getPieceOnSquare())) {
        m_king = ChessPiece::W_King;
    }
    else {
        m_king = ChessPiece::B_King;
    }

    if(!ChessBoard::isMovePossible(m_topTimer->isActive(), m_bottomTimer->isActive(), m_sourceButton->getPieceOnSquare(), m_king)) {
        return;
    }
    highlightValidMoves(m_sourceButton->getPieceOnSquare(), m_sourceButton->squarePosition());
    QPixmap pixmap(m_sourceButton->icon().pixmap(m_sourceButton->iconSize()));
    QCursor cursor(pixmap);
    setCursor(cursor);

    m_sourceButtonIcon = m_sourceButton->icon();
    qDebug() << "Chess piece: " << m_sourceButton->getPieceOnSquareName() << Qt::endl;
    m_sourceButton->setIcon(QIcon());
}

void Window::mouseReleaseEvent(QMouseEvent* event) {
    if(!ChessBoard::isMovePossible(m_topTimer->isActive(), m_bottomTimer->isActive(), m_sourceButton->getPieceOnSquare(), m_king)) {
        return;
    }

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
        Piece::setPieceAtPos(targetButton->squarePosition(), Piece::getPieceAtPos(m_sourceButton->squarePosition()));
        Piece::setPieceAtPos(m_sourceButton->squarePosition(), ChessPiece::NoPiece);

        if(ChessGame::getCurrentPlayer() == PieceColor::White) {
            ChessGame::setCurrentPlayer(PieceColor::Black);
        }
        else {
            ChessGame::setCurrentPlayer(PieceColor::White);
        }
        startOneStopOtherTimer();

        if(ChessGame::isCheckMate(ChessPiece::B_King)) {
            ui->outcome->setText("White won");
            if(m_topTimer->isActive()) {
                m_topTimer->stop();
                if(ui->topLine->isVisible()) {
                    ui->topLine->setVisible(false);
                }
            }
            if(m_bottomTimer->isActive()) {
                m_bottomTimer->stop();
                if(ui->bottomLine->isVisible()) {
                    ui->bottomLine->setVisible(false);
                }
            }
        }
        else if(ChessGame::isCheckMate(ChessPiece::W_King)) {
            ui->outcome->setText("Black won");
            if(m_topTimer->isActive()) {
                m_topTimer->stop();
                if(ui->topLine->isVisible()) {
                    ui->topLine->setVisible(false);
                }
            }
            if(m_bottomTimer->isActive()) {
                m_bottomTimer->stop();
                if(ui->bottomLine->isVisible()) {
                    ui->bottomLine->setVisible(false);
                }
            }
        }
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
                if(Piece::getPieceAtPos(fieldName) != button->getPieceOnSquare()) {
                    button->setPieceOnSquare(Piece::getPieceAtPos(fieldName));
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
            if(Piece::getPieceAtPos(m_validMoves[i]) == ChessPiece::B_King || Piece::getPieceAtPos(m_validMoves[i]) == ChessPiece::W_King) {
                continue;
            }
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

void Window::timeChangeTopTimer() {
    m_remainingTimeTop--;
    if(m_remainingTimeTop == 0) {
        m_topTimer->stop();
        ui->topLine->setVisible(false);
        if(ChessBoard::getPieceColor() == PieceColor::Black) {
            ui->outcome->setText("Black won");
        }
        else {
            ui->outcome->setText("White won");
        }
    }

    int minutes = m_remainingTimeTop / 60;
    int seconds = m_remainingTimeTop % 60;

    QString timeString = QString("%1:%2")
                              .arg(minutes, 2, 10, QLatin1Char('0'))
                              .arg(seconds, 2, 10, QLatin1Char('0'));
    ui->topTimer->setText(timeString);
}

void Window::timeChangeBottomTimer() {
    m_remainingTimeBottom--;
    if(m_remainingTimeBottom == 0) {
        m_bottomTimer->stop();
        ui->bottomLine->setVisible(false);
        if(ChessBoard::getPieceColor() == PieceColor::Black) {
            ui->outcome->setText("White won");
        }
        else {
            ui->outcome->setText("Black won");
        }
    }

    int minutes = m_remainingTimeBottom / 60;
    int seconds = m_remainingTimeBottom % 60;

    QString timeString = QString("%1:%2")
                              .arg(minutes, 2, 10, QLatin1Char('0'))
                              .arg(seconds, 2, 10, QLatin1Char('0'));
    ui->bottomTimer->setText(timeString);
}

void Window::setupTimers() {
    m_topTimer = new QTimer(this);
    connect(m_topTimer, &QTimer::timeout, this, &Window::timeChangeTopTimer);
    int minutes = m_remainingTimeTop / 60;
    int seconds = m_remainingTimeTop % 60;

    QString timeString = QString("%1:%2")
                              .arg(minutes, 2, 10, QLatin1Char('0'))
                              .arg(seconds, 2, 10, QLatin1Char('0'));
    ui->topTimer->setText(timeString);

    m_bottomTimer = new QTimer(this);
    connect(m_bottomTimer, &QTimer::timeout, this, &Window::timeChangeBottomTimer);
    minutes = m_remainingTimeBottom / 60;
    seconds = m_remainingTimeBottom % 60;

    timeString = QString("%1:%2")
                              .arg(minutes, 2, 10, QLatin1Char('0'))
                              .arg(seconds, 2, 10, QLatin1Char('0'));
    ui->bottomTimer->setText(timeString);


    if(ChessBoard::getPieceColor() == PieceColor::Black) {
        m_topTimer->start(1000);
        ui->topLine->setVisible(true);
    }
    else {
        m_bottomTimer->start(1000);
        ui->bottomLine->setVisible(true);
    }
}

void Window::startOneStopOtherTimer() {
    if(m_topTimer->isActive()) {
        m_topTimer->stop();
        ui->topLine->setVisible(false);
        m_bottomTimer->start(1000);
        ui->bottomLine->setVisible(true);
    }
    else {
        m_bottomTimer->stop();
        ui->bottomLine->setVisible(false);
        m_topTimer->start(1000);
        ui->topLine->setVisible(true);
    }
}

void Window::setUnderLinesInvisible() {
    ui->topLine->setVisible(false);
    ui->bottomLine->setVisible(false);
}

Window::~Window()
{
    delete ui;
}
