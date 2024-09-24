
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once
#include <array>

// Window settings
constexpr int g_winWidth = 1600 / 2;
constexpr int g_winHeight = 900 / 2;
constexpr int g_borderSize = 10;
constexpr int g_padding = 40;

// Game play settings
constexpr int g_playerSpeed = 300;
constexpr int g_playerLives = 4;
constexpr int g_ballSpeed = 250;
constexpr int g_defaultAngle = -30;
constexpr int g_angleStep = 2;

enum class BallType { Gray, Blue };

enum class BrickType { Gray = -1, None, Green, Yellow, Red, Purple, Blue, maxTypes };

enum class PaddleType { Blue, Red };

inline BrickType intToBrickType(int type) {
    switch (type) {
        case -1:
            return BrickType::Gray;
        case 0:
            return BrickType::None;
        case 1:
            return BrickType::Green;
        case 2:
            return BrickType::Yellow;
        case 3:
            return BrickType::Red;
        case 4:
            return BrickType::Purple;
        case 5:
            return BrickType::Blue;
    }

    return BrickType::None;
}