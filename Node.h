//
// Created by jose on 21/09/18.
//

#ifndef MPOINTER_NODE_H
#define MPOINTER_NODE_H


#include "Soldier.h"

class Node {
private:
    Soldier* soldier;
    int ID;
    Node *next = nullptr;
public:

    Node(Soldier* soldier);

    Soldier* getSoldier();

    int getID() const;

    void setID(int ID);

    Node* getNext() const;

    void setNext(Node *next);
};


#endif //MPOINTER_NODE_H
