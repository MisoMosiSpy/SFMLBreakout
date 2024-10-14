// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "ball.h"
#include "brick.h"

class Grid {
public:

    Grid();
    ~Grid();

    void draw(sf::RenderWindow& window);

    void checkCollision(Ball& ball);

    bool isGameOver() const;

private:

    std::vector<Brick*> m_bricks{};
};
