// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "ball.h"

#include <iostream>

Ball::Ball(BallType t) : SpriteEx() {
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
        m_lives--;
        if (m_lives > 0) {
            reset();
        } else {
            // TODO: handle lives.
            std::exit(-1);
        }
    }

    setPosition(pos);
}

bool Ball::checkCollision(const SpriteEx& other) {

    sf::FloatRect ballPos{getGlobalBounds().getPosition(), getGlobalBounds().getSize()};
    sf::FloatRect otherPos{other.getGlobalBounds().getPosition(),
                           other.getGlobalBounds().getSize()};

    // Check if the sprites are colliding
    if (ballPos.intersects(otherPos)) {

        float overlapX = 0.0f;
        float overlapY = 0.0f;

        // Calculate horizontal overlap based on the direction of movement
        if (m_speed.x > 0) {
            overlapX = getRight() - other.getLeft();
        } else {
            overlapX = other.getRight() - getLeft();
        }

        // Calculate Vertical overlap based on the direction of movement
        if (m_speed.y > 0) {
            overlapY = getBottom() - other.getTop();
        } else {
            overlapY = other.getBottom() - getTop();
        }

        sf::Vector2f pos = getPosition();
        // Check which overlap is smaller, we will take that as overlap direction
        if (overlapX > overlapY) {

            m_speed.y *= -1;

            // Set ball postion (top) flush to the edge of the collided object in the
            // direction of the movement
            pos.y = (m_speed.y > 0) ? other.getBottom() : (other.getTop() - getHeight());
        } else {

            m_speed.x *= -1;

            // Set ball postion (left) flush to the edge of the collided object in the
            // direction of the movement
            pos.x = (m_speed.x > 0) ? other.getRight() : (other.getLeft() - getWidth());
        }

        setPosition(pos);

        return true;
    }

    return false;
}
