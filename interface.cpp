/*********************************************************************
** Program Filename: interface.cpp
** Author: Anthony Silva
** Date: 03-06-2022
** Description: driver file for the entire Escape From CS 162 game.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

/*********************************************************************
** Function: void run_game(int &playAgain)
** Description: creates the game object and runs it.
** Parameters: reference to the value that determines if the user wants
   to play again.
*********************************************************************/ 
void run_game(int &playAgain){
    Game EscapeFromCS162;
    EscapeFromCS162.set_up();
    EscapeFromCS162.play_game();
    playAgain = EscapeFromCS162.check_to_play_again();
}

int main(){
    srand(time(0));
    int playAgain = 1;
    while(playAgain == 1){
        run_game(playAgain);
    }
    return 0;
}