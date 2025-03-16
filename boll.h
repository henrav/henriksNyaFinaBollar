//
// Created by Henrik Ravnborg on 2025-03-15.
//

#ifndef UNTITLED12_BOLL_H
#define UNTITLED12_BOLL_H

#include "SFML/Graphics/CircleShape.hpp"
class Boll {
private:
    sf::CircleShape circle;
    sf::Vector2f velocity;
    int bollXArea = 1;
    int bollYArea = 1;

public:
    Boll(float radius, float x, float y, sf::Color color, sf::Vector2f velocity = sf::Vector2f(0, 0));
    sf::CircleShape &getCircle();
    void update();
    void applyVelocity(float x, float y);
    sf::Vector2f getVelocity();
    void setVelocity(float x, float y);
    void setPos(float x, float y);
    void setArea(int area);
    int getBollXArea();
    int getBollYArea();
    void setBollXArea(int x);
    void setBollYArea(int y);


};




#endif //UNTITLED12_BOLL_H
