
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once
#include <array>

// Window settings
constexpr int g_winWidth = 1600;
constexpr int g_winHeight = 900;
constexpr int g_borderSize = 10;

// Game play settings
constexpr int g_playerSpeed = 3;
constexpr int g_playerLives = 4;

enum class BallType { Gray, Blue };

enum class BrickType { Green, Yellow, Red, Purple, Blue, Gray, maxTypes };

enum class PaddleType { Blue, Red };

inline BrickType intToBrickType(int type) {
    std::array lookup = {BrickType::Green,  BrickType::Yellow, BrickType::Red,
                         BrickType::Purple, BrickType::Blue,   BrickType::Gray};

    return lookup[type];
}