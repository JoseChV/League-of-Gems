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

    void newBreed(int fatherGenes [4], int motherGenes [4]);

    int getGeneScore(int array[4]);

    int searchDominantGene(const int gene[4]);
};


#endif //LOG_GENEGENERATOR_H
