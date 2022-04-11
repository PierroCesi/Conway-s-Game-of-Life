//
// Created by Pierre Forques on 09/04/2022.
//

#include "Map.h"

Map::Map(MMap mMap, VMap vMap){
    this->vMap = &vMap;
    this->mMap = &mMap;
}

void Map::run(){
    auto window = this->vMap->window;

    while(window->isOpen()){
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::Escape){
                    //updatable = !updatable;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    this->colorPixel(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }
        this->updateMatrix();

        vMap->clearWindow();
        vMap->render(*mMap);
        window->display();
    }

}

void Map::colorPixel(int x, int y){
    int sizePixel = VMap::WINDOW_SIZE/MMap::matrixSize;
    int xIndex = std::trunc(x/sizePixel);
    int yIndex = std::trunc(y/sizePixel);
    this->mMap->matrix[xIndex][yIndex] = true;
}

void Map::updateMatrix(){
    bool newMatrix[MMap::matrixSize][MMap::matrixSize];

    int aliveNeighbour;
    for(int i=0; i<MMap::matrixSize; i++){
        for(int y=0; y<MMap::matrixSize; y++){
            aliveNeighbour = this->howManyAliveNeighbour(this->mMap->matrix, i, y);

            if(mMap->matrix[i][y] == true){
                if(aliveNeighbour >= 4 || aliveNeighbour <2){
                    newMatrix[i][y] = false;
                } else {
                    newMatrix[i][y] = true;
                }
            } else {
                if(aliveNeighbour == 3){
                    newMatrix[i][y] = true;
                } else {
                    newMatrix[i][y] = false;
                }
            }
        }
    }

    //Copy the new matrix in the MMap object
    for(int i=0; i<MMap::matrixSize; i++){
        for(int y=0; y<MMap::matrixSize; y++){
            this->mMap->matrix[i][y] = newMatrix[i][y];
        }
    }
}

int Map::howManyAliveNeighbour(bool matrix[MMap::matrixSize][MMap::matrixSize], int xIndex, int yIndex){
    int alive = 0;
    //left
    if(matrix[xIndex-1][yIndex] && xIndex!=0){
        alive = alive + 1;
    }

    //right
    if(matrix[xIndex+1][yIndex] && xIndex!=MMap::matrixSize-1){
        alive = alive + 1;
    }

    //above
    if(matrix[xIndex][yIndex-1] && yIndex!=0){
        alive = alive + 1;
    }

    //below
    if(matrix[xIndex][yIndex+1] && yIndex!=MMap::matrixSize){
        alive = alive + 1;
    }

    //diagonal above left
    if(matrix[xIndex-1][yIndex-1] && yIndex!=0 && xIndex!=0){
        alive = alive + 1;
    }

    //diagonal above right
    if(matrix[xIndex+1][yIndex-1] && yIndex!=0 && xIndex!=MMap::matrixSize-1){
        alive = alive + 1;
    }

    //diagonal below left
    if(matrix[xIndex-1][yIndex+1] && yIndex!=MMap::matrixSize && xIndex!=0){
        alive = alive + 1;
    }

    //diagonal below right
    if(matrix[xIndex+1][yIndex+1] && yIndex!=MMap::matrixSize && xIndex!=MMap::matrixSize-1){
        alive = alive + 1;
    }

    return alive;
}
