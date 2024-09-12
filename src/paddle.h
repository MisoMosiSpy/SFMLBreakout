// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"

class Paddle : public sf::Sprite {
public:

    Paddle(PaddleType t);
    void update();

    void setSpeed(float s) { m_speed = s; }

private:

    PaddleType m_paddleType;
    sf::Texture m_texture;
    float m_speed = 3;
};