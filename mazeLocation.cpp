/*********************************************************************
** Program Filename: mazeLocation.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: holds functions used to edit what is located in the maze.
** Input: calls to what a space holds.
** Output: information about what a space in the maze holds.
*********************************************************************/

#include <iostream>
#include <string>
#include "mazeLocation.h"

using namespace std;

/*********************************************************************
** Function: MazeLocation::MazeLocation()
** Description: sets default values for a MazeLocation object.
** Parameters: none
** Pre-Conditions: a new MazeLocation object is set to be called.
** Post-Conditions: default values are set for the object.
*********************************************************************/ 
MazeLocation::MazeLocation(){
    this->wall_char = ' ';
    this->student_char = ' ';
    this->TA_char = ' ';
    this->num_TA = 0;
    this->instructor_char = ' ';
    this->skill_char = ' ';
    this->has_st = false;
    this->has_TA = false;
    this->has_i = false;
    this->has_sk = false;
}

/*********************************************************************
** Function: void MazeLocation::set_has_student(const bool value)
** Description: sets a new value to determine if a maze location has a
   student.
** Parameters: new boolean value
*********************************************************************/ 
void MazeLocation::set_has_student(const bool value){
    this->has_st = value;
}

/*********************************************************************
** Function: bool MazeLocation::has_student() const
** Description: returns a boolean to determine if a student occupies a
   space.
** Parameters: none
*********************************************************************/ 
bool MazeLocation::has_student() const{
    return this->has_st;
}

/*********************************************************************
** Function: void MazeLocation::set_has_ta(const bool value)
** Description: sets a new value to determine if a maze location has a
   TA.
** Parameters: new value
*********************************************************************/ 
void MazeLocation::set_has_ta(const bool value){
    this->has_TA = value;
}

/*********************************************************************
** Function: bool MazeLocation::has_ta() const
** Description: returns a boolean to determine if a TA occupies a space.
** Parameters: none
*********************************************************************/ 
bool MazeLocation::has_ta() const{
    return this->has_TA;
}

/*********************************************************************
** Function: void MazeLocation::set_has_instructor(const bool value)
** Description: sets a new value to determine if a maze location has an
   instructor.
** Parameters: new value
*********************************************************************/ 
void MazeLocation::set_has_instructor(const bool value){
    this->has_i = value;
}

/*********************************************************************
** Function: bool MazeLocation::has_instructor() const
** Description: returns a boolean to determine if an instructor occupies a
   space.
** Parameters: none
*********************************************************************/ 
bool MazeLocation::has_instructor() const{
    return this->has_i;
}

/*********************************************************************
** Function: void MazeLocation::set_has_skill(const bool value)
** Description: sets a new value to determine if a maze location has a
   skill.
** Parameters: new value
*********************************************************************/ 
void MazeLocation::set_has_skill(const bool value){
    this->has_sk = value;
}

/*********************************************************************
** Function: bool MazeLocation::has_skill() const
** Description: returns a boolean to determine if a skill occupies a
   space.
** Parameters: none
*********************************************************************/ 
bool MazeLocation::has_skill() const{
    return this->has_sk;
}

/*********************************************************************
** Function: char MazeLocation::get_wall_char() const
** Description: returns a character to determine if a wall occupies a
   space.
** Parameters: none
*********************************************************************/ 
char MazeLocation::get_wall_char() const{
    return this->wall_char;
}

/*********************************************************************
** Function: char MazeLocation::get_student_char() const
** Description: returns a character to determine if a student occupies a
   space.
** Parameters: none
*********************************************************************/ 
char MazeLocation::get_student_char() const{
    return this->student_char;
}

/*********************************************************************
** Function: char MazeLocation::get_TA_char() const
** Description: returns a character to determine if a TA occupies a space.
** Parameters: none
*********************************************************************/ 
char MazeLocation::get_TA_char() const{
    return this->TA_char;
}

/*********************************************************************
** Function: int MazeLocation::get_num_TA() const
** Description: returns a number to determine the number of TAs that occupy
   a space.
** Parameters: none
*********************************************************************/ 
int MazeLocation::get_num_TA() const{
    return this->num_TA;
}

/*********************************************************************
** Function: char MazeLocation::get_instructor_char() const
** Description: returns a character to determine if an instructor occupies a
   space.
** Parameters: none
*********************************************************************/ 
char MazeLocation::get_instructor_char() const{
    return this->instructor_char;
}

/*********************************************************************
** Function: char MazeLocation::get_skill_char() const
** Description: returns a character to determine if a skill occupies a
   space.
** Parameters: none
*********************************************************************/ 
char MazeLocation::get_skill_char() const{
    return this->skill_char;
}

/*********************************************************************
** Function: void MazeLocation::set_student_char(const char value)
** Description: sets a new character to determine if a maze location has a
   student.
** Parameters: new character
*********************************************************************/ 
void MazeLocation::set_student_char(const char value){
    this->student_char = value;
}

/*********************************************************************
** Function: void MazeLocation::set_TA_char(const char value)
** Description: sets a new character to determine if a maze location has a
   TA.
** Parameters: new character
*********************************************************************/ 
void MazeLocation::set_TA_char(const char value){
    this->TA_char = value;
}

/*********************************************************************
** Function: void MazeLocation::set_num_TA(const int value)
** Description: sets a new value to determine the number of TAs on a
   space.
** Parameters: new character
*********************************************************************/ 
void MazeLocation::set_num_TA(const int value){
    this->num_TA = value;
}

/*********************************************************************
** Function: void MazeLocation::set_instructor_char(const char value)
** Description: sets a new character to determine if a maze location has an
   instructor.
** Parameters: new number of TAs
*********************************************************************/ 
void MazeLocation::set_instructor_char(const char value){
    this->instructor_char = value;
}

/*********************************************************************
** Function: void MazeLocation::set_skill(const char character)
** Description: sets a new value to determine if a maze location has a
   skill.
** Parameters: new character
*********************************************************************/ 
void MazeLocation::set_skill(const char character){
    this->skill_char = character;
}

/*********************************************************************
** Function: MazeLocation::~MazeLocation()
** Description: deletes the dynamically allocated object.
** Parameters: none
** Pre-Conditions: the maze is being deleted.
** Post-Conditions: the object is successfully deleted.
*********************************************************************/ 
MazeLocation::~MazeLocation(){}