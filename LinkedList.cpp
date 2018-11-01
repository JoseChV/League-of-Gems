//
// Created by jose on 17/09/18.
//

#include "LinkedList.h"
void LinkedList::insert(Soldier* soldier) {
    Node *temp = new Node(soldier);
    this->ID ++;
    temp->setID(ID);
    if(head == nullptr){
        this->head = temp;
    }else{
        Node *actual = this->head;
        while(actual->getNext() != nullptr){
            actual = actual->getNext();
        }
        actual->setNext(temp);
    }
}
void LinkedList::print() {
    Node *temp = this->head;
    std::cout<<"printing"<<std::endl;
    if(head== nullptr){
        std::cout<<"empty list"<<std::endl;
    }else {
        while (temp->getNext() != nullptr) {
            std::cout << temp->getSoldier()->ID << std::endl;
            temp = temp->getNext();
        }
        std::cout << temp->getSoldier()->ID << std::endl;
    }
}
void LinkedList::deleteNode(int ID)  {
    Node *actual = this->head;
    if(actual->getID()==ID){
        this->head = actual->getNext();
    }else{
        while (actual->getNext()->getID() != ID) {
            actual = actual->getNext();
        }
        actual->setNext(actual->getNext()->getNext());
    }
}