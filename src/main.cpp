// SPDX-FileCopyrightText: 2024 MisoMosiSpy
// SPDX-License-Identifier: MIT

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ball.h"
#include "border.h"
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
                        grayBall.setSpeed(sf::Vector2f{1.0f, -1.0f});
                        break;
                    default:
                        break;
                }
            }
        }

        grayBall.update();
        player.update();
        grayBall.checkCollision(player);
        window.clear();
        window.draw(border);
        window.draw(grayBall);
        window.draw(player);
        window.display();
    }
}
