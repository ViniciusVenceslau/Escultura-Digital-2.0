#include <iostream>
#include <vector>
#include "sculptor.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "interpretador.h"

using namespace std;

int main(){

    Sculptor *lightsaber; // Objetos.

    Interpretador parser;

    vector<FiguraGeometrica*> figs; // Ponteiro para cada posição da variável "figs".

/*
 * @Interpretação do figs com a entrada do arquivo.
 */
    figs = parser.parse((char*)"leitura.txt");

/*
 * @Definição do tamanho da matriz tridimensional através dos "gets" das dimensões.
 * @Para alocação dinâmica de memória. 
 */
    lightsaber = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

/*
 * @Laços de repitação para percorrer a variável "figs".
 */
    for(size_t i=0; i<figs.size(); i++){
        figs[i] -> draw(*lightsaber); // Operador "arrow": Acessar os membros das estruturas através de ponteiros. 
    }

/*
 * @Pega as informações que foram desenhadas/registradas no arquivo .txt e as tornam legíveis no visualizador/aplicativo 3D (.off). 
 */
    lightsaber -> writeOFF((char*)"lightsaberPARTE2.off");

    for(size_t i=0; i<figs.size(); i++){
        delete figs[i];
    }
    delete lightsaber;
    return 0;
}
