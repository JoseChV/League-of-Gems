//
// Created by jose on 30/10/18.
//

#include "Soldier.h"
void Soldier::recieveDamage(int damage){
    damage = damage - this->dmgReduction;
    this->hp -= damage;
}
void Soldier::dealDamage(Soldier* target)  {
    if(this->attCounter%this->attSpeed == 0) {
        target->recieveDamage(this->attack);
        this->attCounter = 0;
    }
    this->attCounter ++;


}
void Soldier::setID(int ID) {
    this->ID = ID;
}

void Soldier::searchAndDestroy() {

}