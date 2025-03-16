#include "MainWindow.h"
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
using namespace std;
MainWindow::MainWindow() {
    window.create(sf::VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(60);

}

void MainWindow::run() {
    clock.restart();
    createAreas();
    while (window.isOpen()) {
        window.clear();
        setupBollar();
        addBallsToArea();
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }


        applyGravity();
        borderCollison();
        drawBoll();


        window.display();
    }
}

void MainWindow::threadWork() {
    for (int i = 0; i < 7; i++){
        ballCollison(grid[0][i]);
        if (i == 0){
            adjecentAreaCollision(grid[0][i], grid[0][i+1]);
            adjecentAreaCollision(grid[0][i], grid[1][i]);
        }
        else if (i == 5){
            adjecentAreaCollision(grid[0][i], grid[0][i-1]);
            adjecentAreaCollision(grid[0][i], grid[1][i]);
        }
        else {
            adjecentAreaCollision(grid[0][i], grid[0][i + 1]);
            adjecentAreaCollision(grid[0][i], grid[0][i - 1]);
            adjecentAreaCollision(grid[0][i], grid[1][i]);
        }
    }


}

void MainWindow::thread1Work() {
    for (int i = 0; i < 7; i++){
        ballCollison(grid[1][i]);
        if (i == 0){
            adjecentAreaCollision(grid[1][i], grid[1][i+1]);
            adjecentAreaCollision(grid[1][i], grid[0][i]);
            adjecentAreaCollision(grid[1][i], grid[2][i]);
        }
        else if (i == 5){
            adjecentAreaCollision(grid[1][i], grid[1][i-1]);
            adjecentAreaCollision(grid[1][i], grid[0][i]);
            adjecentAreaCollision(grid[1][i], grid[2][i]);
        }
        else {
            adjecentAreaCollision(grid[1][i], grid[1][i + 1]);
            adjecentAreaCollision(grid[1][i], grid[1][i - 1]);
            adjecentAreaCollision(grid[1][i], grid[0][i]);
            adjecentAreaCollision(grid[1][i], grid[2][i]);
        }
    }

}

void MainWindow::thread2Work() {
    for (int i = 0; i < 7; i++){
        ballCollison(grid[2][i]);
        if (i == 0){
            adjecentAreaCollision(grid[2][i], grid[2][i+1]);
            adjecentAreaCollision(grid[2][i], grid[1][i]);
            adjecentAreaCollision(grid[2][i], grid[3][i]);
        }
        else if (i == 5){
            adjecentAreaCollision(grid[2][i], grid[2][i-1]);
            adjecentAreaCollision(grid[2][i], grid[1][i]);
            adjecentAreaCollision(grid[2][i], grid[3][i]);
        }
        else {
            adjecentAreaCollision(grid[2][i], grid[2][i + 1]);
            adjecentAreaCollision(grid[2][i], grid[2][i - 1]);
            adjecentAreaCollision(grid[2][i], grid[1][i]);
            adjecentAreaCollision(grid[2][i], grid[3][i]);
        }
    }
}

void MainWindow::thread3Work() {
    for (int i = 0; i < 7; i++){
        ballCollison(grid[3][i]);
        if (i == 0){
            adjecentAreaCollision(grid[3][i], grid[3][i+1]);
            adjecentAreaCollision(grid[3][i], grid[2][i]);
            adjecentAreaCollision(grid[3][i], grid[4][i]);
        }
        else if (i == 5){
            adjecentAreaCollision(grid[3][i], grid[3][i-1]);
            adjecentAreaCollision(grid[3][i], grid[2][i]);
            adjecentAreaCollision(grid[3][i], grid[4][i]);
        }
        else {
            adjecentAreaCollision(grid[3][i], grid[3][i + 1]);
            adjecentAreaCollision(grid[3][i], grid[3][i - 1]);
            adjecentAreaCollision(grid[3][i], grid[2][i]);
            adjecentAreaCollision(grid[3][i], grid[4][i]);
        }

    }
}

void MainWindow::thread4Work() {
    for (int i = 0; i < 7; i++){
        ballCollison(grid[4][i]);
        if (i == 0){
            adjecentAreaCollision(grid[4][i], grid[4][i+1]);
            adjecentAreaCollision(grid[4][i], grid[3][i]);
        }
        else if (i == 5){
            adjecentAreaCollision(grid[4][i], grid[4][i-1]);
            adjecentAreaCollision(grid[4][i], grid[3][i]);
        }
        else {
            adjecentAreaCollision(grid[4][i], grid[4][i + 1]);
            adjecentAreaCollision(grid[4][i], grid[4][i - 1]);
            adjecentAreaCollision(grid[4][i], grid[3][i]);
        }
    }
}

