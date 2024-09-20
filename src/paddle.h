// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "config.h"
#include "spriteEx.h"

class Paddle : public SpriteEx {
public:

    Paddle(PaddleType t);
    void update(float dt);

    void setSpeed(float s) { m_speed = s; }

private:

    PaddleType m_paddleType{};
    sf::Texture m_texture{};
    float m_speed{g_playerSpeed};
};