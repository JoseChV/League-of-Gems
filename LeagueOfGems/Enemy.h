//
// Created by jose on 18/10/18.
//

#ifndef LEAGUE_OF_GEMS_ENEMY_H
#define LEAGUE_OF_GEMS_ENEMY_H


#include "Soldier.h"


class Enemy : public Soldier{

    int genes[4]; //0: ataque, 1: vida, 2: velocidad de ataque, 3: resistencia al daño.

public:

    Enemy(int genes[4]): Soldier(genes[0], genes[1], genes[2], genes[3],al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Raegen.png"),0){
        for(int i=0;i<4;i++) {
            this->genes[i] = genes[i];
        }
    }

    int getGene(int i);

    void setGene(int i, int value);



    void recieveDamage(int damage);
};


#endif //LEAGUE_OF_GEMS_ENEMY_H
