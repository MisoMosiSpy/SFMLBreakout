// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "config.h"
#include "spriteEx.h"

class Ball : public SpriteEx {

public:

    Ball(BallType t);

    void update(float dt, sf::Vector2f playerPos);

    void draw(sf::RenderWindow& window) const;

    bool checkCollision(const SpriteEx& other);

    void setSpeed(sf::Vector2f speed) {
        m_speed = speed;
        m_angle = static_cast<int>(atan2f(m_speed.y, m_speed.x) * (180 / 3.14f));
    }

    void setMoving(bool isMoving) { m_isMoving = isMoving; }

    bool isMoving() const { return m_isMoving == true; }

    void changeAngle(int delta) {
        int newAngle = m_angle + delta;

        if (newAngle <= -5 && newAngle >= -175) setAngle(newAngle);
    }

    void setAngle(int angle);

private:

    void checkWindowCollision();

    void reset() {
        setAngle(g_defaultAngle);
        m_isMoving = false;
    }

private:

    BallType m_ballType{};
    sf::Texture m_texture{};
    sf::Vector2f m_speed{};
    int m_lives{g_playerLives};
    bool m_isMoving{};
    int m_angle{};
    sf::RectangleShape m_dirLine{};
};
