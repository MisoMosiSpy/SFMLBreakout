// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"

class Border : public sf::Drawable {

public:

    Border(float borderSize, sf::Vector2f windowSize, bool top, bool bottom, bool left, bool right);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:

    bool isBorderActive(sf::RectangleShape r) {
        sf::Vector2f size = r.getSize();
        return (size.x == 0 || size.y == 0) ? false : true;
    }

    sf::RectangleShape m_topBorder;
    sf::RectangleShape m_bottomBorder;
    sf::RectangleShape m_leftBorder;
    sf::RectangleShape m_rightBorder;
};