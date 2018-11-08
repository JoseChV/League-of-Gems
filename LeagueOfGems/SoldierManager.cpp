//
// Created by jose on 31/10/18.
//
#include "SoldierManager.h"
#include "Ally.h"

using namespace std;
SoldierManager* SoldierManager::instance = nullptr;
SoldierManager* SoldierManager::getInstance() {
    if(SoldierManager::instance == nullptr){
        instance = new SoldierManager;
    }
    return instance;
}

//crea las nuevas listas de enemigos y aliados
void SoldierManager::newLists() {
    //borrar listas de enemigos y aliados
    int maxSize = maxEnemies/3;

    allyList = new LinkedList();
    enemyList = new LinkedList();

    if(!firstGeneration){

        int newGene1[4] = {0,0,0,0};
        int newGene2[4] = {0,0,0,0};
        int newGene3[4] = {0,0,0,0};
        generator->newBreed(mainGene1, mainGene2);
        for(int i = 0; i<4;i++){
            newGene3[i] = generator->newGenes[i];
        }
        generator->newBreed(mainGene1, mainGene3);
        for(int i = 0; i<4;i++){
            newGene2[i] = generator->newGenes[i];
        }
        generator->newBreed(mainGene3, mainGene2);
        for(int i = 0; i<4;i++){
            newGene1[i] = generator->newGenes[i];
        }
        for(int i = 0; i<4; i++){
            this->mainGene1[i] = newGene1[i];
            this->mainGene2[i] = newGene2[i];
            this->mainGene3[i] = newGene3[i];

        }
    }
    for(int i = 0; i<15; i++){
        allyList->insert(new Ally());
    }
    for(int i = 0; i < maxSize; i++){
        enemyList->insert(new Enemy(this->mainGene1));
        enemyList->insert(new Enemy(this->mainGene2));
        enemyList->insert(new Enemy(this->mainGene3));

    }
    enemyList->insert(new Enemy(mainGene2));
    enemyList->insert(new Enemy(mainGene1));
    this->firstGeneration = false;
}


//elimina los aliados muertos
void SoldierManager::removeDeadAlly(int allyID) {

    allyList->deleteNode(allyID);
}
//elimina los enemigos muertos
void SoldierManager::removeDeadEnemy(int enemyID) {
    enemyList->deleteNode(enemyID);
}

void SoldierManager::update() {

    if (doubleAttSpeed) {
        if (doubleAttSpeedCounter <= 0) {
            doubleAttSpeed = false;

            for (SoldierNode *n = allyList->head; n != nullptr; n = n->getNext()) {
                n->getSoldier()->attSpeed *= 2;
            }
        }
        doubleAttSpeedCounter--;

    }

    if(doubleAttack){
        if (doubleAttackCounter <= 0) {
            doubleAttack = false;

            for (SoldierNode *n = allyList->head; n != nullptr; n = n->getNext()) {
                n->getSoldier()->attack /= 2;
            }
        }
        doubleAttackCounter--;
    }
    seekAndDestroy();

}

void SoldierManager::setMaxEnemies(int max) {
    this->maxEnemies = max;
}

void SoldierManager::callReinforcements() {
    Ally* a1 = new Ally();
    Ally* a2 = new Ally();
    a1->i = 9;
    a2->i = 9;
    a1->j = 1;
    a2->j = 2;
    a1->posX = a1->i*100+18;
    a1->posY = a1->j*100+18;
    a2->posX = a1->i*100+18;
    a2->posY = a1->j*100+18;
    this->allyList->insert(a1);
    matriz[9][1]=1;
    matriz[9][2]=1;
    this->allyList->insert(a2);
}

void SoldierManager::kill(){
    SoldierNode* n1 = enemyList->head;
    matriz[n1->getSoldier()->i][n1->getSoldier()->j] = 0;
    matriz[n1->getNext()->getSoldier()->i][n1->getNext()->getSoldier()->j] = 0;
    enemyList->deleteNode(n1->getSoldier()->ID);
    enemyList->deleteNode(n1->getNext()->getSoldier()->ID);
}

