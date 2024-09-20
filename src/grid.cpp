// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "grid.h"

#include <iostream>

Grid::Grid() {

    Brick tempBrick{BrickType::Gray, sf::Vector2f(0, 0)};

    float width = tempBrick.getWidth() + g_padding;
    float height = tempBrick.getHeight() + g_padding;

    int cols = static_cast<int>(((g_winWidth - g_borderSize * 2) / width));
    int rows = static_cast<int>(((g_winHeight / 2 - g_borderSize * 2) / height));

    sf::Vector2f start{};
    start.x = g_padding / 2 + (g_winWidth - cols * width) / 2;
    start.y = g_padding / 2 + (g_winHeight / 2 - rows * height) / 2;

    int t = 0;

    for (int x = 0; x < cols; x++) {
        sf::Vector2f pos{0, 0};
        pos.x = start.x + width * x;
        for (int y = 0; y < rows; y++) {
            t++;
            pos.y = start.y + height * y;
            if (x == y) {
                m_bricks.push_back(new Brick{BrickType::Gray, pos});
            } else {
                m_bricks.push_back(new Brick{intToBrickType(1 + (t % 3)), pos});
            }
        }
    }
};

Grid::~Grid() {
    for (auto brick : m_bricks) {
        delete brick;
    }
    m_bricks.clear();
};

void Grid::draw(sf::RenderWindow& window) {
    for (auto brick : m_bricks) {
        if (brick->isActive()) window.draw(*brick);
    }
}

void Grid::checkCollision(Ball& ball) {
    for (auto brick : m_bricks) {
        if (brick->isActive()) {
            if (ball.checkCollision(*brick)) {
                brick->decrementLevel();
            }
        }
    }
}

bool Grid::isGameOver() const {

    auto count =
        std::count_if(m_bricks.begin(), m_bricks.end(), [](Brick* b) { return (b->isActive()); });

    auto blocking =
        std::count_if(m_bricks.begin(), m_bricks.end(), [](Brick* b) { return (b->isBlocking()); });

    return (count == blocking);
}