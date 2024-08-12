#include <SFML/Graphics.hpp>
#include "ball.h"
#include <iostream>

constexpr uint32_t winWidth = 1980;
constexpr uint32_t winHeight = 1080;

int main()
{
    auto window = sf::RenderWindow{{winWidth, winHeight}, "SFML Breakout", sf::Style::Default};
    window.setFramerateLimit(144);

    Ball grayBall(BallType::Gray);
    Ball blueBall(BallType::Blue);

    grayBall.setPosition(100, 20);
    blueBall.setPosition(20, 100);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Key::Escape:
                    window.close();

                default:
                    break;
                }
            }
        }

        window.clear();
        window.draw(blueBall);
        window.draw(grayBall);
        window.display();
    }
}
