#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"
/**
 * @putBox ativa todos os voxels no intervalo (x,y,z) dados.
 * @param x0 e x1, valores de x que serao inseridos na equaçao do cubo.
 * @param y0 e y1, valores de y que serao inseridos na equaçao do cubo.
 * @param z0 e z1, valores de z que serao inseridos na equaçao do cubo.
 */
class PutBox : public FiguraGeometrica{
    int x0, x1, y0, y1, z0, z1;
public:
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float alpha);
    ~PutBox();
    void draw(Sculptor &s);
};

#endif // PUTBOX_H