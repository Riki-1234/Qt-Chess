#pragma once

#include <QPushButton>
#include <QMainWindow>
#include "chesstypes.hpp"

enum class Direction {
    Right,
    Left,
    Up,
    Down,
    DiagonalUpRight,
    DiagonalUpLeft,
    DiagonalDownRight,
    DiagonalDownLeft
};

class FieldIterator
{
public:
    FieldIterator(posXY sourcePos);
    explicit operator bool() const;

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void moveDiagonalUpLeft();
    void moveDiagonalUpRight();
    void moveDiagonalDownLeft();
    void moveDiagonalDownRight();

    void moveToSourcePos();
    void moveTo(posXY pos);
    void checkLimits();

    posXY getCurrentPos() const;
    posXY getSourcePos() const;
private:
    posXY m_sourcePos;
    posXY m_currentPos;
    bool m_rightLimit{false};
    bool m_leftLimit{false};
    bool m_upLimit{false};
    bool m_downLimit{false};
    Direction m_direction{NULL};
};
