
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "config.h"
#include "spriteEx.h"

class Brick : public SpriteEx {
public:

    Brick(BrickType t, sf::Vector2f pos, bool isActive = true);

    void Brick::getTexture(BrickType t);

    void setActive(bool state) { m_isActive = state; }

    bool getActive() const { return m_isActive; }

    bool isActive() const { return m_isActive == true; }

    void decrementLevel() {
        m_level--;
        if (m_level == -1) {
            setActive(false);
        }
        if (isActive()) {
            getTexture(intToBrickType(m_level));
        }
    }

private:

    sf::Vector2f m_pos{};
    sf::Texture m_texture{};
    bool m_isActive{};
    int m_level{-1};
};
