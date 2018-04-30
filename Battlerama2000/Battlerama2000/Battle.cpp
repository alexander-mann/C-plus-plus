//
//  Battle.cpp
//  Side-Projects
//
//  Created by Alexander Mann on 2017-08-18.
//  Copyright © 2017 Alexander Mann. All rights reserved.
//

#include "Battle.hpp"

// ROUND INTRO

int Battle::round(Character &User , Character &Enemy, int num) {
    int result = 0; // set to 'unknown'
    if(User.getHealth() <= 0 || Enemy.getHealth() <= 0 || num > 3) {
        std::cout << "+----------------------------+" << std::endl;
        std::cout << "+        FIGHT OVER!         +" << std::endl;
        std::cout << "+----------------------------+" << std::endl;
        std::cout << "+        FINAL STATS:        +" << std::endl;
        std::cout << "+----------------------------+" << std::endl;
        std::cout << "+ " << User.getName() << " = " << User.getHealth() << " health" << std::endl;
        std::cout << "+ " << Enemy.getName() << " = " << Enemy.getHealth() << " health" << std::endl;
        std::cout << "+----------------------------+" << std::endl;
        std::cout << "+ THE WINNER IS ";
        if(User.getHealth() > Enemy.getHealth()) {
            result = 1; // set to 'won'
            std::cout << User.getName() << "!" << std::endl;
        } else {
            std::cout << Enemy.getName() << "!" << std::endl;
            result = -1; // set to 'lost'
        }
        std::cout << "+----------------------------+" << std::endl;
    } else {
        std::cout << "+----------------------------+" << std::endl;
        std::cout << "+         ROUND   " << num << "          +" << std::endl;
        std::cout << "+----------------------------+" << std::endl;
        std::cout << "+     CHOOSE YOUR MOVE!      +" << std::endl;
        std::cout << "+----------------------------+" << std::endl;
        std::cout << "+ Enter PUNCH (" << User.getPunch() << ")"<< std::endl;
        std::cout << "+ Enter KICK (" << User.getKick() << ")"<< std::endl;
        std::cout << "+----------------------------+" << std::endl;
    }
    return result;
}

// USER BATTLE SEQUENCE

void Battle::userAttack(Character &User, Character &Enemy) {
    std::string input;                                              // hold input
    int die;                                                        // to roll
    while(input != "PUNCH" && input != "KICK") {
        std::cout << "+::::::::: ";
        std::cin >> input;
        std::cout << "+----------------------------+" << std::endl;
        if(input == "PUNCH") {
            die = 1+(rand()%6);                                     // roll 6-sided die
            if(die % 2 == 0) {                                      // check if it is even
                Enemy.getHit(User.getPunch());                      // do damage to opponent
                std::cout << " You punched him! " << User.getPunch() << " damage!" << std::endl;
            } else {
                std::cout << " Oh no, your punch missed!" << std::endl;
            }
        } else if(input == "KICK") {
            die = 1+(rand()%6);                                     // roll 6-sided die
            if(die % 2 == 0) {                                      // check if it is even
                Enemy.getHit(User.getKick());                       // do damage to opponent
                std::cout << " What a kick! " << User.getKick() << " damage!" << std::endl;
            } else {
                std::cout << " Oh no, your kick missed!" << std::endl;
            }
        } else {
            std::cout << " Try again!" << std::endl;
            std::cout << "+----------------------------+" << std::endl;
        }
    }  // end of while
    std::cout << "+----------------------------+" << std::endl;
}

// OPPONENT BATTLE SEQUENCE

