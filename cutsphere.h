#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"
/**
 * @cutSphere desativa os voxels que tornam a equaçao da esfera verdadeira.
 * @param radius e o raio da esfera.
 */
class CutSphere : public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere();
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H