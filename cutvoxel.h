#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"
/**
 * @cutVoxel desativa o voxel na posicao (x,y,z).
 */
class CutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel();
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H