/*********************************************************************
** Program Filename: openSpace.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: returns and sets information an open space in the maze
   has.
** Input: a request for edits or access to information about an open space.
** Output: information about what an open space holds is set or returned.
*********************************************************************/

#include <iostream>
#include "openSpace.h"

using namespace std;

/*********************************************************************
** Function: OpenSpace::OpenSpace()
** Description: creates the OpenSpace object.
** Parameters: none
** Pre-Conditions: an OpenSpace object is being created.
** Post-Conditions: an OpenSpace object is created.
*********************************************************************/ 
OpenSpace::OpenSpace(){}

/*********************************************************************
** Function: void OpenSpace::set_has_student(const bool value)
** Description: sets a new value to determine if an open space has a
   student.
** Parameters: new value
*********************************************************************/ 
void OpenSpace::set_has_student(const bool value){
    this->has_st = value;
}

/*********************************************************************
** Function: bool OpenSpace::has_student() const
** Description: returns a boolean to determine if a student occupies a
   space.
** Parameters: none
*********************************************************************/ 
bool OpenSpace::has_student() const{
    return this->has_st;
}

/*********************************************************************
** Function: void OpenSpace::set_has_ta(const bool value)
** Description: sets a new value to determine if an open space has a TA.
** Parameters: new value
*********************************************************************/ 
void OpenSpace::set_has_ta(const bool value){
    this->has_TA = value;
}

/*********************************************************************
** Function: bool OpenSpace::has_ta() const
** Description: returns a boolean to determine if a TA occupies a space.
** Parameters: none
*********************************************************************/ 
bool OpenSpace::has_ta() const{
    return this->has_TA;
}

/*********************************************************************
** Function: void OpenSpace::set_has_instructor(const bool value)
** Description: sets a new value to determine if an open space has a
   instructor.
** Parameters: new value
*********************************************************************/ 
void OpenSpace::set_has_instructor(const bool value){
    this->has_i = value;
}

/*********************************************************************
** Function: bool OpenSpace::has_instructor() const
** Description: returns a boolean to determine if an instructor occupies a
   space.
** Parameters: none
*********************************************************************/ 
bool OpenSpace::has_instructor() const{
    return this->has_i;
}

/*********************************************************************
** Function: void OpenSpace::set_has_skill(const bool value)
** Description: sets a new value to determine if an open space has a
   skill.
** Parameters: new value
*********************************************************************/ 
void OpenSpace::set_has_skill(const bool value){
    this->has_sk = value;
}

/*********************************************************************
** Function: bool OpenSpace::has_skill() const
** Description: returns a boolean to determine if a skill occupies a
   space.
** Parameters: none
*********************************************************************/ 
bool OpenSpace::has_skill() const{
    return this->has_sk;
}

/*********************************************************************
** Function: OpenSpace::~OpenSpace()
** Description: destroys the OpenSpace object.
** Parameters: none
** Pre-Conditions: the maze is being deleted.
** Post-Conditions: the object is deleted.
*********************************************************************/ 
OpenSpace::~OpenSpace(){}