//
// Created by Pierre Forques on 09/04/2022.
//

#ifndef JEUDLAVIE_MAP_H
#define JEUDLAVIE_MAP_H


#include "../Model/MMap.h"
#include "../View/VMap.h"
#include <cmath>

class Map {
private:
    MMap *mMap;
    VMap *vMap;
public:
    Map(MMap mMap, VMap vMap);

    void run();
    void colorPixel(int x, int y);
    void updateMatrix();
    int howManyAliveNeighbour(bool matrix[MMap::matrixSize][MMap::matrixSize], int xIndex, int yIndex);

};


#endif //JEUDLAVIE_MAP_H
