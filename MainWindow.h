//
// Created by Henrik Ravnborg on 2025-03-15.
//

#ifndef UNTITLED12_MAINWINDOW_H
#define UNTITLED12_MAINWINDOW_H

#include <SFML/Window/Event.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Thread.hpp>
#include "SFML/Graphics/CircleShape.hpp"
#include "boll.h"
using namespace std;

class MainWindow {
private:
    sf::RenderWindow window;
    int width = 1470;
    int height = 832;
    vector<Boll*> bolls;
    sf::Vector2f gravity = sf::Vector2f(0, 0.16);
    float bouncyness = 0.9;
    sf::Clock clock;
    sf::Clock clock2;
    float x = -10;
    bool up = true;
    int streamPos = 100;
    vector<vector<vector<Boll*>>> grid;
    int ballCounter = 0;





public:
    MainWindow();
    void run();
    void setupBollar();
    void drawBoll();
    void applyGravity();
    void borderCollison();
    void ballCollison(vector<Boll*> &bollArea);
    void resolveCollision(Boll *boll1, Boll *boll2, float distance);
    void addBallsToArea();
    void adjecentAreaCollision(vector<Boll*> &bollArea1, vector<Boll*> &bollArea2);
    void threadWork();
    void thread1Work();
    void thread2Work();
    void thread3Work();
    void thread4Work();
    void thread5Work();
    void drawBollArea(vector<Boll*> &bollArea);
    void createAreas();
    void addBallToArea(Boll* boll);
    void addBallToYArea(Boll* boll, int xArea);
    void extraBallCollision(Boll *boll1, Boll *boll2, vector<Boll*> &bollArea);
    void applyGravityArea(vector<Boll*> &bollArea);
    void borderCollisonArea(vector<Boll*> &bollArea);





};

#endif //UNTITLED12_MAINWINDOW_H
