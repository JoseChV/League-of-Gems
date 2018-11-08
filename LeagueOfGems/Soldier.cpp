//
// Created by jose on 30/10/18.
//

#include "Soldier.h"
#include "SoldierManager.h"
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>



void Soldier::dealDamage(Soldier* target)  {
    if(lifeSteal){
        this->recieveDamage(-(this->attack - target->dmgReduction));
        lsCounter--;
        if(lsCounter == 0){
            lifeSteal = false;
        }
    }
    if(reflectDmg){
        this->recieveDamage((this->attack - target->dmgReduction));
        reflectDmgCounter--;
        if(reflectDmgCounter == 0){
            reflectDmg = false;
        }
    }
    if (this->attCounter % this->attSpeed == 0) {
        target->recieveDamage(this->attack);
        this->attCounter = 0;
    }
    this->attCounter++;

}
void Soldier::setID(int ID) {
    this->ID = ID;
}

void Soldier::setPosition(int i, int j) {
    this->i = i;
    this->j = j;
}


void Soldier::draw ( int posX, int posY)
{

    if (frame == 7){

        frame = 1;

    }
    if (this->direction == 0)
    {
        moveFrame(posX, posY, 0);
    }

    else if (this->direction == 1){

        moveFrame (posX, posY, 576);

    } else if (this->direction == 2){

        moveFrame (posX, posY, 704);


    } else if (this->direction == 3){

        moveFrame (posX, posY, 512);

    } else if (this->direction == 4){

        moveFrame (posX, posY, 640);

    }
}
void Soldier::moveFrame ( int posX, int posY, int frameSprite){

    al_draw_bitmap_region(this->health, 0, 0, (hp * 100 / maxHealth) * 0.82, 6, posX - 9, posY - 8, 0);

    if (frame == 0){

        al_draw_bitmap_region(this->image, 0, 0, 64, 64, posX, posY, 0);

    }

    else if(frame == 1) {

        al_draw_bitmap_region(this->image, 64, frameSprite, 64, 64, posX, posY, 0);

        frame += 1;

    }else if (frame == 2){

        al_draw_bitmap_region(this->image, 128, frameSprite, 64, 64, posX, posY, 0);

        frame += 1;

    }else if (frame == 3) {

        al_draw_bitmap_region(this->image, 192, frameSprite, 64, 64, posX, posY, 0);

        frame += 1;

    }else if (frame == 4){

        al_draw_bitmap_region(this->image, 256, frameSprite, 64, 64, posX, posY, 0);

        frame += 1;

    }else if (frame == 5){

        al_draw_bitmap_region(this->image, 320, frameSprite, 64, 64, posX, posY, 0);


        frame += 1;

    }else{

        al_draw_bitmap_region(this->image, 384, frameSprite, 64, 64, posX, posY, 0);

        frame += 1;

    }



}
