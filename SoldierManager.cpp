//
// Created by jose on 31/10/18.
//
#include "SoldierManager.h"
#include "Ally.h"
SoldierManager* SoldierManager::instance = nullptr;
SoldierManager* SoldierManager::getInstance() {
    if(SoldierManager::instance == nullptr){
        instance = new SoldierManager;
    }
    return instance;
}

//crea las nuevas listas de enemigos y aliados
void SoldierManager::newLists() {
    //borrar listas de enemigos y aliados
    int maxSize = maxEnemies/3;

    allyList = new LinkedList();
    enemyList = new LinkedList();

    if(!firstGeneration){

        int newGene1[4] = {0,0,0,0};
        int newGene2[4] = {0,0,0,0};
        int newGene3[4] = {0,0,0,0};
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
    for(int i = 0; i<15; i++){
        allyList->insert(new Ally());
    }
    std::cout<<"attack 1: "<<mainGene1[0]<<std::endl;
    std::cout<<"attack 2: "<<mainGene2[0]<<std::endl;
    std::cout<<"attack 3: "<<mainGene3[0]<<std::endl;
    for(int i = 0; i < maxSize; i++){
        enemyList->insert(new Enemy(this->mainGene1));
        enemyList->insert(new Enemy(this->mainGene2));
        enemyList->insert(new Enemy(this->mainGene3));

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
    for(Node* n = allyList->head; n!= nullptr; n = n->getNext()){
        n->getSoldier()->searchAndDestroy();
    }
    for(Node* n = enemyList->head; n!= nullptr; n = n->getNext()){
        n->getSoldier()->searchAndDestroy();
    }
}
void SoldierManager::setMaxEnemies(int max) {
    this->maxEnemies = max;
}