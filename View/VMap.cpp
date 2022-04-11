//
// Created by Pierre Forques on 09/04/2022.
//

#include "VMap.h"

VMap::VMap() {
    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "jedlavi");
    this->window->setFramerateLimit(5);
}

void VMap::render(MMap map) {
    int matrixSize = MMap::matrixSize;
    int sizePixel = WINDOW_SIZE/matrixSize;

    //Init rectangle
    sf::RectangleShape rectangle(sf::Vector2f(0, 0));
    rectangle.setSize(sf::Vector2f(sizePixel, sizePixel));
    rectangle.setOutlineThickness(THICKNESS);
    rectangle.setOutlineColor(sf::Color(0, 0, 0));

    auto matrix = map.matrix;

    for(int i=0; i<matrixSize; i++){
        for(int y=0; y<matrixSize; y++){
            if(matrix[i][y] == true){
                rectangle.setFillColor(sf::Color(0, 0, 0));
            }
            rectangle.setPosition(sf::Vector2f(i*sizePixel, y*sizePixel));
            this->window->draw(rectangle);
            rectangle.setFillColor(sf::Color(255, 255, 255));
        }
    }

}

void VMap::clearWindow(){
    this->window->clear(sf::Color(123, 45, 90));
}

