//
// Created by Pierre Forques on 09/04/2022.
//

#ifndef JEUDLAVIE_VMAP_H
#define JEUDLAVIE_VMAP_H
#include <SFML/Graphics.hpp>
#include <iostream>


#include "../Model/MMap.h"

class VMap {
private:
public:
    static const int WINDOW_SIZE = 1600;
    static const int THICKNESS = 1;

    sf::RenderWindow *window;

    VMap();

    void render(MMap map);
    void clearWindow();
};


#endif //JEUDLAVIE_VMAP_H
