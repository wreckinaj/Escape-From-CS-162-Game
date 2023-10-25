/*********************************************************************
** Program Filename: intrepidStudent.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: holds information about the student in the maze and how
   it should move.
** Input: calls for the student to move.
** Output: the move of the student is returned.
*********************************************************************/

#include <iostream>
#include "intrepidStudent.h"
#include "mazePerson.h"

using namespace std;

/*********************************************************************
** Function: IntrepidStudent::IntrepidStudent()
** Description: sets the value of the number of students on a space.
** Parameters: none
** Pre-Conditions: a student object is being created.
** Post-Conditions: the number of students on a space is set.
*********************************************************************/ 
IntrepidStudent::IntrepidStudent(){
    this->num_student = this->num_student + 1;
}

/*********************************************************************
** Function: char IntrepidStudent::get_move()
** Description: collects the move input from the user.
** Parameters: none
** Pre-Conditions: the student needs to make a move
** Post-Conditions: the move command is returned.
*********************************************************************/ 
char IntrepidStudent::get_move(){
    char move;
    cout << "w: up" << endl;
    cout << "s: down" << endl;
    cout << "a: left" << endl;
    cout << "d: right" << endl;
    cout << "p: use a programming skill" << endl;
    cin >> move;
    return move;
}

/*********************************************************************
** Function: IntrepidStudent::~IntrepidStudent()
** Description: the IntrepidStudent object is destroyed.
** Parameters: none
** Pre-Conditions: the people vector is being deleted.
** Post-Conditions: the IntrepidStudent object is destroyed.
*********************************************************************/ 
IntrepidStudent::~IntrepidStudent(){}