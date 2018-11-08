#ifndef ALGORITMOS_PRIMSOLVER_H
#define ALGORITMOS_PRIMSOLVER_H
#include <iostream>
#include <vector>
#include "../Estructuras/Grafo.h"
#include "../Estructuras/Pila.h"

using namespace std;

struct finalPath{
    int fila, columnna, prevFila, prevComlumna;
    finalPath(){

    }
    finalPath(int fila, int columna, int prevFila, int prevColumna){
        this->columnna=columna;
        this->fila=fila;
        this->prevComlumna=prevColumna;
        this->prevFila=prevFila;
    }
};



class PrimSolver {
private:
    Grafo grafo;
    vector<VerticePrim> visitados;
    bool isVisitado(VerticePrim vertice);
    Pila<pair<int,int>> pilaGenerador(int fila, int columna, int objFila, int objColumna, vector<finalPath> heapis);
    finalPath encontrarPrevPath(int prevFila, int prevColumna, vector<finalPath> path);


public:
    Pila<pair<int, int>> prim(int columnaActual, int filaActual, int objColumna, int objFila, Grafo grafis);
    Pila<pair<int,int>> start(int posYinicial, int posXinicial, int posYfinal, int posXfinal);



};
#endif //ALGORITMOS_PRIMSOLVER_H
