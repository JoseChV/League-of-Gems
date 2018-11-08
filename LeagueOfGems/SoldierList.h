//
// Created by jose on 17/09/18.
//

#ifndef MPOINTER_LINKEDLIST_H
#define MPOINTER_LINKEDLIST_H


#include <iostream>
#include "SoldierNode.h"

class LinkedList {
private:
    int ID;
public:
    int size;
    SoldierNode *head = nullptr;

    ///inserta un nodo al final de la lista
    void insert(Soldier* soldier);
    ///imprime la lista
    void print();
    ///borra un nodo de la lista segun su ID
    void deleteNode(int ID);

    Soldier* search(int i, int j);
};


#endif //MPOINTER_LINKEDLIST_H
