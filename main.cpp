#include <iostream>
#include "Enemy.h"
#include "Ally.h"
#include "GeneGenerator.h"
#include "LinkedList.h"
#include "SoldierManager.h"

using namespace std;
int main() {
    SoldierManager* s= new SoldierManager();
    s->setMaxEnemies(35);
    s->newLists();
    s->enemyList->print();
    s->removeDeadEnemy(20);
    cout<<"ahora aliados"<<endl;
    s->enemyList->print();

}