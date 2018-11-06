//
// Created by jose on 31/10/18.
//

#include "Ally.h"
#include "SoldierManager.h"

void Ally::searchAndDestroy() {

}

void Ally::recieveDamage(int damage) {
    if(!invincible){
        damage = damage - this->dmgReduction;
        this->hp -= damage;
        if(this->hp <= 0){
            SoldierManager::getInstance()->removeDeadAlly(this->ID);
        }
    }else{
        invCounter--;
        if(invCounter == 0){
            invincible = false;
        }
    }
}
