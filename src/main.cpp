// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ball.h"
#include "border.h"
#include "brick.h"
#include "config.h"
#include "grid.h"
#include "paddle.h"

int main() {

    auto window =
        sf::RenderWindow{{g_winWidth, g_winHeight}, "SFML Breakout", sf::Style::Fullscreen};
    window.setFramerateLimit(144);

    // Create game objects
    Grid grid{};
    Ball ball(BallType::Gray);
    Paddle paddle(PaddleType::Red);
    Border border(g_borderSize, sf::Vector2f{g_winWidth, g_winHeight}, true, false, true, true);

    sf::Clock clock;

    while (window.isOpen()) {

        float dt = clock.restart().asSeconds();

        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Key::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::Key::Space:
                        if (!ball.isMoving()) {
                            ball.setSpeed(sf::Vector2f{-g_ballSpeed, -g_ballSpeed});
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        // Update game state

        ball.update(dt);
        paddle.update(dt);

        if (!ball.isMoving()) {
            sf::Vector2f playerMidTop = paddle.getMidTop();
            ball.setPosition(playerMidTop.x - (ball.getWidth() / 2),
                             playerMidTop.y - ball.getHeight());
        }

        // Check collisions
        ball.checkCollision(paddle);
        grid.checkCollision(ball);
        if (grid.isGameOver()) {
            std::cout << "You Won!!!" << std::endl;
            exit(0);
        }

        // Drawing
        window.clear();

        window.draw(border);
        window.draw(ball);
        window.draw(paddle);
        grid.draw(window);

        window.display();
    }
}
