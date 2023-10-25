/*********************************************************************
** Program Filename: mazeLocation.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: header file for the MazeLocation class.
*********************************************************************/

#ifndef MAZELOCATION_H
#define MAZELOCATION_H

#include <string>

using namespace std;

class MazeLocation{
    protected:
        char wall_char;
        char student_char;
        char TA_char;
        int num_TA;
        char instructor_char;
        char skill_char;
        bool has_st;
        bool has_TA;
        bool has_i;
        bool has_sk;
    public:
        MazeLocation();
        virtual void set_has_student(const bool value);
        virtual bool has_student() const;
        virtual void set_has_ta(const bool value);
        virtual bool has_ta() const;
        virtual void set_has_instructor(const bool value);
        virtual bool has_instructor() const;
        virtual void set_has_skill(const bool value);
        virtual bool has_skill() const;
        char get_wall_char() const;
        char get_student_char() const;
        char get_TA_char() const;
        int get_num_TA() const;
        char get_instructor_char() const;
        char get_skill_char() const;
        void set_student_char(const char value);
        void set_TA_char(const char value);
        void set_num_TA(const int value);
        void set_instructor_char(const char value);
        void set_skill(const char character);
        virtual ~MazeLocation();
};

#endif