void SoldierManager::setMatriz(int matriz[10][12]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<12; j++){
            this->matriz[i][j] = matriz[i][j];
        }
    }

}
void SoldierManager::seekAndDestroy() {
    for(SoldierNode* n = allyList->head;n != nullptr;n=n->getNext()){
        int i = n->getSoldier()->i;
        int j = n->getSoldier()->j;

            if (matriz[i][j-1]==2) {
                Soldier *enemy = enemyList->search(i, j - 1);
                n->getSoldier()->dealDamage(enemy);


            }else if (matriz[i+1][j]==2) {
                Soldier *enemy = enemyList->search(i + 1, j);
                n->getSoldier()->dealDamage(enemy);


            }else if (matriz[i][j+1]==2) {
                Soldier *enemy = enemyList->search(i, j + 1);
                n->getSoldier()->dealDamage(enemy);


            }else if (matriz[i-1][j]==2) {
                Soldier *enemy = enemyList->search(i - 1, j);
                n->getSoldier()->dealDamage(enemy);
            }

    }
    for(SoldierNode* n = enemyList->head;n != nullptr;n=n->getNext()){
        int i = n->getSoldier()->i;
        int j = n->getSoldier()->j;

            if (matriz[i][j-1]==1) {
                Soldier *ally = allyList->search(i, j - 1);
                n->getSoldier()->dealDamage(ally);
            }

           else if (matriz[i+1][j]==1) {
                Soldier *ally = allyList->search(i + 1, j);
                n->getSoldier()->dealDamage(ally);
            }

            else if (matriz[i][j+1]==1) {
                Soldier *ally = allyList->search(i, j + 1);
                n->getSoldier()->dealDamage(ally);
            }

           else if (matriz[i-1][j]==1) {
                Soldier *ally = allyList->search(i - 1, j);
                n->getSoldier()->dealDamage(ally);
            }

    }
    if(enemyList->size==4){
        for(int i = 0; i<4; i++){
            mainGene1[i] = {enemyList->head->getSoldier()->genes[i]};
            mainGene2[i] = {enemyList->head->getNext()->getSoldier()->genes[i]};
            mainGene3[i] = {enemyList->head->getNext()->getNext()->getSoldier()->genes[i]};

        }
        matriz[enemyList->head->getSoldier()->i][enemyList->head->getSoldier()->j]=0;
        enemyList->deleteNode(enemyList->head->getID());
        matriz[enemyList->head->getSoldier()->i][enemyList->head->getSoldier()->j]=0;
        enemyList->deleteNode(enemyList->head->getID());
        matriz[enemyList->head->getSoldier()->i][enemyList->head->getSoldier()->j]=0;
        enemyList->deleteNode(enemyList->head->getID());
    }
}
void SoldierManager ::setPos() {

    SoldierNode *n = allyList->head;
    SoldierNode *e = enemyList->head;

    for (int i = 0; i < 10; i++) {
//        cout<< i<<"gran iteracion"<<endl;
        for (int j = 0; j < 12; j++) {
//            cout<< j<<"iteracion"<<endl;
            if (matriz[i][j] == 1) {
                if (n != nullptr) {
                    n->getSoldier()->i = i;
                    n->getSoldier()->j = j;
                    n->getSoldier()->posX = (i * 100) + 18;
                    n->getSoldier()->posY = (j * 100) + 18;
                    n = n->getNext();
                }


//                cout<< n->getSoldier()->i<<endl;
//                cout<< n->getSoldier()->j<<endl;


            }else if (matriz[i][j] == 2) {
                    if (e != nullptr) {
                        e->getSoldier()->i = i;
                        e->getSoldier()->j = j;
                        e = e->getNext();
                    }
                }

            }
        }

}
void SoldierManager ::backTrackMove(int i, int j) {

    for(SoldierNode*n = allyList->head; n!= nullptr; n = n->getNext()) {
        int distanciaDelCentro = 0;
        bool position = false;

        if (matriz[i][j] == 0 || matriz[i][j] == 4)
        {
            n->getSoldier()->targetI = i;
            n->getSoldier()->targetJ = j;
            matriz [i][j] = 5;

        } else{
            distanciaDelCentro = 1;
            while (position == false){
                for (int a =  j - distanciaDelCentro; a <=  j + distanciaDelCentro && position == false; a++){
                    if ((i - distanciaDelCentro >= 0 && i < 10) && ( a >= 0 && a < 12)){
                        if (matriz [i - distanciaDelCentro][a] == 0){

                            n->getSoldier()->targetI = i - distanciaDelCentro;
                            n->getSoldier()->targetJ = a;
                            matriz [i - distanciaDelCentro][a] = 5;
                            position = true;
                        }
                    }
                }
                for(int a = i - distanciaDelCentro; a <= i +distanciaDelCentro && position == false; a++){
                    if ((a >= 0 && a < 10) && (j >= 0 && j + distanciaDelCentro < 12)){
                        if (matriz [a][j + distanciaDelCentro] == 0){
                            n->getSoldier()->targetI = a;
                            n->getSoldier()->targetJ = j + distanciaDelCentro;
                            matriz [a] [j + distanciaDelCentro] = 5;
                            position = true;
                        }
                    }
                }for (int a =  j - distanciaDelCentro; a <=  j + distanciaDelCentro && position == false; a++){
                    if (( i >= 0 && i + distanciaDelCentro < 10) && ( a >= 0 && a < 12)){
                        if (matriz [i + distanciaDelCentro][a] == 0){
                            n->getSoldier()->targetI = i + distanciaDelCentro;
                            n->getSoldier()->targetJ = a;
                            matriz [i + distanciaDelCentro][a] = 5;
                            position = true;
                        }
                    }
                }for(int a = i - distanciaDelCentro; a <= i +distanciaDelCentro && position == false; a++) {
                    if ((a >= 0 && a < 10) && (j - distanciaDelCentro >= 0 && j < 12)) {
                        if (matriz[a][j - distanciaDelCentro] == 0) {
                            n->getSoldier()->targetI = a;
                            n->getSoldier()->targetJ = j - distanciaDelCentro;
                            matriz[a][j - distanciaDelCentro] = 5;
                            position = true;
                        }
                    }
                }distanciaDelCentro ++;
            }

        }
    }
}
void SoldierManager ::setNewPos() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            if (matriz[i][j] == 1) {
                matriz[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {

            if (matriz[i][j] == 5) {
                matriz[i][j] = 1;
            }
        }
    }
}
void SoldierManager::printMatriz() {
    for(int i = 0; i<10;i++){
        for(int j = 0; j<12; j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
}



