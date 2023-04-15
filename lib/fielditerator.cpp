#include "fielditerator.hpp"

FieldIterator::FieldIterator(posXY sourcePos) :
    m_sourcePos(sourcePos),
    m_currentPos(m_sourcePos)
{
    checkLimits();
}

void FieldIterator::checkLimits() {
    if(m_sourcePos.first == 8) {
        m_rightLimit = true;
    }
    else {
        m_rightLimit = false;
    }

    if(m_sourcePos.first == 1) {
        m_leftLimit = true;
    }
    else {
        m_leftLimit = false;
    }

    if(m_sourcePos.second == 8) {
        m_upLimit = true;
    }
    else {
        m_upLimit = false;
    }

    if(m_sourcePos.second == 1) {
        m_downLimit = true;
    }
    else {
        m_downLimit = false;
    }
}

posXY FieldIterator::getCurrentPos() const {
    return m_currentPos;
}

posXY FieldIterator::getSourcePos() const {
    return m_sourcePos;
}

void FieldIterator::moveRight() {
    m_direction = Direction::Right;
    if(m_currentPos.first == 8) {
        m_rightLimit = true;
        return;
    }

    m_currentPos.first++;
    if(m_leftLimit) {
        m_leftLimit = false;
    }
}

void FieldIterator::moveLeft() {
    m_direction = Direction::Left;
    if(m_currentPos.first == 1) {
        m_leftLimit = true;
        return;
    }

    m_currentPos.first--;
    if(m_rightLimit) {
        m_rightLimit = false;
    }
}

void FieldIterator::moveUp() {
    m_direction = Direction::Up;
    if(m_currentPos.second == 8) {
        m_upLimit = true;
        return;
    }

    m_currentPos.second++;
    if(m_downLimit) {
        m_downLimit = false;
    }
}

void FieldIterator::moveDown() {
    m_direction = Direction::Down;
    if(m_currentPos.second == 1) {
        m_downLimit = true;
        return;
    }

    m_currentPos.second--;
    if(m_upLimit) {
        m_upLimit = false;
    }
}

void FieldIterator::moveDiagonalUpRight() {
    m_direction = Direction::DiagonalUpRight;
    if(m_currentPos.second == 8) {
        m_upLimit = true;
    }
    if(m_currentPos.first == 8) {
        m_rightLimit = true;
    }

    m_currentPos.first++;
    m_currentPos.second++;
    if(m_downLimit) {
        m_downLimit = false;
    }
    if(m_leftLimit) {
        m_leftLimit = false;
    }
}

void FieldIterator::moveDiagonalUpLeft() {
    m_direction = Direction::DiagonalUpLeft;
    if(m_currentPos.second == 8) {
        m_upLimit = true;
    }
    if(m_currentPos.first == 1) {
        m_leftLimit = true;
    }

    m_currentPos.first--;
    m_currentPos.second++;
    if(m_downLimit) {
        m_downLimit = false;
    }
    if(m_rightLimit) {
        m_rightLimit = false;
    }
}

void FieldIterator::moveDiagonalDownRight() {
    m_direction = Direction::DiagonalDownRight;
    if(m_currentPos.second == 1) {
        m_downLimit = true;
    }
    if(m_currentPos.first == 8) {
        m_rightLimit = true;
    }

    m_currentPos.first++;
    m_currentPos.second--;
    if(m_upLimit) {
        m_upLimit = false;
    }
    if(m_leftLimit) {
        m_leftLimit = false;
    }
}

void FieldIterator::moveDiagonalDownLeft() {
    m_direction = Direction::DiagonalDownLeft;
    if(m_currentPos.second == 1) {
        m_downLimit = true;
    }
    if(m_currentPos.first == 1) {
        m_leftLimit = true;
    }

    m_currentPos.first--;
    m_currentPos.second--;
    if(m_upLimit) {
        m_upLimit = false;
    }
    if(m_rightLimit) {
        m_rightLimit = false;
    }
}

void FieldIterator::moveToSourcePos() {
    m_currentPos = m_sourcePos;
    checkLimits();
}

void FieldIterator::moveTo(posXY pos) {
    m_currentPos = pos;
    checkLimits();
}

FieldIterator::operator bool() const {
    if(m_direction == Direction::Right && m_rightLimit) {
        return false;
    }
    else if(m_direction == Direction::Left && m_leftLimit) {
        return false;
    }
    else if(m_direction == Direction::Up && m_upLimit) {
        return false;
    }
    else if(m_direction == Direction::Down && m_downLimit) {
        return false;
    }
    else if(m_direction == Direction::DiagonalUpRight && (m_upLimit || m_rightLimit) ) {
        return false;
    }
    else if(m_direction == Direction::DiagonalUpLeft && (m_upLimit || m_leftLimit)) {
        return false;
    }
    else if(m_direction == Direction::DiagonalDownRight && (m_downLimit || m_rightLimit)) {
        return false;
    }
    else if(m_direction == Direction::DiagonalDownLeft && (m_downLimit || m_leftLimit)) {
        return false;
    }
    return true;
}
