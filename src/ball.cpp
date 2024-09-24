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

    // Line to indicate the direction of the ball movement
    // We set its length to 3 times the ball size and set
    // its origin such that it rotates from the center of the
    // ball.
    m_dirLine.setSize(sf::Vector2f{getWidth() * 3, 4});
    m_dirLine.setOrigin(0, m_dirLine.getSize().y / 2);
    m_dirLine.setFillColor(sf::Color::Red);

    reset();
}

void Ball::update(float dt, sf::Vector2f playerMidTop) {

    // If ball is moving update its position as per current speed
    // If it is not yet moving, update its position as per player's postion
    if (isMoving()) {
        setPosition(getPosition() + (m_speed * dt));
        checkWindowCollision();
    } else {
        setPosition(playerMidTop.x - (getWidth() / 2), playerMidTop.y - getHeight());
        m_dirLine.setPosition(getCenter());
        m_dirLine.setRotation(atan2f(m_speed.y, m_speed.x) * (180 / 3.14f));
    }
}

void Ball::checkWindowCollision() {

    sf::Vector2f pos = getPosition();

    // Check collision with top and bottom
    if (pos.x <= g_borderSize || (pos.x + getWidth() + g_borderSize) > g_winWidth) {
        m_speed.x *= -1.0f;
        // Set ball postion (left) flush to the edge in the direction of the movement
        pos.x = (m_speed.x >= 0.0) ? g_borderSize : (g_winWidth - g_borderSize - getWidth());
    }

    // Check collision with top edge
    if (pos.y <= g_borderSize) {
        m_speed.y *= -1.0f;
        // Set ball postion (top) flush to the edge in the direction of the movement
        pos.y = g_borderSize;
    }

    // Check collision with bottom, it means we lost life
    if ((pos.y + getHeight()) > g_winHeight) {
        m_lives--;
        if (m_lives > 0) {
            reset();
        } else {
            std::exit(-1);
        }
    }

    setPosition(pos);
}

bool Ball::checkCollision(const SpriteEx& other) {

    // Check if the sprites are colliding
    if (getGlobalBounds().intersects(other.getGlobalBounds())) {

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

void Ball::draw(sf::RenderWindow& window) const {
    window.draw(*this);

    if (!isMoving()) window.draw(m_dirLine);
}

void Ball::setAngle(int angle) {
    m_angle = angle;
    m_speed.x = cos(m_angle * (3.14f / 180)) * g_ballSpeed;
    m_speed.y = sin(m_angle * (3.14f / 180)) * g_ballSpeed;
}
