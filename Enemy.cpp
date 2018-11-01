//
// Created by jose on 18/10/18.
//

#include "Enemy.h"
#include "SoldierManager.h"


int Enemy::getGene(int i) {
    return genes[i];
}
void Enemy::setGene(int i, int value) {
    this->genes[i] = value;
}

void Enemy::recieveDamage(int damage) {
    damage = damage - this->dmgReduction;
    this->hp -= damage;
    if(this->hp <= 0){
        SoldierManager::getInstance()->removeDeadEnemy(this->ID);
    }
}

void Enemy::searchAndDestroy() {
    /*if (revisar arriba){
        this->dealDamage(enemigo de arriba);
    }else if( revisar abajo){
        this->dealDamage(enemigo de abajo);
    }else if( revisar derecha){
        this->dealDamage( enemigo de la derecha);
    }else if( revisar izquierda){
        this->dealDamage( enemigo de la izquierda);
    }*/
}