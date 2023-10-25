/*********************************************************************
** Program Filename: intrepidStudent.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: header file for the IntrepidStudent file.
*********************************************************************/

#ifndef INTREPIDSTUDENT_H
#define INTREPIDSTUDENT_H

#include "mazePerson.h"

class IntrepidStudent : public MazePerson{
    public:
        IntrepidStudent();
        char get_move();
        ~IntrepidStudent();
};

#endif