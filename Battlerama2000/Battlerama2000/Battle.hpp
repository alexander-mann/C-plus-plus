//
//  Battle.hpp
//  Side-Projects
//
//  Created by Alexander Mann on 2017-08-18.
//  Copyright © 2017 Alexander Mann. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Character.hpp"

class Battle {
private:
    // no attributes
public:
    int round(Character &User, Character &Enemy, int num); // template for rounds
    void userAttack(Character &User, Character &Enemy); // user attack round
    void enemyAttack(Character &Enemy, Character &User, int num); // opponent attack round
    int fight(Character &User, Character &Enemy, int num); // full battle sequence
    void pause(); // force user to hit enter
    void intro(int num); // round intro
}; // end of class Battle

