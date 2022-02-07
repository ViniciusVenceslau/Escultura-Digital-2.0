#include "interpretador.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <string.h>
#include <vector>
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"

using namespace std;

/* 
 * @Leitura/Interpretação do arquivo .txt de entrada.
 */
Interpretador::Interpretador(){

}

/*
 * @Declaração do interpretador.
 */
std::vector<FiguraGeometrica *> Interpretador::parse(std::string filename){

    std::vector<FiguraGeometrica*> figs; // Variável "figs" responsável por armazenar cada chamada da figura geométrica.
    std::ifstream arq;
    std::stringstream ss; // Inicialização das funções para leitura de dados.
    std::string s, token;

    arq.open(filename.c_str()); // Leitura do arquivo.
    if(!arq.is_open()){
        cout << "Ocorreu um erro!" << endl;
        exit(0);
    }
/*
 * @Laço de leitura enquanto existir linhas legíveis.
 */
    while(arq.good()){
        getline(arq, s); // Verificação de cada linha.
        if(arq.good()){
            ss.clear(); // Limpando as informações de cada loop.
            ss.str(s); // Cópia da string "s" para o fluxo "ss".
            ss >> token; // Ler o primeiro conteúdo legível de cada linha do conteúdo de entrada.
            if(ss.good()){
                if(token.compare("dim") == 0){ // Compara se o conteúdo da string "token" é "dim".
                    ss >> dimx >> dimy >> dimz;
                }
                else if(token.compare("putvoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> alpha;
                    figs.push_back(new PutVoxel(x, y, z, r, g, b, alpha)); 
                    // O método "push_back" adiciona uma posição no final do vetor.
                    // Além de chamar o construtor da classe, fazendo alocação dinâmica.
                }
                else if(token.compare("cutvoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z;
                    figs.push_back(new CutVoxel(x, y, z));
                }
                else if(token.compare("putbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> alpha;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, alpha));
                }
                else if(token.compare("cutbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }
                else if(token.compare("putsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> alpha;
                    figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, alpha));
                }
                else if(token.compare("cutsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
                }
                else if(token.compare("putellipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> alpha;
                    figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, alpha));
                }
                else if(token.compare("cutellipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
                }
            }
        }
    }
    arq.close();
    cout << "Arquivo do lightsaber gravado com sucesso!" << endl;
    return(figs); // Retorno do conteúdo.
}

/*
 * @Chamada dos métodos "get" para as dimensões a fim de criar a matriz tridimensional.
 */
int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}

int Interpretador::getDimz(){
    return dimz;
}
