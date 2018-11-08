
#include <iostream>
#include <stdio.h>
#include <vector>
#include "../Estructuras/Pila.h"
#include "../Estructuras/Grafo.h"

using namespace std;

struct rutaOptima{
    int fila, columnna, prevFila, prevComlumna;
    rutaOptima(){

    }
    rutaOptima(int fila, int columna, int prevFila, int prevColumna){
        this->columnna=columna;
        this->fila=fila;
        this->prevComlumna=prevColumna;
        this->prevFila=prevFila;
    }
};



class Kruskal {
private:
    Grafo grafo;
    vector<VerticePrim> visitados;
    bool isVisitado(VerticePrim vertice);
    Pila<pair<int,int>> pilaGenerador(int fila, int columna, int objFila, int objColumna, vector<rutaOptima> heapis);
    rutaOptima encontrarPrevPath(int prevFila, int prevColumna, vector<rutaOptima> path);


public:
    Pila<pair<int, int>> busquedaKruskal(int columnaActual, int filaActual, int objColumna, int objFila, Grafo grafis);
    Pila<pair<int,int>> start(int posYinicial, int posXinicial, int posYfinal, int posXfinal);



};
