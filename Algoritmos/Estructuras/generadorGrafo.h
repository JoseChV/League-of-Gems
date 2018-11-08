//
// Created by kevinfgn on 11/7/18.
//

#ifndef ALGORITMOS_GENERADORGRAFO_H
#define ALGORITMOS_GENERADORGRAFO_H

#include "Grafo.h"


class generadorGrafo {
public:
    ///Dimensiones de la matriz
    const static int defFilas = 10;
    const static int defColas = 12;
    Grafo grafo;
    Grafo generarGrafo(int matriz[defFilas][defColas]);

    bool isPermitido(int fila, int columna, int matrix[defFilas][defColas]);

};

#endif //ALGORITMOS_GENERADORGRAFO_H
