#include <iostream>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "SoldierManager.h"
#include "Soldier.h"
#include "Player.h"
#include <vector>


//Valores de la ventana segun tamaño width x height
#define ScreenWidth 1200
#define ScreenHeight 1000

//Variables para crear las animaciones de los soldados
bool noMove = true;
bool canMove = true;
int frame = 0;
int maxEnemy = 20;
int lvl = 1;

int difficulty = 1;

using namespace std;

int easyD [10][12] = {
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 1, 1, 1, 0, 0, 0, 2, 2, 2, 2, 3},
        {3, 1, 1, 1, 0, 0, 0, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 0, 2, 2, 2, 4, 3},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

};

int mediumD [10][12] = {
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 1, 1, 1, 0, 0, 0, 0, 2, 2, 0, 3},
        {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 4, 3},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

};

int hardD [10][12] = {
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
        {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 4, 3},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

};



//Metodo para centrar el soldado en el centro del cuadro
int center (int pos)
{
    if (pos > 0 && pos <= 100){ return 18;}
    else if (pos > 100 && pos <= 200){ return 118;}
    else if (pos > 200 && pos <= 300){ return 218;}
    else if (pos > 300 && pos <= 400){ return 318;}
    else if (pos > 400 && pos <= 500){ return 418;}
    else if (pos > 500 && pos <= 600){ return 518;}
    else if (pos > 600 && pos <= 700){ return 618;}
    else if (pos > 700 && pos <= 800){ return 718;}
    else if (pos > 800 && pos <= 900){ return 818;}
    else if (pos > 900 && pos <= 1000){ return 918;}
    else if (pos > 1000 && pos <= 1100){ return 1018;}
    else if (pos > 1100 && pos <= 1200){ return 1118;}
}

//Metodo que crea el escenario a partir de una matriz 10x12
//0 es terreno
//1 obstaculos
void drawMap(ALLEGRO_BITMAP *Map,ALLEGRO_BITMAP *obstacule,int matriz[10][12], ALLEGRO_BITMAP *gem)
{
    int posX = 1;
    int posY = 1;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 12; j++){

            if (matriz [i][j] == 0 || matriz [i][j] == 1 || matriz [i][j] == 2)
            {
                al_draw_bitmap_region(Map, 0, 0, 98, 98, posX, posY, 0);

                posX += 100;

            }
            else if (matriz [i][j] == 3)
            {
                al_draw_bitmap_region(obstacule, 0, 0, 98, 98, posX, posY, 0);
                posX += 100;
            } else if (matriz [i][j] == 4 || matriz [i][j] == 6)
            {
                al_draw_bitmap_region(gem, 0, 0, 98, 98, posX, posY, 0);
                posX += 100;
            }

        }
        if (posX == 1201)
        {
            posX = 1;
            posY += 100;
        }

    }


}

void drawBattleMap (SoldierManager *manager)
{

    for(SoldierNode*n = manager->allyList->head; n!= nullptr; n = n->getNext()){
        //X y Y están invertidos acá
       n->getSoldier()->draw(n->getSoldier()->posY, n->getSoldier()->posX);


    }
    for(SoldierNode*n = manager->enemyList->head; n!= nullptr; n = n->getNext()){
        n->getSoldier()->draw((n->getSoldier()->j * 100 + 18), (n->getSoldier()->i * 100) + 18);

    }



}

