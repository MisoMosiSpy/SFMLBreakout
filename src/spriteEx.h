// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

#include <SFML/Graphics.hpp>

class SpriteEx : public sf::Sprite {
public:

    float getTop() const { return getGlobalBounds().top; }

    float getLeft() const { return getGlobalBounds().left; }

    float getWidth() const { return getGlobalBounds().width; }

    float getHeight() const { return getGlobalBounds().height; }

    float getBottom() const { return (getTop() + getHeight()); }

    float getRight() const { return (getLeft() + getWidth()); }

    sf::Vector2f getMidTop() const { return sf::Vector2f{getLeft() + (getWidth() / 2), getTop()}; }
};