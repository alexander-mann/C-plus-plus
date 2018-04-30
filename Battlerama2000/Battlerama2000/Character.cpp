//
//  Character.cpp
//  Side-Projects
//
//  Created by Alexander Mann on 2017-08-18.
//  Copyright © 2017 Alexander Mann. All rights reserved.
//

#include "Character.hpp"

// CONSTRUCTORS

Character::Character(std::string n) {
    name = n;
    punch = 10;
    kick = 10;
    health = 50;
}

Character::Character(std::string n, int h) {
    name = n;
    punch = 10;
    kick = 10;
    health = h;
}

Character::Character(std::string n, int p, int k){
    name = n;
    punch = p;
    kick = k;
    health = 50;
}

Character::Character(std::string n, int p, int k , int h) {
    name = n;
    punch = p;
    kick = k;
    health = h;
}

Character::~Character() {
    name = '\0';
    punch = 0;
    kick = 0;
    health = 0;
}

// NAME GETTER AND SETTER

std::string Character::getName() {
    return name;
}

void Character::setName(std::string value) {
    name = '\0'; // clear name
    name = value;
}

// HEALTH GETTER AND SETTER

int Character::getHealth() {
    return health;
}

void Character::setHealth(int value) {
    health = value;
}

void Character::getHit(int value) {
    health = health - value;
}

// PUNCH GETTER AND SETTER

int Character::getPunch() {
    return punch;
}

void Character::setPunch(int value) {
    punch = value;
}

// KICK GETTER AND SETTER

int Character::getKick() {
    return kick;
}

void Character::setKick(int value) {
    kick = value;
}

// SHOW STATISTICS
void Character::showStats() {
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+         YOUR STATS         +" << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+ NAME   : " << this->getName() << std::endl;
    std::cout << "+ HEALTH : " << this->getHealth() << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+          ATTACKS           +" << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+ PUNCH  : " << this->getPunch() << std::endl;
    std::cout << "+ KICK   : " << this->getKick() << std::endl;
    std::cout << "+----------------------------+" << std::endl;
}

void Character::showStats(int i) {
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+        OPPONENT " << i << "          +" << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+ NAME   : " << this->getName() << std::endl;
    std::cout << "+ HEALTH : " << this->getHealth() << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+          ATTACKS           +" << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+ PUNCH  : " << this->getPunch() << std::endl;
    std::cout << "+ KICK   : " << this->getKick() << std::endl;
    std::cout << "+----------------------------+" << std::endl;
}
