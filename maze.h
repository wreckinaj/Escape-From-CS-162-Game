/*********************************************************************
** Program Filename: maze.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: serves as the header file for the Maze class
*********************************************************************/

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "mazeLocation.h"
#include "mazePerson.h"

using namespace std;

class Maze{
    private:
        vector < vector <MazeLocation*> > locations;
        vector < vector <MazePerson*> > people;
    public:
        void create_maze_vector(int side);
        void set_walls();
        bool test_for_north_wall(int row, int column);
        bool test_for_south_wall(int row, int column);
        bool test_for_west_wall(int row, int column);
        bool test_for_east_wall(int row, int column);
        void set_student_initial();
        void set_TA_initial();
        void set_instructor();
        void set_skills();
        void add_student();
        void add_TAs();
        void add_instructor();
        void create_people_vector();
        void print_line();
        void print_line_with_empty_spaces();
        void print_maze_people(int &empty_spaces, int i, int j);
        void print_line_with_characters(int i);
        void print_grid();
        void check_for_skill(int &acquired_skills);
        int find_student_row();
        int find_student_column(int row);
        bool test_for_north_TA(int row, int column);
        bool test_for_south_TA(int row, int column);
        bool test_for_west_TA(int row, int column);
        bool test_for_east_TA(int row, int column);
        bool caught_by_TA(int &appeasement_level);
        bool test_for_north_instructor(int row, int column);
        bool test_for_south_instructor(int row, int column);
        bool test_for_west_instructor(int row, int column);
        bool test_for_east_instructor(int row, int column);
        bool reached_instructor(int required_skills);
        void move_student_left(int i, int j);
        void move_student_right(int i, int j);
        void move_student_up(int i, int j);
        void move_student_down(int i, int j);
        void appease_TAs(int &acquired_skills, int &appeasement_level);
        bool evaluate_student_move(char move, int i, int j, int &acquired_skills, int &appeasement_level);
        void get_student_move(int i, int j, int &acquired_skills, int &appeasement_level);
        void play_student_move(int &acquired_skills, int &appeasement_level);
        void move_TA_left(int i, int j);
        void move_TA_right(int i, int j);
        void move_TA_up(int i, int j);
        void move_TA_down(int i, int j);
        bool evaluate_TA_move(char move, int i, int j);
        void get_TA_move(int i, int j);
        void play_TA_moves();
        void play_move(int &acquired_skills, int &appeasement_level);
        void clear_people_vector();
        ~Maze();
};

#endif