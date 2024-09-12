// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "paddle.h"

#include <iostream>

Paddle::Paddle(PaddleType t) : SpriteEx() {
    m_paddleType = t;

    std::string fileName;

    if (m_paddleType == PaddleType::Blue) {
        fileName = "resources/paddleBlu.png";
    } else {
        fileName = "resources/paddleRed.png";
    }

    if (!m_texture.loadFromFile(fileName)) {
        std::cerr << "Unable to load texture " << fileName << std::endl;
        std::cerr << "Quitting..." << std::endl;
        std::exit(-1);
    }
    setTexture(m_texture);
    setPosition(g_winWidth / 2 - getWidth() / 2, g_winHeight - (getHeight() * 2));
}

void Paddle::update() {

    sf::Vector2f currentPos = getPosition();
    sf::Vector2f movement{0, 0};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x = -m_speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x = m_speed;
    }

    sf::Vector2f newPos = currentPos + movement;

    // Check left side collision
    if (newPos.x < g_borderSize) newPos.x = g_borderSize;

    // Check right side collision
    if (newPos.x + getWidth() > (g_winWidth - g_borderSize))
        newPos.x = static_cast<float>((g_winWidth - g_borderSize) - getWidth());

    setPosition(newPos);
}