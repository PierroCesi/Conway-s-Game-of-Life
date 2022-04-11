//
// Created by Pierre Forques on 09/04/2022.
//

#ifndef JEUDLAVIE_MMAP_H
#define JEUDLAVIE_MMAP_H

#include <vector>

class MMap {
private:
    void initMatrix();
public:
    static int const matrixSize = 50;

    MMap();
    bool matrix[matrixSize][matrixSize];

};


#endif //JEUDLAVIE_MMAP_H
