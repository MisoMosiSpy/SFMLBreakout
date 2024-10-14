
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "config.h"
#include "spriteEx.h"

class Brick : public SpriteEx {
public:

    Brick(BrickType t, sf::Vector2f pos);

    void getTexture(BrickType t);

    bool isActive() const { return (m_level >= 1 || m_level == -1); }

    bool isBlocking() const { return (m_level < 0); }

    // If the level is >= 1 it means the brick is still active
    // If the level is 0 means the brick is not active and invisible
    // If the level is < 0 it means it i blocking brink
    void decrementLevel() {
        if (m_level >= 1) {
            m_level--;
            if (m_level > 0) {
                getTexture(intToBrickType(m_level));
            }
        }
    }

private:

    sf::Vector2f m_pos{};
    sf::Texture m_texture{};
    int m_level{0};
};
