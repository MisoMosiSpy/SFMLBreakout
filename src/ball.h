// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "config.h"
#include "spriteEx.h"

class Ball : public SpriteEx {

public:

    Ball(BallType t);

    void update();

    void checkWindowCollision();

    bool checkCollision(const SpriteEx &other);

    void setSpeed(sf::Vector2f speed) { this->m_speed = speed; }

    bool isMoving() { return (m_speed.x != 0.0f || m_speed.y != 0.0f); }

    void reset() { m_speed = {0, 0}; }

private:

    BallType m_ballType{};
    sf::Texture m_texture{};
    sf::Vector2f m_speed{};
    int m_lives{g_playerLives};
};
