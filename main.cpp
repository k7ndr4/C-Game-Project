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
#include <string>

using namespace std;

int main(int argc, char** argv) {
    srand(time(0));
    
    //DIFFICULTY POINTS
    const int WIN_CON_EASY = 65; //NUM OF POINTS TO WIN THE GAME (easy)
    const int WIN_CON_MED  = 100; //NUM OF POINTS TO WIN THE GAME (medium)
    const int WIN_CON_HARD = 150; //NUM OF POINTS TO WIN THE GAME (hard)
    const int BAD_NUM   = 1; //THE SIDE OF THE DIE THAT WILL RESULT IN ENDING YOUR TURN
    const int DIE_SIDES = 6; //AMOUNT OF SIDES ON THE DIE
    unsigned int points = 0; //AMOUNT OF CURRENT POINTS
    unsigned int currRolled = 0; //THE CURRENT SIDE OF THE DIE THAT HAS BEEN ROLLED 'i.e: 5'
    unsigned int currTurn   = 1; //THE CURRENT NUMBER OF TURNS THE PLAYER IS ON
    
    //EXPLAIN RULES
    char input;
    cout << "Welcome to the game of Pig Dice!\n" <<
            "To play the game, you roll a die as many times as you'd like to try and reach \n" << 
            "EASY: " << WIN_CON_EASY << " points\n MEDIUM: " << WIN_CON_MED << " points\n HARD: " << WIN_CON_HARD << " points\n in a minimum amount of turns.\n" <<
            "The catch is, if you roll a " << BAD_NUM << " you will lose all your points, and must start again.\n" <<
            "You may end your turn at any time to save the number of points you have, and try to minimize the amount of turns until you reach the desired amount of points.\n" <<
            "Type '1' to start the game, or type '3' to exit the program.\n";
    
    //CAPTURE USER INPUT & START THE GAME IF REQUESTED
    cin >> input;
    if(input != '1'){
        cout << "Exiting game...\n";
        exit(0);
    }
    
    //CHOOSE DIFFICULTY
    char difficulty;
    string diffStr;
    int currWinCon;
    cout << "Please choose your difficulty...\n" <<
            "Enter 'E' for Easy (" << WIN_CON_EASY << " points)" <<
            "Enter 'M' for Medium (" << WIN_CON_MED << " points)" <<
            "Enter 'H' for Hard (" << WIN_CON_HARD << " points)";
    
    switch(difficulty){
        case 'E': 
            currWinCon = WIN_CON_EASY;
            diffStr = "EASY";
            break;
        
        case 'M': 
            currWinCon = WIN_CON_MED;
            diffStr = "MEDIUM";
            break;
            
        case 'H': 
            currWinCon = WIN_CON_HARD;
            diffStr = "HARD";
            break;
            
        default : 
            currWinCon = WIN_CON_EASY;
            diffStr = "EASY";
            break;
    }
    //START THE GAME
    cout << "\nSTARTING GAME\n\n";
    
    char roll;
    while(points < currWinCon){
        cout << "Roll the die by inputting 'R', or input anything else to stop your turn.\n";
        cin >> roll;
        
        if(roll == 'R'){
            //WHILE LOOP WILL CONTINUE IF THE INPUT WAS 'R'
            currRolled = rand()%DIE_SIDES+1;
            cout << "You rolled a " << currRolled << '\n';

            if(currRolled == 1){
                points = 0;
                cout << "You have lost all your points. You are currently on turn: " << currTurn++ << '\n';
                cout << "\nTURN: " << currTurn << '\n';
            }else{
                points += currRolled;
                cout << "Your current amount of points are: " << points << '\n';
            }
        }else{
            cout << "You have chosen to end your turn. It is currently turn " << currTurn++ <<
                    "\nYou have " << points << " amount of points.\n\n";
        }
    }
    
    //ENSURE THAT THE WHILE LOOP BROKE BECAUSE PLAYER REACHED WIN CONDITION
    if(points >= currWinCon){
        cout << "Congratulations! You have beat the game on " << diffStr << " difficulty, in " << currTurn << " amount of turns!\n";
    }
    
    return 0;
}

