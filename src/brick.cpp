
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include "brick.h"

#include <iostream>

Brick::Brick(BrickType t, sf::Vector2f pos, bool isActive) : SpriteEx() {
    std::string fileName;
    switch (t) {
        case BrickType::Gray:
            fileName = "resources/element_grey_rectangle.png";
            break;

        case BrickType::Blue:
            fileName = "resources/element_blue_rectangle.png";
            break;

        case BrickType::Green:
            fileName = "resources/element_green_rectangle.png";
            break;

        case BrickType::Yellow:
            fileName = "resources/element_yellow_rectangle.png";
            break;

        case BrickType::Red:
            fileName = "resources/element_red_rectangle.png";
            break;

        case BrickType::Purple:
            fileName = "resources/element_purple_rectangle.png";
            break;
        default:
            break;
    }

    if (!m_texture.loadFromFile(fileName)) {
        std::cerr << "Unable to load texture " << fileName << std::endl;
        std::cerr << "Quitting..." << std::endl;
        std::exit(-1);
    }
    setTexture(m_texture);
    setPosition(pos);
    m_isActive = isActive;
}