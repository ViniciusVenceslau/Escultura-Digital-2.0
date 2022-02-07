#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"
/**
 *@Classe abstrata que serve para representar objetos primitivos genericos.
 *@Diversos tipos de formas então inseridas dentro do campo figura geométrica.
 *@É a classe "mãe" para os tipos de figuras geométricas que serão criadas. Neste contexto, as classses concretas (filhas).
 */
class FiguraGeometrica{
protected:
    float r, g, b, alpha;
public:
    virtual ~FiguraGeometrica(){}; // Destrutor
    virtual void draw(Sculptor &s)=0; /*
                                       *@Função Virtual Pura.
                                       *@"virtual" -> Faz com que o programa execute os métodos das subclasses e não da superclasse.
                                      */
};

#endif // FIGURAGEOMETRICA_H
