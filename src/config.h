
// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#pragma once

// Window settings
constexpr int g_winWidth = 1600;
constexpr int g_winHeight = 900;
constexpr int g_borderSize = 10;

// Game play settings
constexpr int g_playerSpeed = 3;
constexpr int g_playerLives = 4;

enum class BallType { Gray, Blue };

enum class BrickType { Gray, Blue, Green, Yellow, Red, Purple };

enum class PaddleType { Blue, Red };