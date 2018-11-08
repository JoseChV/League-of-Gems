//
// Created by jose on 31/10/18.
//

#ifndef LEAGUE_OF_GEMS_SOLDIERMANAGER_H
#define LEAGUE_OF_GEMS_SOLDIERMANAGER_H


#include "SoldierList.h"
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

    int matriz[10][12];
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

    void setMatriz(int matriz[10][12]);

    void seekAndDestroy();

    void setPos();

    void backTrackMove(int i, int j);

    void walk(int i, int j);

    void setNewPos();

    void printMatriz();
};


#endif //LEAGUE_OF_GEMS_SOLDIERMANAGER_H
