//
// Created by jose on 17/09/18.
//

#include "LinkedList.h"
void LinkedList::insert(Soldier* soldier) {
    Node *temp = new Node(soldier);

    temp->setID(ID);
    this->ID ++;
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
            std::cout << temp->getSoldier()->attack << std::endl;
            temp = temp->getNext();
        }
        std::cout << temp->getSoldier()->attack << std::endl;
    }
}
void LinkedList::deleteNode(int ID)  {
    Node *actual = this->head;
    std::cout<<"ID: "<<actual->getID()<<std::endl;
    if(actual != nullptr){
        if(actual->getID()==ID){
            std::cout<<"deleted node :"<<ID<<std::endl;
            this->head = actual->getNext();
            std::cout<<"next: "<<this->head<<std::endl;
        }else{
            std::cout<<"false"<<std::endl;
            while (actual->getNext() != nullptr) {
                if(actual->getNext()->getID() == ID){
                    std::cout<<"deleted node :"<<ID<<std::endl;
                    actual->setNext(actual->getNext()->getNext());

                }
                actual = actual->getNext();
            }
        }
    }

}