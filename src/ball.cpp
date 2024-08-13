#include "ball.h"
#include <iostream>

Ball::Ball(BallType t) : Sprite()
{
    std::string fileName;
    if (t == BallType::Gray)
    {
        fileName = "resources/ballGrey.png";
    }
    else if (t == BallType::Blue)
    {
        fileName = "resources/ballBlue.png";
    }

    if (!tex.loadFromFile(fileName))
    {
        std::cerr << "Unable to load texture " << fileName << std::endl;
        std::cerr << "Quitting..." << std::endl;
        std::exit(-1);
    }
    setTexture(tex);
}

void Ball::update(void)
{
    sf::Vector2f pos = getPosition();
    pos += speed;

    if (pos.x < 0 || pos.x + getGlobalBounds().width > winWidth)
    {
        speed.x *= -1.0f;
    }
    if (pos.y < 0 || pos.y + getGlobalBounds().height > winHeight)
    {
        speed.y *= -1.0f;
    }
    setPosition(pos);
}

void Ball::setSpeed(sf::Vector2f speed)
{
    this->speed = speed;
}
