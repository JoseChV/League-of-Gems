//
// Created by jose on 30/10/18.
//

#include "Soldier.h"
#include "SoldierManager.h"


void Soldier::dealDamage(Soldier* target)  {
    if(lifeSteal){
        this->recieveDamage(-(this->attack - target->dmgReduction));
        lsCounter--;
        if(lsCounter == 0){
            lifeSteal = false;
        }
    }
    if(reflectDmg){
        this->recieveDamage((this->attack - target->dmgReduction));
        reflectDmgCounter--;
        if(reflectDmgCounter == 0){
            reflectDmg = false;
        }
    }
    if (this->attCounter % this->attSpeed == 0) {
        target->recieveDamage(this->attack);
        this->attCounter = 0;
    }
    this->attCounter++;

}
void Soldier::setID(int ID) {
    this->ID = ID;
}

void Soldier::setPosition(int i, int j) {
    this->i = i;
    this->j = j;
}

void Soldier::searchAndDestroy() {

}