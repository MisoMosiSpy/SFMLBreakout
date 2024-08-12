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