//
// Created by jose on 01/11/18.
//

#include "Player.h"

using namespace std;

void Player::keyManager(int i, int level) {
    if(i == 1 && healCooldown == 0 && level>= 1){ //Curar a los aliados
        healCooldown = 1000;
        for(SoldierNode* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
            n->getSoldier()->recieveDamage(-500);

        }
        cout << "Curacion activada" << endl;

    }else if(i == 2 && doubleAttSpeedCooldown == 0&& level>= 1){ //Doble velocidad de ataque para los aliados
        doubleAttSpeedCooldown = 1000;

        manager->doubleAttSpeed = true;
        manager->doubleAttSpeedCounter = 400;
        for(SoldierNode* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
            n->getSoldier()->attSpeed /= 2;
        }
        cout << "Mas velocidad de ataque" << endl;

    }else if(i == 3 && reinfCooldown == 0&& level>= 2){ //Dos aliados llegan como refuerzos
        reinfCooldown = 1000;
        manager->callReinforcements();
        for(SoldierNode *n = manager->allyList->head; n!= nullptr; n= n->getNext()){

            cout<<n->getSoldier()->i<<n->getSoldier()->j<<endl;
        }
        cout << "Llego el bigote" << endl;

    }else if(i == 4 && killCooldown == 0&& level>= 2){ //Matar 2 enemigos
        manager->kill();
        killCooldown = 1000;
        cout << "KILL THEM ALL" << endl;

    }else if(i == 5 && doubleAttackCooldown == 0&& level>= 3){ //Doble daño a los aliados
        doubleAttackCooldown = 4000;
        manager->doubleAttack = true;
        manager->doubleAttackCounter = 400;
        for(SoldierNode* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
            n->getSoldier()->attack *= 2;
        }
        cout << "Doble dano activado" << endl;

    }else if(i == 6 && dmgAllCooldown == 0&& level>= 3){ //Daño a todos los enemigos
        dmgAllCooldown = 40000;
        for(SoldierNode* n = manager->getInstance()->enemyList->head; n != nullptr; n = n->getNext() ){
            n->getSoldier()->recieveDamage(150);
        }
        cout << "Feel it" << endl;

    }else if(i == 7 && invincibleCooldown == 0&& level>= 4){ //Aliados Invencibles por 7 ataques
        invincibleCooldown = 10000;
        for(SoldierNode* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
            n->getSoldier()->invincible = true;
            n->getSoldier()->invCounter = 3;
        }
        cout << "I´m invincible" << endl;
    }else if(i == 8 && lsCooldown == 0&& level>= 4){
        lsCooldown = 10000;
        for(SoldierNode* n = manager->getInstance()->allyList->head; n != nullptr; n = n->getNext() ){
            n->getSoldier()->lifeSteal = true;
            n->getSoldier()->lsCounter = 5;
        }
        cout << "The taste of your blood" << endl;
    }else if(i == 9 && reflectCooldown == 0&& level>= 5){
        reflectCooldown = 10000;
        for(SoldierNode* n = manager->getInstance()->enemyList->head; n != nullptr; n = n->getNext() ){
            n->getSoldier()->reflectDmg = true;
            n->getSoldier()->reflectDmgCounter = 2;
        }
        cout << "Refleccion activada" << endl;
    }

}

void Player::update() {
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
