#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"
#include "sculptor.h"


/**
 * @cutEllipsoid desativa os voxels que satisfazem a equaçao da elipse.
 */
class CutEllipsoid : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid();
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H