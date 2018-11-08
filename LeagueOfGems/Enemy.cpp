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
        SoldierManager::getInstance()->matriz[i][j] = 0;
        SoldierManager::getInstance()->removeDeadEnemy(this->ID);

    }
}
