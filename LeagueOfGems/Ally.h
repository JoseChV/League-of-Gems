//
// Created by jose on 31/10/18.
//

#ifndef LEAGUE_OF_GEMS_ALLY_H
#define LEAGUE_OF_GEMS_ALLY_H


#include "Soldier.h"

class Ally: public Soldier {

public:
    Ally():Soldier(10,10,10,10,al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Lasswell.png"),0){
    }


    void recieveDamage(int damage);
};


#endif //LEAGUE_OF_GEMS_ALLY_H
