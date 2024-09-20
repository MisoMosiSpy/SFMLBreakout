
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "config.h"
#include "spriteEx.h"

class Brick : public SpriteEx {
public:

    Brick(BrickType t, sf::Vector2f pos, bool isActive = true);

    void setActive(bool state) { m_isActive = state; }

    bool getActive() const { return m_isActive; }

    bool isActive() const { return m_isActive == true; }

private:

    sf::Vector2f m_pos{};
    sf::Texture m_texture{};
    bool m_isActive{};
};
