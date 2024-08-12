#include <SFML/Graphics.hpp>
#include "config.h"

class Ball : public sf::Sprite
{
public:
    Ball(BallType t);

private:
    BallType ballType;
    sf::Texture tex;
};