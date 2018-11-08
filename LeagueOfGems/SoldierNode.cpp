//
// Created by jose on 21/09/18.
//

#include "SoldierNode.h"
#include "Soldier.h"
SoldierNode::SoldierNode(Soldier *soldier) {
    this->soldier = soldier;
}

Soldier* SoldierNode::getSoldier() {
    return soldier;
}
SoldierNode* SoldierNode::getNext() const{
    return next;
}
void SoldierNode::setNext(SoldierNode *next) {
    SoldierNode::next = next;
}

int SoldierNode::getID() const {
    return ID;
}

void SoldierNode::setID(int ID) {
    SoldierNode::ID = ID;
    SoldierNode::soldier->setID(ID);
}
