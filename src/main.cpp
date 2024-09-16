// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ball.h"
#include "border.h"
#include "brick.h"
#include "config.h"
#include "paddle.h"

int main() {

    auto window =
        sf::RenderWindow{{g_winWidth, g_winHeight}, "SFML Breakout", sf::Style::Fullscreen};
    window.setFramerateLimit(144);

    Ball ball(BallType::Gray);
    Paddle paddle(PaddleType::Red);

    Border border(g_borderSize, sf::Vector2f{g_winWidth, g_winHeight}, true, false, true, true);

    Brick testBrickGray = Brick(BrickType::Gray, sf::Vector2f(50, 100));
    Brick testBrickBlue = Brick(BrickType::Blue, sf::Vector2f(100, 200));
    Brick testBrickGreen = Brick(BrickType::Green, sf::Vector2f(150, 300));
    Brick testBrickYellow = Brick(BrickType::Yellow, sf::Vector2f(200, 400));
    Brick testBrickRed = Brick(BrickType::Red, sf::Vector2f(250, 500));
    Brick testBrickPurple = Brick(BrickType::Purple, sf::Vector2f(300, 600));

    while (window.isOpen()) {

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
                            ball.setSpeed(sf::Vector2f{-2.0f, -2.0f});
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        ball.update();
        paddle.update();

        if (!ball.isMoving()) {
            sf::Vector2f playerMidTop = paddle.getMidTop();
            ball.setPosition(playerMidTop.x - (ball.getWidth() / 2),
                             playerMidTop.y - ball.getHeight());
        }

        ball.checkCollision(paddle);
        ball.checkCollision(testBrickGray);
        ball.checkCollision(testBrickBlue);
        ball.checkCollision(testBrickGreen);
        ball.checkCollision(testBrickYellow);
        ball.checkCollision(testBrickRed);
        ball.checkCollision(testBrickPurple);

        window.clear();
        window.draw(border);
        window.draw(ball);
        window.draw(paddle);
        window.draw(testBrickGray);
        window.draw(testBrickBlue);
        window.draw(testBrickGreen);
        window.draw(testBrickYellow);
        window.draw(testBrickRed);
        window.draw(testBrickPurple);

        window.display();
    }
}
