#include <iostream>
#include "Model/MMap.h"
#include "View/VMap.h"
#include "Controller/Map.h"

int main() {

    MMap mMap;
    VMap vMap;

    Map *map = new Map(mMap, vMap);
    map->run();


    return 0;
}
