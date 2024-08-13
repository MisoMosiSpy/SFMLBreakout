#include <SFML/Graphics.hpp>
#include "config.h"

class Ball : public sf::Sprite
{
public:
    Ball(BallType t);
    void update(void);
    void setSpeed(sf::Vector2f speed);

private:
    BallType ballType;
    sf::Texture tex;
    sf::Vector2f speed;
};