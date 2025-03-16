//
// Created by Henrik Ravnborg on 2025-03-15.
//

#include "boll.h"

sf::CircleShape &Boll::getCircle() {
    return circle;
}

Boll::Boll(float radius, float x, float y, sf::Color color, sf::Vector2f velocity) {
    circle.setRadius(radius);
    circle.setPosition(x, y);
    circle.setFillColor(color);
    this->velocity = velocity;
}

void Boll::update() {
    circle.move(velocity);
}

void Boll::applyVelocity(float x, float y) {
    this->velocity += sf::Vector2f(x, y);
}

sf::Vector2f Boll::getVelocity() {
    return this->velocity;
}

void Boll::setVelocity(float x, float y) {
    this->velocity = sf::Vector2f(x, y);
}

void Boll::setPos(float x, float y) {
    circle.setPosition(x, y);
}



int Boll::getBollXArea() {
    return this->bollXArea;
}

int Boll::getBollYArea() {
    return this->bollYArea;
}

void Boll::setBollXArea(int x) {
    this->bollXArea = x;
}

void Boll::setBollYArea(int y) {
    this->bollYArea = y;
}

