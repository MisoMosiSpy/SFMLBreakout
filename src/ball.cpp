#include "ball.h"

#include <iostream>

Ball::Ball(BallType t) : Sprite() {
    std::string fileName;
    if (t == BallType::Gray) {
        fileName = "resources/ballGrey.png";
    } else if (t == BallType::Blue) {
        fileName = "resources/ballBlue.png";
    }

    if (!tex.loadFromFile(fileName)) {
        std::cerr << "Unable to load texture " << fileName << std::endl;
        std::cerr << "Quitting..." << std::endl;
        std::exit(-1);
    }
    setTexture(tex);
}

void Ball::update(void) {
    sf::Vector2f pos = getPosition();
    pos += speed;

    if (pos.x <= borderSize || (pos.x + getGlobalBounds().width + borderSize) > winWidth) {
        speed.x *= -1.0f;
    }

    if (pos.y <= borderSize) {
        speed.y *= -1.0f;
    }

    if ((pos.y + getGlobalBounds().height) > winHeight) {
        std::exit(-1);
    }
    setPosition(pos);
}

void Ball::checkCollision(sf::Sprite& other) {

    sf::FloatRect rectSelf{getGlobalBounds().getPosition(), getGlobalBounds().getSize()};
    sf::FloatRect rectOther{other.getGlobalBounds().getPosition(),
                            other.getGlobalBounds().getSize()};

    if (rectSelf.intersects(rectOther)) {
        speed.y *= -1;
    }
}
