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
    unsigned int currTurn   = 0; //THE CURRENT NUMBER OF TURNS THE PLAYER IS ON
    
    //EXPLAIN RULES
    char input;
    cout << "Welcome to the game of Pig Dice!\n" <<
            "To play the game, you roll a die as many times as you'd like to try and reach " << WIN_CON << " points in a minimum amount of turns.\n" <<
            "The catch is, if you roll a " << BAD_NUM << " you will lose all your points, and must start again.\n" <<
            "You may end your turn at any time to save the number of points you have, and try to minimize the amount of turns until " << WIN_CON << " points.\n" <<
            "Type '1' to start the game, or type '3' to exit the program.\n";
    
    //CAPTURE USER INPUT & START THE GAME IF REQUESTED
    cin >> input;
    if(input != '1'){
        cout << "Exiting game...\n";
        exit(0);
    }
    
    //START THE GAME
    cout << "\nSTARTING GAME\n\n";
    
    char roll;
    while(points < WIN_CON){
        //cout << "TURN: " << currTurn << '\n';
        cout << "Roll the die by inputting 'R', or input anything else to stop your turn.\n";
        cin >> roll;
        
        if(roll == 'R'){
            //WHILE LOOP WILL CONTINUE IF THE INPUT WAS 'R'
            currRolled = rand()%DIE_SIDES+1;
            cout << "You rolled a " << currRolled << '\n';

            if(currRolled == 1){
                points = 0;
                cout << "You have lost all your points. You are currently on turn: " << currTurn++;
            }else{
                points += currRolled;
                cout << "Your current amount of points are: " << points << '\n';
            }
        }else{
            cout << "You have chosen to end your turn. It is currently turn " << currTurn++ <<
                    "\nYou have " << points << " amount of points.\n\n";
        }
    }
    
    return 0;
}

