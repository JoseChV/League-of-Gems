//
// Created by jose on 30/10/18.
//

#ifndef LEAGUE_OF_GEMS_SOLDIER_H
#define LEAGUE_OF_GEMS_SOLDIER_H



class Soldier {
public:


    int attack, hp, attCounter = 0, attSpeed, dmgReduction, ID, invCounter = 0, lsCounter = 0, reflectDmgCounter = 0;
    int i,j;
    bool invincible = false, lifeSteal = false, reflectDmg = false;


    Soldier(int attack, int hp, int attSpeed, int dmgReduction){
        this->attack = 80 + attack * 29;
        this->hp = 500 + hp * 100;
        this->attSpeed = 40 - attSpeed;
        this->dmgReduction = 20 + dmgReduction;

    }

    void dealDamage(Soldier* target);

    virtual void recieveDamage(int damage){}

    void searchAndDestroy();

    void setID(int ID);

    void setPosition(int i, int j);

};


#endif //LEAGUE_OF_GEMS_SOLDIER_H
