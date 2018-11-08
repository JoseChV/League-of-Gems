//
// Created by jose on 30/10/18.
//
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#ifndef LEAGUE_OF_GEMS_SOLDIER_H
#define LEAGUE_OF_GEMS_SOLDIER_H



class Soldier {
public:


    ALLEGRO_BITMAP *image;
    int attack, hp, attCounter = 0, attSpeed, dmgReduction, ID, invCounter = 0, lsCounter = 0, reflectDmgCounter = 0;
    int i = 0,j = 0, frame  = 0, direction = 0, posX = 0, posY = 0, targetI = 0, targetJ = 0;
    bool invincible = false, lifeSteal = false, reflectDmg = false;
    int genes[4];

    ALLEGRO_BITMAP *health = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Green.png");
    int maxHealth;


    Soldier(int attack, int hp, int attSpeed, int dmgReduction, ALLEGRO_BITMAP *image, int frame){
        int gen[4] = {attack,hp,attSpeed,dmgReduction};
        for(int i = 0; i<4;i++){
            this->genes[i] = gen[i];
        }

        this->attack = 80 + attack * 29;
        this->hp = 500 + hp * 100;
        this->attSpeed = 40 - attSpeed;
        this->dmgReduction = 20 + dmgReduction;
        this->frame = frame;
        this->image = image;
        this->maxHealth = this->hp;

    }

    void dealDamage(Soldier* target);

    virtual void recieveDamage(int damage){}


    void setID(int ID);

    void setPosition(int i, int j);

    void draw ( int posX, int posY);

    void moveFrame (int posX, int posY, int frameSprite);


};


#endif //LEAGUE_OF_GEMS_SOLDIER_H
