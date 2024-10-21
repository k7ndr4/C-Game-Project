/* 
 * File:   main.cpp
 * Author: Kendra
 *
 * Created on October 21, 2024, 3:16 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    srand(time(0));
    
    const int WIN_CON   = 100; //NUM OF POINTS TO WIN THE GAME
    const int BAD_NUM   = 1; //THE SIDE OF THE DIE THAT WILL RESULT IN ENDING YOUR TURN
    const int DIE_SIDES = 6; //AMOUNT OF SIDES ON THE DIE
    unsigned int points = 0; //AMOUNT OF CURRENT POINTS
    unsigned int currRolled = 0; //THE CURRENT SIDE OF THE DIE THAT HAS BEEN ROLLED 'i.e: 5'
    
    //EXPLAIN RULES
    char input;
    while(input != '3'){
        cout << "Welcome to the game of Pig Dice!\n" <<
                "To play the game, you roll a die as many times as you'd like to try and reach " << WIN_CON << " points in a minimum amount of turns.\n" <<
                "The catch is, if you roll a " << BAD_NUM << " you will lose all your points, and must start again.\n" <<
                "Type '1' to start the game, or type '3' to exit the program.\n";
        
        cin >> input;
    }
    
    
    
    return 0;
}

