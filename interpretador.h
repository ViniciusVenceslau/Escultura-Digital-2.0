#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>
#include "figurageometrica.h"

using namespace std;

/**
 * @Ler as insformações para implementar.
 */
class Interpretador{
    int dimx, dimy, dimz;
    float r, g, b, alpha;
public:
    Interpretador(); // Construtor.
    std::vector<FiguraGeometrica *>parse(std::string filename); // Atribuição do interpretador a um vetor.
    int getDimx(); // Chamada das dimensões.
    int getDimy();
    int getDimz();
};

#endif // INTERPRETADOR_H
