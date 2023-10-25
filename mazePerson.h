/*********************************************************************
** Program Filename: mazePerson.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: header file for the MazePerson class.
*********************************************************************/

#ifndef MAZEPERSON_H
#define MAZEPERSON_H

using namespace std;

class MazePerson{
    protected:
        int num_student;
        int num_TA;
        int num_instructor;
        bool has_moved;
    public:
        MazePerson();
        int get_num_student() const;
        virtual char get_move();
        void set_num_TA(const int value);
        int get_num_TA() const;
        virtual bool get_has_moved() const;
        virtual void set_has_moved(const bool value);
        virtual ~MazePerson();
};

#endif