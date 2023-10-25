/*********************************************************************
** Program Filename: game.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: Runs the entire CS 162 game.
** Input: The side length of the maze is determined by the user. The
   side length must be five or greater. Then the game is played from there
   with four walls, one intrepid student, one instructor, three TAs, and
   six programming skills.
** Output: The game ends whenever the player gets caught by a TA (with no
   programming skills demonstrated) or the student reaches the instructor.
   The player is given the chance to play again.
*********************************************************************/

#include <iostream>
#include <string>
#include "game.h"
#include "maze.h"

using namespace std;

/*********************************************************************
** Function: bool Game::check_side(string width)
** Description: checks to see if the side length input for the square
   grid of the maze is an integer.
** Parameters: the input of side length determined by the user.
** Pre-Conditions: the user plugs in input to be checked.
** Post-Conditions: the function returns false if the input is not a
   positive integer or is null, and returns true if otherwise.
*********************************************************************/ 
bool Game::check_side(string width){
    // checks if the input is not null.
    if(width.size() != 0){
        // checks every element of the input string.
        for(int i = 0; i < width.length(); i++){
            // the input may be valid if every element of the string is a number.
            if(!isdigit(width[i])){
                cout << "Invalid input. Please try again." << endl;
                return false;
            }
        }
        return true;
    }
    else{
        cout << "Invalid input. Please try again." << endl;
        return false;
    }
}

/*********************************************************************
** Function: int Game::get_side()
** Description: collects the side length of the grid from the user. The
   program may repeat itself an invalid input is given.
** Parameters: none
** Pre-Conditions: the program is able to successfully start up.
** Post-Conditions: the program repeats itself until the input given is
   any integer greater than 5.
*********************************************************************/ 
int Game::get_side(){
    string width;
    while(true){
        cout << "Enter the side length of your maze (must be five or greater): ";
        getline(cin, width);
        if(check_side(width)){
            int w = stoi(width);
            if(w >= 5){
                return w;
            }
            else{
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }
}

/*********************************************************************
** Function: void Game::set_up()
** Description: sets up the game by collecting the side length from the
   user, and using it to create the maze vector.
** Parameters: none
** Pre-Conditions: the game is ready to be started up.
** Post-Conditions: the game is set up and ready to play.
*********************************************************************/ 
void Game::set_up(){
    int side = get_side();
    m.create_maze_vector(side);
    m.set_walls();
    m.set_student_initial();
    m.set_TA_initial();
    m.set_instructor();
    m.set_skills();
}

/*********************************************************************
** Function: void Game::play_game()
** Description: plays the complete game
** Parameters: none
** Pre-Conditions: the maze vector is completely set up.
** Post-Conditions: the function keeps running until a valid condition
   is met for the game to end.
*********************************************************************/ 
void Game::play_game(){
    bool clear = true;
    int acquired_skills = 0;
    int appeasement_level = 0;
    m.create_people_vector();
    // keeps repeating until a certain condition is met for the game to end
    while(clear == true){
        m.print_grid();
        m.check_for_skill(acquired_skills);
        // the game ends if the student is caught by the TA
        if(m.caught_by_TA(appeasement_level)){
            clear = false;
        }
        // the game ends if the student has reached a square adjacent to the instructor
        else if(m.reached_instructor(acquired_skills)){
            clear = false;
        }
        else{
            m.play_move(acquired_skills, appeasement_level);
        }
    }
}

/*********************************************************************
** Function: int Game::check_to_play_again()
** Description: checks if the user wants to play again, and if not,
   terminates the program.
** Parameters: None
** Pre-Conditions: the game is finished.
** Post-Conditions: the game repeats if the user wants to play again, and
   terminates if otherwise. The function may repeat itself for the case of
   invalid input from the user.
*********************************************************************/ 
int Game::check_to_play_again(){
    string play_again;
    // keeps repeating until a valid input is given.
    while(true){
        cout << "Do you want to play again? (1-yes, 0-no)" << endl;
        getline(cin, play_again);
        if(play_again == "1"){
            return 1;
        }   
        else if(play_again == "0"){
            return 0;
        }
        else{
            cout << "Invalid input. Please try again." << endl;
        }
    }
}