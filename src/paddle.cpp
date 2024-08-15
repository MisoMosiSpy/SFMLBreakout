#include "paddle.h"

#include <iostream>

Paddle::Paddle(PaddleType t) : Sprite() {
    paddleType = t;

    std::string fileName;

    if (paddleType == PaddleType::Blue) {
        fileName = "resources/paddleBlu.png";
    } else {
        fileName = "resources/paddleRed.png";
    }

    if (!tex.loadFromFile(fileName)) {
        std::cerr << "Unable to load texture " << fileName << std::endl;
        std::cerr << "Quitting..." << std::endl;
        std::exit(-1);
    }
    setTexture(tex);
    setPosition(winWidth / 2 - tex.getSize().x / 2, winHeight - tex.getSize().y * 2);
}

void Paddle::update() {

    sf::Vector2f currentPos = getPosition();
    sf::Vector2f movement{0, 0};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x = -speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x = speed;
    }

    sf::Vector2f newPos = currentPos + movement;
    if (newPos.x < borderSize) newPos.x = borderSize;
    if (newPos.x > winWidth - borderSize - tex.getSize().x)
        newPos.x = winWidth - borderSize - tex.getSize().x;

    setPosition(newPos);
}