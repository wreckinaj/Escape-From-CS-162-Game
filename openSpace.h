/*********************************************************************
** Program Filename: openSpace.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: header file for the OpenSpace class.
*********************************************************************/

#ifndef OPENSPACE_H
#define OPENSPACE_H

#include "mazeLocation.h"

class OpenSpace : public MazeLocation{
    public:
        OpenSpace();
        void set_has_student(const bool value);
        bool has_student() const;
        void set_has_ta(const bool value);
        bool has_ta() const;
        void set_has_instructor(const bool value);
        bool has_instructor() const;
        void set_has_skill(const bool value);
        bool has_skill() const;
        ~OpenSpace();
};

#endif