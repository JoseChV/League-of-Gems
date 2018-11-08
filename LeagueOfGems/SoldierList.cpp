//
// Created by jose on 17/09/18.
//

#include "SoldierList.h"
void LinkedList::insert(Soldier* soldier) {
    SoldierNode *temp = new SoldierNode(soldier);
    size++;
    temp->setID(ID);
    this->ID ++;
    if(head == nullptr){
        this->head = temp;
    }else{
        SoldierNode *actual = this->head;
        while(actual->getNext() != nullptr){
            actual = actual->getNext();
        }
        actual->setNext(temp);
    }
}
void LinkedList::print() {
    SoldierNode *temp = this->head;
    std::cout<<"printing"<<std::endl;
    if(head== nullptr){
        std::cout<<"empty list"<<std::endl;
    }else {
        while (temp->getNext() != nullptr) {
            std::cout << temp->getSoldier()->hp << std::endl;
            temp = temp->getNext();
        }
        std::cout << temp->getSoldier()->hp << std::endl;
    }
}
void LinkedList::deleteNode(int ID)  {
    SoldierNode *actual = this->head;
    size--;
    if(actual != nullptr){
        if(actual->getID()==ID){
            this->head = actual->getNext();
        }else{
            while (actual->getNext() != nullptr) {
                if(actual->getNext()->getID() == ID){
                    actual->setNext(actual->getNext()->getNext());

                }
                actual = actual->getNext();
            }
        }
    }
}
Soldier* LinkedList::search(int i, int j) {
    for(SoldierNode*n = head; n!= nullptr; n = n->getNext()) {
        if(n->getSoldier()->i == i && n->getSoldier()->j == j){
            return n->getSoldier();
        }
    }
    return nullptr;
}