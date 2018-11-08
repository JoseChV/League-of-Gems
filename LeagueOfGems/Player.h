//
// Created by jose on 01/11/18.
//

#ifndef LEAGUE_OF_GEMS_PLAYER_H
#define LEAGUE_OF_GEMS_PLAYER_H


#include "SoldierManager.h"

class Player {
private:
    SoldierManager* manager = SoldierManager::getInstance();

    int healCooldown = 0, doubleAttSpeedCooldown = 0, reinfCooldown = 0, killCooldown = 0, doubleAttackCooldown = 0, dmgAllCooldown = 0, invincibleCooldown = 0, lsCooldown = 0, reflectCooldown;
public:

    void keyManager(int i, int level);


    void update();
};


#endif //LEAGUE_OF_GEMS_PLAYER_H
