//
//  Character.hpp
//  Side-Projects
//
//  Created by Alexander Mann on 2017-08-18.
//  Copyright © 2017 Alexander Mann. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string.h>
#include <iostream>

class Character {
private:
    std::string name;
    int health, punch, kick;
public:
    // constructors
    Character(std::string n);                           // name
    Character(std::string n, int h);                    // name, health
    Character(std::string n, int p, int k);             // name, punch, kick
    Character(std::string n, int p, int k , int h);     // all attributes
    // deconstructor
    ~Character();
    // for name
    std::string getName();
    void setName(std::string value);
    // for health
    int getHealth();
    void setHealth(int value);
    void getHit(int value);
    // for punch
    int getPunch();
    void setPunch(int value);
    // for kick
    int getKick();
    void setKick(int value);
    // for stats
    void showStats();                                   // user stats
    void showStats(int i);                              // opponent stats
};  // end of class Character
