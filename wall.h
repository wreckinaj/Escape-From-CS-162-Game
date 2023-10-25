/*********************************************************************
** Program Filename: wall.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: header file for the Wall class.
*********************************************************************/

#ifndef WALL_H
#define WALL_H

#include "mazeLocation.h"

class Wall : public MazeLocation{
    public:
        Wall();
        void set_has_student(const bool value);
        bool has_student() const;
        void set_has_ta(const bool value);
        bool has_ta() const;
        void set_has_instructor(const bool value);
        bool has_instructor() const;
        void set_has_skill(const bool value);
        bool has_skill() const;
        ~Wall();
};

#endif