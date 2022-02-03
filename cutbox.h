#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @cutBox remove bloco quadrado/retangular dentro da matriz 3d
 * @param x0 e x1, valor inicial e final de x na fórmula, respectivamente
 * @param y0 e y1, valor inicial e final de y na fórmula, respectivamente
 * @param z0 e z1, valor inicial e final de z na fórmula, respectivamente
 */
class CutBox : public FiguraGeometrica{
    int x0, x1, y0, y1, z0, z1;
public:

    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~CutBox();

    /**
      @draw - Função que desenha os voxels
      @param s - Escultor que armazena os voxels
      */
    void draw(Sculptor &s);
};

#endif // CUTBOX_H