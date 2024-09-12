// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "ball.h"

#include <iostream>

Ball::Ball(BallType t) : Sprite() {
    std::string fileName;
    if (t == BallType::Gray) {
        fileName = "resources/ballGrey.png";
    } else if (t == BallType::Blue) {
        fileName = "resources/ballBlue.png";
    }

    if (!m_texture.loadFromFile(fileName)) {
        std::cerr << "Unable to load texture " << fileName << std::endl;
        std::cerr << "Quitting..." << std::endl;
        std::exit(-1);
    }
    setTexture(m_texture);
}

void Ball::update(void) {
    setPosition(getPosition() + m_speed);

    // Keep the ball inside window (and border)
    checkWindowCollision();
}

void Ball::checkWindowCollision() {

    sf::Vector2f pos = getPosition();

    // Check collision with top and bottom
    if (pos.x <= g_borderSize || (pos.x + getGlobalBounds().width + g_borderSize) > g_winWidth) {
        m_speed.x *= -1.0f;
        // Set ball postion (left) flush to the edge in the direction of the movement
        pos.x = (m_speed.x >= 0.0) ? g_borderSize
                                   : (g_winWidth - g_borderSize - getGlobalBounds().width);
    }

    // Check collision with top edge
    if (pos.y <= g_borderSize) {
        m_speed.y *= -1.0f;
        // Set ball postion (top) flush to the edge in the direction of the movement
        pos.y = g_borderSize;
    }

    // Check collision with bottom, it means we lost life
    if ((pos.y + getGlobalBounds().height) > g_winHeight) {
        // TODO: handle lives.
        std::exit(-1);
    }

    setPosition(pos);
}

void Ball::checkCollision(sf::Sprite& other) {

    sf::FloatRect ballPos{getGlobalBounds().getPosition(), getGlobalBounds().getSize()};
    sf::FloatRect otherPos{other.getGlobalBounds().getPosition(),
                           other.getGlobalBounds().getSize()};

    // Check if the sprites are colliding
    if (ballPos.intersects(otherPos)) {

        float overlapX = 0.0f;
        float overlapY = 0.0f;

        // Calculate horizontal overlap based on the direction of movement
        if (m_speed.x > 0) {
            overlapX = (ballPos.left + ballPos.width) - otherPos.left;
        } else {
            overlapX = (otherPos.left + otherPos.width) - ballPos.left;
        }

        // Calculate Vertical overlap based on the direction of movement
        if (m_speed.y > 0) {
            overlapY = (ballPos.top + ballPos.height) - otherPos.top;
        } else {
            overlapY = (otherPos.top + otherPos.height) - ballPos.top;
        }

        sf::Vector2f pos = getPosition();
        // Check which overlap is smaller, we will take that as overlap direction
        if (overlapX > overlapY) {

            m_speed.y *= -1;

            // Set ball postion (top) flush to the edge of the collided object in the
            // direction of the movement
            pos.y = (m_speed.y > 0) ? (otherPos.top + otherPos.height)
                                    : (otherPos.top - ballPos.height);
        } else {

            m_speed.x *= -1;

            // Set ball postion (left) flush to the edge of the collided object in the
            // direction of the movement
            pos.x = (m_speed.x > 0) ? (otherPos.left + otherPos.width)
                                    : (otherPos.left - ballPos.width);
        }

        setPosition(pos);
    }
}
