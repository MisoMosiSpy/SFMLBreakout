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

    auto window = sf::RenderWindow{{winWidth, winHeight}, "SFML Breakout", sf::Style::Fullscreen};
    window.setFramerateLimit(144);

    Ball grayBall(BallType::Gray);
    Paddle player(PaddleType::Red);

    grayBall.setPosition(winWidth / 2,
                         player.getGlobalBounds().top - grayBall.getGlobalBounds().height);

    Border border(borderSize, sf::Vector2f{winWidth, winHeight}, true, false, true, true);

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
                        grayBall.setSpeed(sf::Vector2f{-2.0f, -2.0f});
                        break;
                    default:
                        break;
                }
            }
        }

        grayBall.update();
        player.update();
        grayBall.checkCollision(player);
        grayBall.checkCollision(testBrickGray);
        grayBall.checkCollision(testBrickBlue);
        grayBall.checkCollision(testBrickGreen);
        grayBall.checkCollision(testBrickYellow);
        grayBall.checkCollision(testBrickRed);
        grayBall.checkCollision(testBrickPurple);

        window.clear();
        window.draw(border);
        window.draw(grayBall);
        window.draw(player);
        window.draw(testBrickGray);
        window.draw(testBrickBlue);
        window.draw(testBrickGreen);
        window.draw(testBrickYellow);
        window.draw(testBrickRed);
        window.draw(testBrickPurple);

        window.display();
    }
}