void MainWindow::createAreas() {
    grid.resize(5);
    for (int i = 0; i < 5; i++) {
        grid[i].resize(7);
    }


}

void MainWindow::setupBollar() {

    if (clock2.getElapsedTime().asSeconds() < 50){
        if (clock.getElapsedTime().asSeconds() > 0.001) {
                Boll* boll = new Boll(
                        5,
                        streamPos,
                        100,
                        sf::Color::Red,
                        sf::Vector2f(cos(x * 0.8) * (x * 0.4) , 5)
                );
                bolls.push_back(boll);
                int bollx = boll->getCircle().getPosition().x;
                if (bollx >= 0 && bollx <= 274){ // 0-274
                    addBallToArea(boll);
                }
                else if (bollx >= 275 && bollx <= 548){ // 275-548
                    addBallToArea(boll);
                }else if (bollx >= 549 && bollx <= 822){ // 549-822
                    addBallToArea(boll);
                }
                else if (bollx >= 823 && bollx <= 1096){ // 823-1096
                    addBallToArea(boll);
                }else if (bollx >= 1097 && bollx <= 1370){ // 1097-1370
                    addBallToArea(boll);
                }
                streamPos += 300;
                if (streamPos > 1200){
                    streamPos = 100;
                }
                clock.restart();
                ballCounter++;
                cout << ballCounter << endl;
                if (up){
                    x += 0.1;
                }else {
                    x -= 0.1;
                }

                if (x > 10){
                    up = false;
                }
                if (x < -10){
                    up = true;
                }
            }
    }
}

void MainWindow::drawBollArea(vector<Boll *> &bollArea) {
    for (auto boll : bollArea) {
        window.draw(boll->getCircle());
    }
}

void MainWindow::drawBoll() {
    for (auto boll : bolls) {
        window.draw(boll->getCircle());
    }
}

void MainWindow::applyGravity() {
    for (auto &boll : bolls) {
        boll->applyVelocity(gravity.x, gravity.y);
        boll->update();
    }
}

void MainWindow::addBallToArea(Boll *boll) {
    float bollx = boll->getCircle().getPosition().x;
    float bolly = boll->getCircle().getPosition().y;

    int nyxArea = static_cast<int>(bollx/254.f);
    int nyyArea = static_cast<int>(bolly/122.f);

    if (nyxArea < 0){
        nyxArea = 0;
    }
    if (nyyArea < 0){
        nyyArea = 0;
    }
    if (nyxArea > 4){
        nyxArea = 4;
    }
    if (nyyArea > 5){
        nyyArea = 5;
    }

    grid[nyxArea][nyyArea].push_back(boll);

}
void MainWindow::applyGravityArea(vector<Boll *> &bollArea) {
    for (auto &boll : bollArea) {
        boll->applyVelocity(gravity.x, gravity.y);
        boll->update();
    }
}


void MainWindow::addBallToYArea(Boll *boll, int xArea) {


}

void MainWindow::addBallsToArea() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            grid[i][j].clear();
        }
    }

    for (auto &boll : bolls) {
        float bollx = boll->getCircle().getPosition().x;
        float bolly = boll->getCircle().getPosition().y;

        int nyxArea = static_cast<int>(bollx/254.f);
        int nyyArea = static_cast<int>(bolly/122.f);

        if (nyxArea < 0){
            nyxArea = 0;
        }
        if (nyyArea < 0){
            nyyArea = 0;
        }
        if (nyxArea > 4){
            nyxArea = 4;
        }
        if (nyyArea > 5){
            nyyArea = 5;
        }

        grid[nyxArea][nyyArea].push_back(boll);
    }
}


void MainWindow::adjecentAreaCollision(vector<Boll *> &bollArea1, vector<Boll *> &bollArea2) {
    for (auto &boll : bollArea1) {
        for (auto &other : bollArea2) {
            float bollx = boll->getCircle().getPosition().x;
            float bolly = boll->getCircle().getPosition().y;
            float otherx = other->getCircle().getPosition().x;
            float othery = other->getCircle().getPosition().y;

            float dx = bollx - otherx;
            float dy = bolly - othery;
            float distance = (dx * dx) + (dy * dy);
            float rad1 = boll->getCircle().getRadius();
            float rad2 = other->getCircle().getRadius();
            float mindist = rad1 + rad2;

            if (distance < mindist * mindist) {
                resolveCollision(boll, other, sqrt(distance));
            }
        }
    }
}



