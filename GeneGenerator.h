//
// Created by jose on 17/10/18.
//

#ifndef LOG_GENEGENERATOR_H
#define LOG_GENEGENERATOR_H


#include "Enemy.h"
#include <ctime>
#include <iostream>

class GeneGenerator {

public:
    int newGenes[4];
    int newMutationGenes[3];

    void newBreed(int fatherGenes [4], int motherGenes [4]){

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




        std::cout<<"start"<<std::endl;
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
                    if (std::rand() % 2 == 0) {
                        currentGenes[i] = motherGenes[i];
                    } else {
                        currentGenes[i] = fatherGenes[i];
                    }
                    //Mini-mutacion: 10% de probabilidad de aumentar 3 al gen heredado
                    if(std::rand()%100 < 10){
                        currentGenes[i] += 3;
                        std::cout<<"se sumo 3"<<std::endl;
                    }//Mini-mutacion: 20% de probabilidad de aumentar 1 al gen heredado
                    else if(std::rand()%100 < 20){
                        currentGenes[i] += 1;
                        std::cout<<"se sumo 1"<<std::endl;

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

            //Mutacion real, 5% de probabilidad de que ocurra
            if (std::rand()+std::rand() % 100 < 5) {
                std::cout<<std::rand()<<std::endl;
                std::cout << "mutacion" << std::endl;

            }
            std::cout<<"current Genes"<<std::endl;
            for (int i = 0; i < 4; i++) {
                std::cout << currentGenes[i] << std::endl;
            }
            std::cout<<"Gene score: "<<getGeneScore(currentGenes)<<std::endl;

        }
        std::cout<<"best Genes"<<std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << newGenes[i] << std::endl;
        }

    }
    int getGeneScore(int array[4]){
        int result = 0;
        for(int i = 0; i<4;i++){
            result+=array[i];
        }
        return result;
    }

    int searchDominantGene(const int gene[4]){
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
};


#endif //LOG_GENEGENERATOR_H
