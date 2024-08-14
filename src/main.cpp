#include <SFML/Graphics.hpp>
#include <iostream>

#include "ball.h"
#include "border.h"
#include "config.h"

int main() {

    auto window = sf::RenderWindow{{winWidth, winHeight}, "SFML Breakout", sf::Style::Fullscreen};
    window.setFramerateLimit(144);

    Ball grayBall(BallType::Gray);
    Ball blueBall(BallType::Blue);

    grayBall.setPosition(100, 20);
    grayBall.setSpeed(sf::Vector2f{1.0f, 1.0f});
    blueBall.setPosition(100, 20);
    blueBall.setSpeed(sf::Vector2f{0.5f, 0.5f});

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

                    default:
                        break;
                }
            }
        }

        grayBall.update();
        blueBall.update();
        window.clear();
        window.draw(border);
        window.draw(blueBall);
        window.draw(grayBall);
        window.display();
    }
}