void MainWindow::borderCollisonArea(vector<Boll *> &bollArea) {
    for (auto &boll : bollArea) {
        float radius = boll->getCircle().getRadius();
        if (boll->getCircle().getPosition().x - 50 < 0) {
            boll->setPos(0 + 50, boll->getCircle().getPosition().y);
            boll->setVelocity(-boll->getVelocity().x * bouncyness, boll->getVelocity().y * bouncyness);
        } else if (boll->getCircle().getPosition().x + 50 > width) {
            boll->setPos(width - 50, boll->getCircle().getPosition().y);
            boll->setVelocity(-boll->getVelocity().x * bouncyness, boll->getVelocity().y * bouncyness);
        } else if (boll->getCircle().getPosition().y - 50 < 0) {
            boll->setPos(boll->getCircle().getPosition().x, 0 + 50);
            boll->setVelocity(boll->getVelocity().x * bouncyness, -boll->getVelocity().y * bouncyness);
        } else if (boll->getCircle().getPosition().y + 50 > height) {
            boll->setPos(boll->getCircle().getPosition().x, height - 50);
            boll->setVelocity(boll->getVelocity().x * bouncyness, -boll->getVelocity().y * bouncyness);
        }
    }
}


void MainWindow::borderCollison() {
    for (auto &boll : bolls) {
        float radius = boll->getCircle().getRadius();
        if (boll->getCircle().getPosition().x - 50 < 0) {
            boll->setPos(0 + 50, boll->getCircle().getPosition().y);
            boll->setVelocity(-boll->getVelocity().x * bouncyness, boll->getVelocity().y * bouncyness);
        }else if (boll->getCircle().getPosition().x + 50 > width) {
            boll->setPos(width - 50, boll->getCircle().getPosition().y);
            boll->setVelocity(-boll->getVelocity().x * bouncyness, boll->getVelocity().y * bouncyness);
        }
        else if (boll->getCircle().getPosition().y - 50 < 0) {
            boll->setPos(boll->getCircle().getPosition().x, 0 + 50);
            boll->setVelocity(boll->getVelocity().x * bouncyness, -boll->getVelocity().y * bouncyness);


        }else if (boll->getCircle().getPosition().y + 50 > height) {
            boll->setPos(boll->getCircle().getPosition().x, height - 50);
            boll->setVelocity(boll->getVelocity().x * bouncyness, -boll->getVelocity().y * bouncyness);


        }
    }
}

void MainWindow::ballCollison(vector<Boll*> &bollArea) {

    for (auto &boll : bollArea) {
        for (auto &other : bollArea) {
            if (boll != other) {
                float bollx = boll->getCircle().getPosition().x;
                float bolly = boll->getCircle().getPosition().y;
                float otherx = other->getCircle().getPosition().x;
                float othery = other->getCircle().getPosition().y;

                float dx = bollx - otherx;
                float dy = bolly - othery;


                float distance = (dx * dx) + (dy * dy);
                float rad1 = boll->getCircle().getRadius();
                float rad2 = other->getCircle().getRadius();
                float mindist = rad1 + rad2;

                if (distance < mindist * mindist) {
                    resolveCollision(boll, other, sqrt(distance));
                }
            }
        }
    }
}


void MainWindow::resolveCollision(Boll *boll1, Boll *boll2, float distance) {

    sf::Vector2f pos1 = boll1->getCircle().getPosition();
    sf::Vector2f pos2 = boll2->getCircle().getPosition();

    float bollradius = boll1->getCircle().getRadius();
    float bollotheradius = boll2->getCircle().getRadius();

    sf::Vector2f delta = pos1 - pos2;
    if (distance < 0.0001) {
        distance = 0.0001;
        delta = sf::Vector2f(0.0001f, 0.0001f);
    }

    float overlapp = (bollradius + bollotheradius) - distance;
    float angle = atan2(delta.y, delta.x);
    float extra = 0.3f;
    float push = (overlapp / 3) + extra;




    float ballFriction = 0.90;

    boll1->setPos(pos1.x + (push * cos(angle)), pos1.y + (push * sin(angle)));
    boll2->setPos(pos2.x - (push * cos(angle)), pos2.y - (push * sin(angle)));
    boll1->setVelocity(boll1->getVelocity().x * ballFriction, boll1->getVelocity().y * ballFriction);
    boll2->setVelocity(boll2->getVelocity().x * ballFriction, boll2->getVelocity().y * ballFriction);

    sf::Vector2f normal = delta / distance;

    auto reflect = [&](const sf::Vector2f& v, const sf::Vector2f& n) {
        float dot = v.x*n.x + v.y*n.y;
        return sf::Vector2f(v.x - 2.f*dot*n.x, v.y - 2.f*dot*n.y);
    };

    sf::Vector2f oldV1 = boll1->getVelocity();
    sf::Vector2f oldV2 = boll2->getVelocity();

    sf::Vector2f newV1 = reflect(oldV1, normal);
    sf::Vector2f newV2 = reflect(oldV2, -normal);

    boll1->setVelocity(newV1.x, newV1.y);
    boll2->setVelocity(newV2.x, newV2.y);


}







