// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"

class Ball : public sf::Sprite {

public:

    Ball(BallType t);
    void update();
    void checkWindowCollision();
    void checkCollision(sf::Sprite &other);

    void setSpeed(sf::Vector2f speed) { this->speed = speed; }

private:

    BallType ballType;
    sf::Texture tex;
    sf::Vector2f speed;
};
