/*********************************************************************
** Program Filename: wall.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: holds information about what a wall space holds, which
   is very straightforward, as the space is inaccessible.
** Input: calls to what the function holds.
** Output: information that every wall space should have.
*********************************************************************/

#include <iostream>
#include "wall.h"

using namespace std;

/*********************************************************************
** Function: Wall::Wall()
** Description: sets the character that determines if a wall is in place.
** Parameters: none
** Pre-Conditions: a new wall object is being created.
** Post-Conditions: the space is occupied by a wall.
*********************************************************************/ 
Wall::Wall(){
    this->wall_char = '#';
}

/*********************************************************************
** Function: void Wall::set_has_student(const bool value)
** Description: undefined function for wall
** Parameters: new value
*********************************************************************/ 
void Wall::set_has_student(const bool value){}

/*********************************************************************
** Function: bool Wall::has_student() const
** Description: a wall should not hold a student, so this always returns
   false.
** Parameters: none
*********************************************************************/ 
bool Wall::has_student() const{
    return false;
}

/*********************************************************************
** Function: void Wall::set_has_ta(const bool value)
** Description: undefined function for wall.
** Parameters: new value
*********************************************************************/ 
void Wall::set_has_ta(const bool value){}

/*********************************************************************
** Function: bool Wall::has_ta() const
** Description: a wall should not hold a TA, so this always returns false.
** Parameters: none
*********************************************************************/ 
bool Wall::has_ta() const{
    return false;
}

/*********************************************************************
** Function: void Wall::set_has_instructor(const bool value)
** Description: undefined function for wall
** Parameters: new value
*********************************************************************/ 
void Wall::set_has_instructor(const bool value){}

/*********************************************************************
** Function: bool Wall::has_instructor() const
** Description: a wall should not hold an instructor, so this always
   returns false.
** Parameters: none
*********************************************************************/ 
bool Wall::has_instructor() const{
    return false;
}

/*********************************************************************
** Function: void Wall::set_has_skill(const bool value)
** Description: undefined function for wall
** Parameters: new value
*********************************************************************/ 
void Wall::set_has_skill(const bool value){}

/*********************************************************************
** Function: bool Wall::has_skill() const
** Description: a wall should not hold a skill, so this always returns
   false.
** Parameters: none
*********************************************************************/ 
bool Wall::has_skill() const{
    return false;
}

/*********************************************************************
** Function: Wall::~Wall()
** Description: deletes the dynamically allocated object.
** Parameters: none
** Pre-Conditions: the maze is being deleted.
** Post-Conditions: the object is successfully deleted.
*********************************************************************/ 
Wall::~Wall(){}