

#ifndef ALGORITMOS_PATHFINDING_H
#define ALGORITMOS_PATHFINDING_H
#include<bits/stdc++.h>
#include "../Estructuras/Pila.h"

#define FILA 10
#define COLUMNA 12

typedef std::pair<int, int> Pair;
typedef std:: pair<double, std::pair<int, int>> pPair;

struct celda{
    int parent_i, parent_j;
    double f, g, h;
};

class Pathfinding {

public:
    bool esValido(int fila, int columna);
    bool estaDesbloqueda(int grid[][COLUMNA], int fila, int columna);
    bool esDestino(int fila, int columna, Pair destino);
    double calcularValorH(int fila, int columna, Pair destino);
    Pila<Pair> trazarCamino(celda detallesCelda[][COLUMNA], Pair destino);
    Pila<Pair> busquedaAStar(int grid[][COLUMNA], Pair inicio, Pair destino);
    Pila<Pair> start(int posXinicial, int posYinicial, int posXfinal, int posYfinal);
    Pila<Pair> ruta;
    Pair inicio;
    Pair objetivo;




};

#endif //ALGORITMOS_PATHFINDING_H
