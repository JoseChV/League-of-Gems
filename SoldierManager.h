//
// Created by jose on 31/10/18.
//

#ifndef LEAGUE_OF_GEMS_SOLDIERMANAGER_H
#define LEAGUE_OF_GEMS_SOLDIERMANAGER_H


#include "LinkedList.h"
#include "GeneGenerator.h"

class SoldierManager {
private:
    static SoldierManager* instance;
    SoldierManager() = default;

    GeneGenerator* generator = new GeneGenerator();

    int mainGene1[4] = {2,1,3,0};
    int mainGene2[4] = {1,2,1,2};
    int mainGene3[4] = {2,1,2,1};

    bool firstGeneration = true;

public:

    int doubleAttSpeedCounter = 0, doubleAttackCounter = 0;
    bool doubleAttSpeed = false, doubleAttack = false;

    static SoldierManager* getInstance();

    LinkedList* enemyList = new LinkedList();
    LinkedList* allyList = new LinkedList();

    int maxEnemies;

    void update();

    void removeDeadAlly(int allyID);

    void removeDeadEnemy(int enemyID);

    void newLists();

    void setMaxEnemies(int max);

    void callReinforcements();

    void kill();
};


#endif //LEAGUE_OF_GEMS_SOLDIERMANAGER_H
