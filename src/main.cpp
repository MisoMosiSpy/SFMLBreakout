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

    std::vector<Brick*> bricks;

    // We construct the objects directly in the vector, so that they are destroyed
    // When removed from the vector.
    bricks.push_back(new Brick{BrickType::Gray, sf::Vector2f(50, 100)});
    bricks.push_back(new Brick{BrickType::Blue, sf::Vector2f(100, 200)});
    bricks.push_back(new Brick{BrickType::Green, sf::Vector2f(150, 300)});
    bricks.push_back(new Brick{BrickType::Yellow, sf::Vector2f(200, 400)});
    bricks.push_back(new Brick{BrickType::Red, sf::Vector2f(250, 500)});
    bricks.push_back(new Brick{BrickType::Purple, sf::Vector2f(300, 600)});

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

        for (auto brick : bricks) {
            if (brick->getActive()) {
                brick->setActive(!ball.checkCollision(*brick));
            }
        }

        window.clear();
        window.draw(border);
        window.draw(ball);
        window.draw(paddle);

        for (auto brick : bricks) {
            if (brick->getActive()) window.draw(*brick);
        }

        window.display();
    }

    for (auto brick : bricks) {
        delete brick;
    }
}
