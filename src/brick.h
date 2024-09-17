
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "config.h"
#include "spriteEx.h"

class Brick : public SpriteEx {
public:

    Brick(BrickType t, sf::Vector2f pos);

private:

    sf::Vector2f m_pos{};
    sf::Texture m_texture{};
};
