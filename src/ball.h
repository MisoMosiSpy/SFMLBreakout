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
    void checkCollision(const SpriteEx &other);

    void setSpeed(sf::Vector2f speed) { this->m_speed = speed; }

private:

    BallType m_ballType;
    sf::Texture m_texture;
    sf::Vector2f m_speed;
};
