//
// Created by jose on 30/10/18.
//

#ifndef LEAGUE_OF_GEMS_SOLDIER_H
#define LEAGUE_OF_GEMS_SOLDIER_H


class Soldier {
public:
    int attack, hp, attCounter = 0, attSpeed, dmgReduction, ID;
    int i,j;

    Soldier(int attack, int hp, int attSpeed, int dmgReduction){
        this->attack = 80 + attack * 4;
        this->hp = 500 + hp * 10;
        this->attSpeed = 40 - attSpeed;
        this->dmgReduction = 20 + dmgReduction;

    }

    void dealDamage(Soldier* target);

    void recieveDamage(int damage);

    void searchAndDestroy();

    void setID(int ID);
};


#endif //LEAGUE_OF_GEMS_SOLDIER_H
