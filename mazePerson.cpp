/*********************************************************************
** Program Filename: mazePerson.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: holds base information about what a person in the maze
   has.
** Input: calls to information about a person in the maze.
** Output: information about a general person in the maze is returned.
*********************************************************************/

#include <iostream>
#include "mazePerson.h"

using namespace std;

/*********************************************************************
** Function: MazePerson::MazePerson()
** Description: sets the initial values of the MazePerson object.
** Parameters: none
** Pre-Conditions: a MazePerson object is being created.
** Post-Conditions: the initial information about a person is set.
*********************************************************************/ 
MazePerson::MazePerson(){
    this->num_student = 0;
    this->num_TA = 0;
    this->num_instructor = 0;
}

/*********************************************************************
** Function: int MazePerson::get_num_student() const
** Description: returns the number of students on a space.
** Parameters: none
*********************************************************************/ 
int MazePerson::get_num_student() const{
    return this->num_student;
}

/*********************************************************************
** Function: char MazePerson::get_move()
** Description: returns the move of a general MazePerson.
** Parameters: none
*********************************************************************/ 
char MazePerson::get_move(){
    return '0';
}

/*********************************************************************
** Function: void MazePerson::set_num_TA(const int value)
** Description: sets the number of TAs on a space.
** Parameters: new number of TAs
*********************************************************************/ 
void MazePerson::set_num_TA(const int value){
    this->num_TA = value;
}

/*********************************************************************
** Function: int MazePerson::get_num_TA() const
** Description: returns the number of TAs on a space.
** Parameters: none
*********************************************************************/ 
int MazePerson::get_num_TA() const{
    return this->num_TA;
}

/*********************************************************************
** Function: bool MazePerson::get_has_moved() const
** Description: undefined function for general MazePerson.
** Parameters: none
*********************************************************************/ 
bool MazePerson::get_has_moved() const{}

/*********************************************************************
** Function: void MazePerson::set_has_moved(const bool value)
** Description: undefined function for general MazePerson.
** Parameters: new value
*********************************************************************/ 
void MazePerson::set_has_moved(const bool value){}

/*********************************************************************
** Function: MazePerson::~MazePerson()
** Description: destroys the MazePerson object.
** Parameters: none
** Pre-Conditions: the people vector is being deleted.
** Post-Conditions: the MazePerson object is deleted.
*********************************************************************/ 
MazePerson::~MazePerson(){}