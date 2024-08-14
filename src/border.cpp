#include "border.h"

Border::Border(float borderSize, sf::Vector2f windowSize, bool top, bool bottom, bool left,
               bool right) {

    float width = windowSize.x;
    float height = windowSize.y;

    if (top) {
        topBorder.setSize(sf::Vector2f{width, borderSize});
        topBorder.setPosition(0, 0);
    }

    if (bottom) {
        bottomBorder.setSize(sf::Vector2f{width, borderSize});
        bottomBorder.setPosition(0, height - borderSize);
    }

    if (left) {
        leftBorder.setSize(sf::Vector2f{borderSize, height});
        leftBorder.setPosition(0, 0);
    }

    if (right) {
        rightBorder.setSize(sf::Vector2f{borderSize, height});
        rightBorder.setPosition(width - borderSize, 0);
    }
}

void Border::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    if (leftBorder.getSize().x > 0) target.draw(leftBorder);

    if (rightBorder.getSize().x > 0) target.draw(rightBorder);

    if (topBorder.getSize().y > 0) target.draw(topBorder);

    if (bottomBorder.getSize().y > 0) target.draw(bottomBorder);
}
