
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once
#include <SFML/Graphics.hpp>

#include "config.h"

class Brick : public sf::Sprite {
public:

    Brick(BrickType t, sf::Vector2f pos);

private:

    sf::Vector2f pos;
    sf::Texture tex;
};
