//
// Created by jose on 31/10/18.
//

#include "Ally.h"
#include "SoldierManager.h"

void Ally::searchAndDestroy() {

}

void Ally::recieveDamage(int damage) {
    damage = damage - this->dmgReduction;
    this->hp -= damage;
    if(this->hp <= 0){
        SoldierManager::getInstance()->removeDeadAlly(this->ID);
    }
}


/*
void Ally::searchAndDestroy() {
    if (revisar arriba){
        this->dealDamage(enemigo de arriba);
    }else if( revisar abajo){
        this->dealDamage(enemigo de abajo);
    }else if( revisar derecha){
        this->dealDamage( enemigo de la derecha);
    }else if( revisar izquierda){
        this->dealDamage( enemigo de la izquierda);
    }
}*/