void newLevel(SoldierManager* manager) {

    lvl++;
    cout << lvl << endl;
    if(lvl == 6) {

        ALLEGRO_BITMAP *Victory = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Victory.png");
        while (true) {
            al_draw_bitmap(Victory, 290, 314, 0);
            al_flip_display();

        }
    }
    manager->newLists();
    if (difficulty == 1) {
        if (lvl == 2) {

            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 0, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 3, 0, 0, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 0, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    easyD[i][j] = matriz[i][j];
                }
            }

            manager->setMatriz(easyD);


        } else if (lvl == 3) {

            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 3, 3, 0, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    easyD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(easyD);

        } else if (lvl == 4) {
            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    easyD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(easyD);

        } else if (lvl == 5) {
            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    easyD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(easyD);

        }
    }else if (difficulty == 2)
    {
        if (lvl == 2) {

            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 2, 2, 0, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 3, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    mediumD[i][j] = matriz[i][j];
                }
            }

            manager->setMatriz(mediumD);


        } else if (lvl == 3) {

            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 2, 2, 0, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 3, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    mediumD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(mediumD);

        } else if (lvl == 4) {
            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 3, 3, 0, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 3, 2, 2, 3, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    mediumD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(mediumD);

        } else if (lvl == 5) {
            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 2, 2, 0, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    mediumD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(mediumD);

        }
    }
    else{
        if (lvl == 2) {

            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 3, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    mediumD[i][j] = matriz[i][j];
                }
            }

            manager->setMatriz(mediumD);


        } else if (lvl == 3) {

            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 3, 0, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    mediumD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(mediumD);

        } else if (lvl == 4) {
            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 3, 0, 0, 0, 0, 3, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2 ,2, 3},
                    {3, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 3, 2, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    mediumD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(mediumD);

        } else if (lvl == 5) {
            int matriz[10][12] = {
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                    {3, 1, 1, 1, 0, 0, 3, 0, 0, 0, 0, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 1, 1, 1, 3, 2, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 3},
                    {3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 4, 3},
                    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}

            };
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 12; j++) {
                    mediumD[i][j] = matriz[i][j];
                }
            }
            manager->setMatriz(mediumD);

        }
    }




        manager->setPos();

}

