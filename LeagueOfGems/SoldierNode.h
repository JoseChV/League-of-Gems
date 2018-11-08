//
// Created by jose on 21/09/18.
//

#ifndef MPOINTER_NODE_H
#define MPOINTER_NODE_H


#include "Soldier.h"

class SoldierNode {
private:
    Soldier* soldier;
    int ID;
    SoldierNode *next = nullptr;
public:

    SoldierNode(Soldier* soldier);

    Soldier* getSoldier();

    int getID() const;

    void setID(int ID);

    SoldierNode* getNext() const;

    void setNext(SoldierNode *next);
};


#endif //MPOINTER_NODE_H
