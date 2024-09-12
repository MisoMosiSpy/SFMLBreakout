// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "border.h"

Border::Border(float borderSize, sf::Vector2f windowSize, bool top, bool bottom, bool left,
               bool right) {

    float width = windowSize.x;
    float height = windowSize.y;

    if (top) {
        m_topBorder.setSize(sf::Vector2f{width, borderSize});
        m_topBorder.setPosition(0, 0);
    }

    if (bottom) {
        m_bottomBorder.setSize(sf::Vector2f{width, borderSize});
        m_bottomBorder.setPosition(0, height - borderSize);
    }

    if (left) {
        m_leftBorder.setSize(sf::Vector2f{borderSize, height});
        m_leftBorder.setPosition(0, 0);
    }

    if (right) {
        m_rightBorder.setSize(sf::Vector2f{borderSize, height});
        m_rightBorder.setPosition(width - borderSize, 0);
    }
}

void Border::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    if (m_leftBorder.getSize().x > 0) target.draw(m_leftBorder);

    if (m_rightBorder.getSize().x > 0) target.draw(m_rightBorder);

    if (m_topBorder.getSize().y > 0) target.draw(m_topBorder);

    if (m_bottomBorder.getSize().y > 0) target.draw(m_bottomBorder);
}
