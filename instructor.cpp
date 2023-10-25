/*********************************************************************
** Program Filename: instructor.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: holds information about the instructor in the maze and how
   it should move.
** Input: calls for the instructor to move.
** Output: the move of the instructor is returned.
*********************************************************************/

#include <iostream>
#include "instructor.h"
#include "mazePerson.h"

using namespace std;

/*********************************************************************
** Function: Instructor::Instructor()
** Description: sets the number of instructors on a space.
** Parameters: none
** Pre-Conditions: a new Instructor object is being created.
** Post-Conditions: the number of instructors on a space is set.
*********************************************************************/ 
Instructor::Instructor(){
    this->num_instructor = this->num_instructor + 1;
}

/*********************************************************************
** Function: char Instructor::get_move()
** Description: returns nothing, as the instructor does not move.
** Parameters: none
*********************************************************************/ 
char Instructor::get_move(){
    return ' ';
}

/*********************************************************************
** Function: Instructor::~Instructor()
** Description: destroys the Instructor object
** Parameters: none
** Pre-Conditions: the people vector is being deleted.
** Post-Conditions: the Instructor object is deleted.
*********************************************************************/ 
Instructor::~Instructor(){}