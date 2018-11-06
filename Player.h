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
    void clickEvent(){}

    void keyManager(int i){
        if(i == 1 && healCooldown == 0){ //Curar a los aliados
            healCooldown = 40000;
            for(Node* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
                n->getSoldier()->recieveDamage(-500);
            }

        }else if(i == 2 && doubleAttSpeedCooldown == 0){ //Doble velocidad de ataque para los aliados
            doubleAttSpeedCooldown = 40000;

            manager->doubleAttSpeed = true;
            manager->doubleAttSpeedCounter = 400;
            for(Node* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
                n->getSoldier()->attSpeed /= 2;
            }

        }else if(i == 3 && reinfCooldown == 0){ //Dos aliados llegan como refuerzos
            reinfCooldown = 40000;
            manager->callReinforcements();

        }else if(i == 4 && killCooldown == 0){ //Matar 2 enemigos
            manager->kill();
            killCooldown = 60000;

        }else if(i == 5 && doubleAttackCooldown == 0){ //Doble daño a los aliados
            doubleAttackCooldown = 40000;
            manager->doubleAttack = true;
            manager->doubleAttackCounter = 400;
            for(Node* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
                n->getSoldier()->attack *= 2;
            }

        }else if(i == 6 && dmgAllCooldown == 0){ //Daño a todos los enemigos
            dmgAllCooldown = 40000;
            for(Node* n = manager->getInstance()->enemyList->head; n != nullptr; n = n->getNext() ){
                n->getSoldier()->recieveDamage(500);
            }

        }else if(i == 7 && invincibleCooldown == 0){ //Aliados Invencibles por 7 ataques
           invincibleCooldown = 10000;
           for(Node* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
                n->getSoldier()->invincible = true;
                n->getSoldier()->invCounter = 7;
           }
        }else if(i == 8 && lsCooldown == 0){
            lsCooldown = 10000;
            for(Node* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
                n->getSoldier()->lifeSteal = true;
                n->getSoldier()->lsCounter = 7;
            }

        }else if(i == 9 && reflectCooldown == 0){
            reflectCooldown = 10000;
            for(Node* n = manager->getInstance()->enemyList->head; n != nullptr; n = n->getNext() ){
                n->getSoldier()->reflectDmg = true;
                n->getSoldier()->reflectDmgCounter = 5;
            }
        }

    }


    void update(){
        manager->update();

        if(healCooldown>0){
            healCooldown --;
        }
        if(doubleAttSpeedCooldown>0){
            doubleAttSpeedCooldown--;
        }
        if(reinfCooldown>0){
            reinfCooldown--;
        }
        if(killCooldown>0){
            killCooldown--;
        }
        if(doubleAttackCooldown>0){
            doubleAttackCooldown--;
        }
        if(dmgAllCooldown>0){
            dmgAllCooldown--;
        }
        if(invincibleCooldown>0){
            invincibleCooldown--;
        }
        if(lsCooldown>0){
            lsCooldown--;
        }
        if(reflectCooldown>0){
            reflectCooldown--;
        }
    }
};


#endif //LEAGUE_OF_GEMS_PLAYER_H
