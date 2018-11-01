//
// Created by jose on 31/10/18.
//

#include "SoldierManager.h"
#include "Ally.h"


//crea las nuevas listas de enemigos y aliados
void SoldierManager::newLists() {
    for(int i = 0; i<15; i++){
        allyList->insert(new Ally());
    }
    int maxSize = (maxEnemies/3);
    if(!firstGeneration){
        int newGene1[4];
        int newGene2[4];
        int newGene3[4];
        generator->newBreed(mainGene1, mainGene2);
        for(int i = 0; i<4;i++){
            newGene3[i] = generator->newGenes[i];
        }
        generator->newBreed(mainGene1, mainGene3);
        for(int i = 0; i<4;i++){
            newGene2[i] = generator->newGenes[i];
        }
        generator->newBreed(mainGene3, mainGene2);
        for(int i = 0; i<4;i++){
            newGene1[i] = generator->newGenes[i];
        }
        for(int i = 0; i<4; i++){
            this->mainGene1[i] = newGene1[i];
            this->mainGene2[i] = newGene2[i];
            this->mainGene3[i] = newGene3[i];
        }
    }
    for(int i = 0; i < maxSize; i++){
        enemyList->insert(new Enemy(mainGene1));
        enemyList->insert(new Enemy(mainGene2));
        enemyList->insert(new Enemy(mainGene3));
    }
    enemyList->insert(new Enemy(mainGene2));
    enemyList->insert(new Enemy(mainGene1));
    this->firstGeneration = false;
}


//elimina los aliados muertos
void SoldierManager::removeDeadAlly(int allyID) {
    allyList->deleteNode(allyID);
}
//elimina los enemigos muertos
void SoldierManager::removeDeadEnemy(int enemyID) {
    enemyList->deleteNode(enemyID);
}

void SoldierManager::update() {

}
void SoldierManager::setMaxEnemies(int max) {
    this->maxEnemies = max;
}