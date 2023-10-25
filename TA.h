/*********************************************************************
** Program Filename: TA.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: header file for the TA class.
*********************************************************************/

#ifndef TA_H
#define TA_H

#include "mazePerson.h"

class TA : public MazePerson{
    public:
        TA();
        char get_move();
        bool get_has_moved() const;
        void set_has_moved(const bool value);
        ~TA();
};

#endif