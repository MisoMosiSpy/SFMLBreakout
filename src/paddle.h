#include <SFML/Graphics.hpp>

#include "config.h"

class Paddle : public sf::Sprite {
public:

    Paddle(PaddleType t);
    void update();

    void setSpeed(float s) { speed = s; }

private:

    PaddleType paddleType;
    sf::Texture tex;
    float speed = 1;
};