void render(SoldierManager *manager, int matrizM [10][12], ALLEGRO_BITMAP *map, ALLEGRO_BITMAP *obs, ALLEGRO_BITMAP *gem){

    drawMap(map, obs, matrizM, gem);
    drawBattleMap(manager);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

int main() {

    cout << "Q: Curacion" << endl;
    cout << "W: x2 Velocidad de ataque" << endl;
    cout << "E: Refuerzos" << endl;
    cout << "R: Ejecutar Enemigos" << endl;
    cout << "D: x2 Dano" << endl;
    cout << "F: Dano a todos" << endl;
    cout << "Space: Invencibilidad" << endl;
    cout << "A: Robo de Vida" << endl;
    cout << "B: Reflejo de dano recibido" << endl;


    //se crea el display o ventana
    ALLEGRO_DISPLAY *display;

    //matriz paara el mapa 10 x 12


    //Direcciones en las que se va a mover el personaje una vez que se clickee
    //La primera palabra representa a la derecha o izquierda
    //la ultima letra arriba o abajo
    enum direction {
        LEFTU, LEFTD, RIGHTU, RIGHTD,LEFT, UP, RIGHT, DOWN, NONE
    };

    const float fps = 60.0;
    const int interval = 5;

    //se inicia allegro
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    //se le da las dimensiones a la ventana
    display = al_create_display(ScreenWidth, ScreenHeight);

    //Se cerifica si existe algun error al crear la ventana
    if (!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
    //Posicion el la que saldrá la ventana en la pantalla
    al_set_window_position(display, 450, 10);
    al_set_window_title(display, "League Of Gems");

    //Variables que se utilizaran para crear salidas y restricciones del juego
    bool done = false, active = false;
    int x, y, goX, goY, moveSpeed = 10;
    int dirRL = NONE;
    int dirUD = NONE;
    int dir = NONE;

    //posicion en X y Y en las que inician los personajes
    int posX = 18, posY = 18;

    al_install_mouse();
    al_install_keyboard();
    al_init_image_addon();

    //Se cargan las imagenes



    ALLEGRO_BITMAP *map = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Grass.png");
    ALLEGRO_BITMAP *obstacule = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/NewTree.png");
    ALLEGRO_BITMAP *gem = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Gem.png");


    //Se crean los timers y cola de eventos
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / fps);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    //se mete all dentro de la cola de eventos
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue,al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    //Se inicial el timer
    al_start_timer(timer);

    Player* player = new Player();


    SoldierManager *manager = SoldierManager :: getInstance();
    manager->setMaxEnemies(maxEnemy);
    manager->newLists();
    manager->setMatriz(easyD);
    manager->setPos();

    SoldierNode *n = manager->allyList->head;

    //Bucle del juego
    while (!done)
    {
        //Variable eventos sobre la que funciona el juego
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        render(manager, easyD, map, obstacule, gem);

        player->update();

        if(manager->matriz[8][10] == 1){

            newLevel(manager);
        }



        //Verifica si se presiona la x de la ventana para cerrar el juego
        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;

        }
        //Se verifica si el personaje no se está moviendo para poner su imagen inicial
        if (noMove == true)
        {
            n = manager->allyList->head;

        }

        //da los valores en X y Y de donde esta el mouse en la ventana
        if (events.type == ALLEGRO_EVENT_MOUSE_AXES)
        {

            goX = events.mouse.x;
            goY = events.mouse.y;
        }

        if (events.type == ALLEGRO_EVENT_KEY_DOWN){
            switch (events.keyboard.keycode)
            {
                case ALLEGRO_KEY_F1:
                    lvl = 1;
                    manager->setMaxEnemies(20);
                    manager->newLists();
                    manager->setMatriz(easyD);
                    manager->setPos();
                    difficulty = 1;
                    cout << "Facil" << endl;
                    break;
                case ALLEGRO_KEY_F2:
                    lvl = 1;
                    manager->setMaxEnemies(25);
                    manager->newLists();
                    manager->setMatriz(mediumD);
                    manager->setPos();
                    difficulty = 2;
                    cout << "Medio" << endl;
                    break;
                case ALLEGRO_KEY_F3:
                    lvl = 1;
                    manager->setMaxEnemies(35);
                    manager->newLists();
                    manager->setMatriz(hardD);
                    manager->setPos();
                    difficulty = 3;
                    cout << "Dificil" << endl;
                    break;
                case ALLEGRO_KEY_Q:
                    cout << "Q" << endl;

                    player->keyManager(1,lvl);
                    break;
                case ALLEGRO_KEY_W:
                    cout << "W" << endl;
                    player->keyManager(2,lvl);
                    break;
                case ALLEGRO_KEY_E:
                    player->keyManager(3,lvl);
                    cout << "E" << endl;
                    break;
                case ALLEGRO_KEY_R:
                    player->keyManager(4,lvl);
                    cout << "R" << endl;
                    break;
                case ALLEGRO_KEY_D:
                    player->keyManager(5,lvl);
                    cout << "D" << endl;
                    break;
                case ALLEGRO_KEY_F:
                    player->keyManager(6,lvl);
                    cout << "F" << endl;
                    break;
                case ALLEGRO_KEY_SPACE:
                    player->keyManager(7,lvl);
                    cout << "Space" << endl;
                    break;
                case ALLEGRO_KEY_A:
                    player->keyManager(8,lvl);
                    cout << "A" << endl;
                    break;
                case ALLEGRO_KEY_B:
                    player->keyManager(9,lvl);
                    cout << "B" << endl;
                    break;
            }
        }
        //Evento que verifica si se presiono un boton del mouse
        if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            //verifica que el no se esté moviendo hacia una casilla antes de darle otra ubicacion
            if (canMove == true) {
                //Verifica si el click que se presionó es el derecho
                if (events.mouse.button & 2) {

                    //centra los valores del click
                    int xi = (center(goY) - 18)/100;
                    int yj = (center(goX) - 18)/100;


                    manager->backTrackMove(xi,yj);



                    n = manager->allyList->head;



                    posX = n->getSoldier()->posX;
                    posY = n->getSoldier()->posY;



                    x = (n->getSoldier()->targetI * 100) + 18;
                    y = (n->getSoldier()->targetJ * 100) + 18;



                    n->getSoldier()->frame = 1;



                    active = true;
                    noMove = false;
                    canMove = false;


                    //busca en que direccion debe moverse el soldado
                    if (posX <= x && posY <= y) {
                        dir = RIGHTD;
                    } else if (posX <= x && posY >= y) {
                        dir = RIGHTU;
                    } else if (posX >= x && posY <= y) {
                        dir = LEFTD;

                    } else {
                        dir = LEFTU;

                    }



                }
            }
        }
        //Verifica si se active es verdadero (se vuelve verdadero al momento de dar click derecho)
        else if (active == true) {
            if (events.type == ALLEGRO_EVENT_TIMER) {

                if (n == nullptr) {



                    dirRL = NONE;
                    dirUD = NONE;
                    dir = NONE;
                    active = false;
                    noMove = true;
                    canMove = true;
                    for(SoldierNode*a = manager->allyList->head;a != nullptr; a = a->getNext()){
                        a->getSoldier()->i = a->getSoldier()->targetI;
                        a->getSoldier()->j = a->getSoldier()->targetJ;
                    }
                    manager->setNewPos();

                }else {
                    if (dir == RIGHTD) {
                        if (posY != y) {
                            n->getSoldier()->posY += moveSpeed;
                            posY = n->getSoldier()->posY;
                            n->getSoldier()->direction = 2;

                        } else if (posX != x) {
                            n->getSoldier()->posX += moveSpeed;
                            posX = n->getSoldier()->posX;
                            n->getSoldier()->direction = 3;

                        }


                    }
                    if (dir == RIGHTU) {
                        if (posY != y) {
                            n->getSoldier()->posY -= moveSpeed;
                            posY = n->getSoldier()->posY;
                            n->getSoldier()->direction = 2;

                        } else if (posX != x) {
                            n->getSoldier()->posX += moveSpeed;
                            posX = n->getSoldier()->posX;
                            n->getSoldier()->direction = 1;

                        }


                    }
                    if (dir == LEFTD) {
                        if (posY != y) {
                            n->getSoldier()->posY += moveSpeed;
                            posY = n->getSoldier()->posY;
                            n->getSoldier()->direction = 4;

                        } else if (posX != x) {
                            n->getSoldier()->posX -= moveSpeed;
                            posX = n->getSoldier()->posX;
                            n->getSoldier()->direction = 3;

                        }


                    }
                    if (dir == LEFTU) {
                        if (posY != y) {
                            n->getSoldier()->posY -= moveSpeed;
                            posY = n->getSoldier()->posY;
                            n->getSoldier()->direction = 4;

                        } else if (posX != x) {
                            n->getSoldier()->posX -= moveSpeed;
                            posX = n->getSoldier()->posX;
                            n->getSoldier()->direction = 1;

                        }


                    }



                    if (posX == x && posY == y) {


                        n->getSoldier()->direction = 0;
                        n = n->getNext();
                        if (n != nullptr) {

                            posX = n->getSoldier()->posX;
                            posY = n->getSoldier()->posY;
                            x = (n->getSoldier()->targetI * 100) + 18;
                            y = (n->getSoldier()->targetJ * 100) + 18;
                            n->getSoldier()->frame = 1;




                            if (posX <= x && posY <= y) {
                                dir = RIGHTD;
                            } else if (posX <= x && posY >= y) {
                                dir = RIGHTU;
                            } else if (posX >= x && posY <= y) {
                                dir = LEFTD;
                            } else {
                                dir = LEFTU;
                            }


                        }

                    }

                }


            }
        }



    }

 // destruye la ventana y se sale
    al_destroy_display(display);
    al_destroy_timer(timer);

    al_destroy_event_queue(event_queue);

    return 0;
}

