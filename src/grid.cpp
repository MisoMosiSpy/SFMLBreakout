// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include "grid.h"

#include <iostream>

Grid::Grid() {

    Brick tempBrick{BrickType::Gray, sf::Vector2f(0, 0)};

    float padding = 80;
    float width = tempBrick.getWidth() + padding;
    float height = tempBrick.getHeight() + padding;

    int cols = static_cast<int>(((g_winWidth - g_borderSize * 2) / width));
    int rows = static_cast<int>(((g_winHeight / 2 - g_borderSize * 2) / height));

    sf::Vector2f start{};

    start.x = padding / 2 + (g_winWidth - cols * width) / 2;
    start.y = padding / 2 + (g_winHeight / 2 - rows * height) / 2;

    std::cout << "Grid: " << rows << "x" << cols << std::endl;
    std::cout << "Offset: " << start.x << "," << start.y << std::endl;
    int t = 0;

    for (int x = 0; x < cols; x++) {
        sf::Vector2f pos{0, 0};
        pos.x = start.x + width * x;
        for (int y = 0; y < rows; y++) {
            pos.y = start.y + height * y;
            m_bricks.push_back(new Brick{intToBrickType(2 - (y % 3)), pos});
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
        window.draw(*brick);
    }
}

void Grid::checkCollision(Ball& ball) {
    for (auto brick : m_bricks) {
        ball.checkCollision(*brick);
    }
}