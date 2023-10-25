/*********************************************************************
** Program Filename: TA.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: holds information about a TA in the maze and how it
   should move.
** Input: calls for the TA to move.
** Output: the move of the TA is returned.
*********************************************************************/

#include <iostream>
#include "TA.h"
#include "mazePerson.h"

using namespace std;

/*********************************************************************
** Function: TA::TA()
** Description: sets the initial values for the TA object.
** Parameters: none
** Pre-Conditions: a TA object is being created.
** Post-Conditions: the initial values for the TA object are set.
*********************************************************************/
TA::TA(){
    this->num_TA = 1;
    this->has_moved = false;
}

/*********************************************************************
** Function: char TA::get_move()
** Description: collects the move command for the TA based on random
   selection.
** Parameters: none
** Pre-Conditions: the TA needs to move.
** Post-Conditions: a random move command is returned.
*********************************************************************/ 
char TA::get_move(){
    int random = rand() % 4;
    if(random == 0){
        return 'w';
    }
    else if(random == 1){
        return 's';
    }
    else if(random == 2){
        return 'a';
    }
    else if(random == 3){
        return 'd';
    }
}

/*********************************************************************
** Function: bool TA::get_has_moved() const
** Description: returns the value to determine if the TA has moved or
   not.
** Parameters: none
*********************************************************************/ 
bool TA::get_has_moved() const{
    return this->has_moved;
}

/*********************************************************************
** Function: void TA::set_has_moved(const bool value)
** Description: sets the value to determine if the TA has moved or not.
** Parameters: new value
*********************************************************************/ 
void TA::set_has_moved(const bool value){
    this->has_moved = value;
}

/*********************************************************************
** Function: TA::~TA()
** Description: destroys the TA object
** Parameters: none
** Pre-Conditions: the people vector is being deleted.
** Post-Conditions: the TA object is deleted.
*********************************************************************/ 
TA::~TA(){}