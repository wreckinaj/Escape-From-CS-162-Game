/*********************************************************************
** Program Filename: instructor.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: header file for the Instructor class.
*********************************************************************/

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "mazePerson.h"

class Instructor : public MazePerson{
    public:
        Instructor();
        char get_move();
        ~Instructor();
};

#endif