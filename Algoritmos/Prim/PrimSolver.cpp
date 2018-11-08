#include "PrimSolver.h"
#include "../Estructuras/generadorGrafo.h"

int matrizInterfaz[10][12];

Pila<pair<int, int>> PrimSolver::prim(int columnaActual, int filaActual, int objColumna, int objFila, Grafo grafis){
    this->grafo = grafis;
    vector<VerticePrim> queue;
    VerticePrim current = this->grafo.getVertice(filaActual, columnaActual);
    VerticePrim temp;
    visitados.push_back(current);

    queue.push_back(current);
    vector<finalPath> prev;
    prev.push_back(finalPath{current.fila, current.columna, -1, -1});
    while (!queue.empty()) {
        current = queue.at(0);
        queue.erase(queue.begin());
        if (current.fila == objFila && current.columna == objColumna) {

            break;
        }
        for (int i = 0; i < current.arista->size(); i++) {

            temp = current.arista->at(i);
            if (!isVisitado(temp)) {
                visitados.push_back(temp);
                temp.peso = current.peso + 1;
                queue.push_back(temp);
                prev.push_back(finalPath{temp.fila, temp.columna, current.fila, current.columna});
            }
        }
    }

    return pilaGenerador(filaActual, columnaActual, objFila, objColumna, prev);
}

bool PrimSolver::isVisitado(VerticePrim vertice) {
    for (int i = 0; i < visitados.size(); i++) {
        if (visitados.at(i).columna == vertice.columna && visitados.at(i).fila == vertice.fila) {
            return true;
        }
    }
    return false;
}


Pila<pair<int, int>>
PrimSolver::pilaGenerador(int fila, int columna, int objFila, int objColumna, vector<finalPath> heapis) {
    Pila<pair<int, int>> pila;
    finalPath tempPath;
    for (int i = 0; i < heapis.size(); i++) {
        if (heapis.at(i).fila == objFila && heapis.at(i).columnna == objColumna) {
            tempPath = heapis.at(i);

        }
    }

    while (true) {
        if (tempPath.fila == fila && tempPath.columnna == columna) {
            break;
        }
        pila.push(make_pair(tempPath.fila, tempPath.columnna));

        tempPath = encontrarPrevPath(tempPath.prevFila, tempPath.prevComlumna, heapis);

    }
    return pila;

}

finalPath PrimSolver::encontrarPrevPath(int prevFila, int prevColumna, vector<finalPath> path) {
    finalPath temp;
    for (int i = 0; i < path.size(); i++) {
        temp = path.at(i);
        if (temp.fila == prevFila && temp.columnna == prevColumna) {
            return temp;
        }
    }

}

Pila<pair<int,int>> PrimSolver::start(int posYInicial, int posXInicial, int posYfinal, int posXfinal) {
    int matrizFinal[10][12];
    int pos = 0;
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 12; x++) {
            if (matrizInterfaz[y][x] == 0) {
                matrizFinal[y][x] = 1;
            } else if (matrizInterfaz[y][x] == 1 || matrizInterfaz[y][x] == 3) {
                matrizFinal[y][x] = 0;
            }
            pos++;
        }
    }

    generadorGrafo genGrafo;
    Grafo grafo = genGrafo.generarGrafo(matrizFinal);


    Pila<pair<int, int>> solucionCoordenadas = prim(posXInicial, posYInicial, posXfinal, posYfinal, grafo);
    while (solucionCoordenadas.getLenght() != 0) {
        int posX = solucionCoordenadas.peek().second;
        int posY = solucionCoordenadas.peek().first;
        cout << "El soldado se movio a la posicion " <<"("<< posX << "," << posY << ")"<< endl;

        solucionCoordenadas.pop();
    }

}

