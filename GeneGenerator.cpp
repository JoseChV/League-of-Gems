//
// Created by jose on 17/10/18.
//

#include "GeneGenerator.h"
using namespace std;


void GeneGenerator::newBreed(int *fatherGenes, int *motherGenes) {

    int bestScore = 0;

    int fatherScore = getGeneScore(fatherGenes);
    int motherScore = getGeneScore(motherGenes);
    //Determina el valor del mejor gen
    if( fatherScore > motherScore){
        bestScore = fatherScore;
    }else{
        bestScore = motherScore;
    }

    int fatherDominant = searchDominantGene(fatherGenes);
    int motherDominant = searchDominantGene(motherGenes);




    for(int iteraciones = 0; iteraciones<10; iteraciones++) {

        int currentGenes [4] = {0,0,0,0};

        //Si el gen dominante de ambos padres es el mismo, se le asigna al hijo y se le suma 2
        if (fatherDominant == motherDominant) {
            currentGenes[fatherDominant] = fatherGenes[fatherDominant] + 2;
        }

        //Se inicia el proceso de generar un nuevo gen
        for (int i = 0; i < 4; i++) {
            if (currentGenes[i] == 0) {
                //Asigna el valor del gen de uno de sus padres en un espacio vacio, quien lo hereda es un 50/50
                if (rand() % 2 == 0) {
                    currentGenes[i] = motherGenes[i];
                } else {
                    currentGenes[i] = fatherGenes[i];
                }
                //Mini-mutacion: 10% de probabilidad de aumentar 3 al gen heredado
                if(rand()%100 < 10){
                    currentGenes[i] += 3;
                }//Mini-mutacion: 20% de probabilidad de aumentar 1 al gen heredado
                else if(rand()%100 < 20){
                    currentGenes[i] += 1;

                }
            }
        }
        //Si el puntaje de este gen supera el mejor actual, este se convierte en el mejor actual
        if(bestScore<getGeneScore(currentGenes)){
            bestScore = getGeneScore(currentGenes);
            for (int i = 0; i < 4; i++) {
                newGenes[i] = currentGenes[i];
            }
        }

        for (int i = 0; i < 4; i++) {
            std::cout << currentGenes[i] << std::endl;
        }

    }
    for (int i = 0; i < 4; i++) {
        std::cout << newGenes[i] << std::endl;
    }

}
int GeneGenerator::getGeneScore(int *array) {
    int result = 0;
    for(int i = 0; i<4;i++){
        result+=array[i];
    }
    return result;
}
int GeneGenerator::searchDominantGene(const int *gene) {
    int dominantIndex = 0;
    int greater = 0;
    for (int i = 0; i < 4; i++){
        if(gene[i] > greater){
            dominantIndex = i;
            greater = gene[i];
        }
    }
    return dominantIndex;
}