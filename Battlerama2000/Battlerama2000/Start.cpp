//
//  Start.cpp
//  Side-Projects
//
//  Created by Alexander Mann on 2017-08-18.
//  Copyright © 2017 Alexander Mann. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "Character.hpp"
#include "Battle.hpp"

using namespace std;

// PAUSE FUNCTION
void pause() {
    cin.clear(); // clear buffer
    cout << endl;
    cout << "Press Enter to Continue...";
    cin.ignore(10,'\n');
    cin.get();
}

// MAIN PROGRAM
int main(int argc, char* argv[]) {
    
    // Local Variables
    string name;
    
    // Start Screen
    cout << "+----------------------------+" << endl;
    cout << "+      BATTLERAMA  2000      +" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+ Created By: Alexander Mann +" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+------------+++-------------+" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+      - Enter A Name -      +" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+::::::::: ";
    cin >> name;
    Character User(name); // initialize user character
    
    // Intro Screen
    cout << endl;
    cout << "+----------------------------+" << endl;
    cout << "+ Welcome " << User.getName() << "," << endl;
    cout << "+ I hope that you are ready" << endl;
    cout << "+ for the quest that awaits!" << endl;
    cout << "+----------------------------+" << endl;
    pause();
    
    // Battle
    int result = 0;
    Battle Battle; // initialize battle
    Character First("Ragnar", 10); // initialize first opponent
    result = Battle.fight(User, First, 1); // first fight
    if(result == 1) { // if opponent is beaten
        Character Second("Lagarth", 20); // initialize second opponent
        result = Battle.fight(User, Second, 2); // second fight
    }
    if(result == 1) { // if opponent is beaten
        Character Third("Mathdu", 30); // initialize third opponent
        result = Battle.fight(User, Third, 3); // third fight
    }
    if(result == 1) { // if you beat the game
        cout << "+----------------------------+" << endl;
        cout << "+----------------------------+" << endl;
        cout << "+----------------------------+" << endl;
        cout << "+ " << User.getName() << " has beaten the game!" << endl;
        cout << "+ A truly great warrior." << endl;
        cout << "+----------------------------+" << endl;
        cout << "+----------------------------+" << endl;
        cout << "+----------------------------+" << endl;
    }
    
    return 0;
}
