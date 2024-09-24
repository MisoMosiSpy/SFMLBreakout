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

    auto window = sf::RenderWindow{{g_winWidth, g_winHeight}, "SFML Breakout", sf::Style::Default};
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
                        if (!ball.isMoving()) ball.setMoving(true);
                        break;
                    case sf::Keyboard::Key::LBracket:
                        if (!ball.isMoving()) ball.changeAngle(-g_angleStep);
                        break;
                    case sf::Keyboard::Key::RBracket:
                        if (!ball.isMoving()) ball.changeAngle(g_angleStep);
                    default:
                        break;
                }
            }
        }

        // Update game state

        paddle.update(dt);
        ball.update(dt, paddle.getMidTop());

        ball.checkCollision(paddle);
        grid.checkCollision(ball);

        if (grid.isGameOver()) {
            std::cout << "You Won!!!" << std::endl;
            exit(0);
        }

        // Drawing
        window.clear();

        window.draw(border);
        window.draw(paddle);

        ball.draw(window);
        grid.draw(window);

        window.display();
    }
}
