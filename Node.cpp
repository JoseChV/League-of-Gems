//
// Created by jose on 21/09/18.
//

#include "Node.h"
#include "Soldier.h"
Node::Node(Soldier *soldier) {
    this->soldier = soldier;
}

Soldier* Node::getSoldier() {
    return soldier;
}
Node* Node::getNext() const{
    return next;
}
void Node::setNext(Node *next) {
    Node::next = next;
}

int Node::getID() const {
    return ID;
}

void Node::setID(int ID) {
    Node::ID = ID;
    Node::soldier->setID(ID);
}