void Battle::enemyAttack(Character &Enemy, Character &User, int num) {
    int choice, die;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+         ROUND   " << num << "          +" << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+      OPPONENTS MOVE!       +" << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+ PUNCH (" << Enemy.getPunch() << ")"<< std::endl;
    std::cout << "+ KICK (" << Enemy.getKick() << ")"<< std::endl;
    std::cout << "+----------------------------+" << std::endl;
    
    // INSERT PAUSE - PRESS ENTER //
    
    choice = 1+(rand()%2);              // flip a coin
    if(choice % 2 == 0) {               // check if it is even
        die = 1+(rand()%6);             // roll 6-sided die
        if(die % 2 == 0) {
            User.getHit(Enemy.getPunch());
            std::cout << "Ouch, you just got punched!" << std::endl;
            std::cout << "-> " << Enemy.getPunch() << " damage!" << std::endl;
        } else {
            std::cout << "Swing and a miss!" << std::endl;
        }
    } else {
        die = 1+(rand()%6);             // roll 6-sided die
        if(die % 2 == 0) {
            User.getHit(Enemy.getKick());
            std::cout << "Ouch, you just got kicked!" << std::endl;
            std::cout << "-> " << Enemy.getKick() << " damage!" << std::endl;
        } else {
            std::cout << "He missed the kick!" << std::endl;
        }
    }
    std::cout << "+----------------------------+" << std::endl;
}

// FULL BATTLE

int Battle::fight(Character &User, Character &Enemy, int num) {
    int result;
    // INTRO
    std::cout << std::endl;
    User.showStats();                                   // show user's stats
    pause();
    std::cout << std::endl;
    intro(num);                                         // show intro slide
    pause();
    std::cout << std::endl;
    Enemy.showStats(num);                               // show opponent's stats
    pause();
    
    // ROUND ONE
    std::cout << std::endl;
    result = this->round(User, Enemy, 1);               // start round one
    // User Attack Phase
    this->userAttack(User, Enemy);                      // user attack phase
    pause();
    if(Enemy.getHealth() <= 0) {                        // check health levels
        result = 1;                                     // set result to 'won'
    }else {
        // Opponent Attack Phase
        std::cout << std::endl;
        this->enemyAttack(Enemy, User, 1);                  // enemy attack phase
        pause();
        if(User.getHealth() <= 0) {                         // check health levels
            result = -1;                                    // set result to 'lost'
        }
    }
    
    // ROUND TWO
    if(result == 0) {                                       // check if battle is over
        std::cout << std::endl;
        result = this->round(User, Enemy, 2);               // start round two - check health levels
        // User Attack Phase
        this->userAttack(User, Enemy);
        pause();
        if(Enemy.getHealth() <= 0) {                        // check health levels
            result = 1;                                     // set result to 'won'
        }
        // Opponent Attack Phase
        std::cout << std::endl;
        this->enemyAttack(Enemy, User, 2);
        pause();
        if(User.getHealth() <= 0) {                         // check health levels
            result = -1;                                    // set result to 'lost'
        }
    }
    
    // FINAL ROUND
    if(result == 0) {                                       // check if battle is over
        std::cout << std::endl;
        result = this->round(User, Enemy, 3);               // start round three - check health levels
        // User Attack Phase
        this->userAttack(User, Enemy);
        pause();
        if(Enemy.getHealth() <= 0) {                        // check health levels
            result = 1;                                     // set result to 'won'
        }
        // Opponent Attack Phase
        std::cout << std::endl;
        this->enemyAttack(Enemy, User, 3);
        pause();
    }
    
    // End Battle (after three rounds)
    std::cout << std::endl;
    result = this->round(User, Enemy, 4);                   // 4 will trigger end sequence
    pause();
    std::cout << std::endl;
    
    return result;
}

// PAUSE FUNCTION

void Battle::pause() {
    std::cin.clear();                                   // clear buffer
    std::cout << std::endl;
    std::cout << "Press Enter to Continue...";
    std::cin.ignore(10,'\n');
    std::cin.get();
}

// BATTLE INTRO

void Battle::intro(int num) {
    std::cout << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    if(num == 1) {
        std::cout << "+        FIRST BATTLE        +" << std::endl;
    }else if(num == 2) {
        std::cout << "+       SECOND BATTLE        +" << std::endl;
    }else if(num == 3) {
        std::cout << "+        FINAL BATTLE        +" << std::endl;
    }
    std::cout << "+-------------+--------------+" << std::endl;
    std::cout << "+------------+++-------------+" << std::endl;
    std::cout << "+-------------+--------------+" << std::endl;
}
