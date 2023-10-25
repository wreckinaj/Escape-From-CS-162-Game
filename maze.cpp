/*********************************************************************
** Program Filename: maze.cpp
** Author: Anthony Silva
** Date: 03-06-2023
** Description: runs the entire maze for the game. Functions are stored
   here to run both of the vectors used to keep track of what is in the
   maze, as well as determine the conditions for ending the game and to
   move the students and the TAs.
** Input: a maze vector with a given sidelength is used to help run the
   functionality here.
** Output: the program tracks the location of every person and object
   in the maze to make sure things run smoothly.
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "maze.h"
#include "mazeLocation.h"
#include "wall.h"
#include "openSpace.h"
#include "mazePerson.h"
#include "intrepidStudent.h"
#include "TA.h"
#include "instructor.h"

/*********************************************************************
** Function: void Maze::create_maze_vector(int side)
** Description: creates the square maze vector of the appropriate size,
   populating it with dynamic memory of Open Spaces.
** Parameters: the side length of the grid, as determined by the user.
** Pre-Conditions: the appropriate side length input is created by the user.
** Post-Conditions: the initial populated maze vector is complete.
*********************************************************************/ 
void Maze::create_maze_vector(int side){
    this->locations.resize(side);
    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            this->locations[i].push_back(new OpenSpace);
        }
    }
}

/*********************************************************************
** Function: void Maze::set_walls()
** Description: sets the walls of the maze.
** Parameters: none
** Pre-Conditions: the initial vector is successfully set up.
** Post-Conditions: four walls replace open spaces in the maze, and
   these spaces are inaccessible.
*********************************************************************/ 
void Maze::set_walls(){
    int row;
    int column;
    for(int i = 0; i < 4; i++){
        row = rand() % this->locations.size();
        column = rand() % this->locations[0].size();
        // the program will try again if there is already a row in
        // a requested location in the maze.
        if(locations[row][column]->get_wall_char() != '#'){
            delete locations[row][column];
            locations[row][column] = new Wall();
        }
        else{
            i = i - 1;
        }
    }
}

/*********************************************************************
** Function: bool Maze::test_for_north_wall(int row, int column)
** Description: determines if there is a wall in the northward direction
   of a position in the maze.
** Parameters: a row and column of the maze.
** Pre-Conditions: the program wants to know if the student or TA is able
   to move up.
** Post-Conditions: the function returns true if the northward direction
   is accessible (no wall or boundary).
*********************************************************************/ 
bool Maze::test_for_north_wall(int row, int column){
    if(row == 0){
        return false;
    }
    else if(locations[row - 1][column]->get_wall_char() == '#'){
        return false;
    }
    return true;
}

/*********************************************************************
** Function: bool Maze::test_for_south_wall(int row, int column)
** Description: determines if there is a wall in the southward direction
   of a position in the maze.
** Parameters: a row and column of the maze.
** Pre-Conditions: the program wants to know if the student or TA is able
   to move down.
** Post-Conditions: the function returns true if the southward direction
   is accessible (no wall or boundary).
*********************************************************************/ 
bool Maze::test_for_south_wall(int row, int column){
    if(row == this->locations.size() - 1){
        return false;
    }
    else if(locations[row + 1][column]->get_wall_char() == '#'){
        return false;
    }
    return true;
}

/*********************************************************************
** Function: bool Maze::test_for_west_wall(int row, int column)
** Description: determines if there is a wall in the westward direction
   of a position in the maze.
** Parameters: a row and column of the maze.
** Pre-Conditions: the program wants to know if the student or TA is able
   to move left.
** Post-Conditions: the function returns true if the westward direction
   is accessible (no wall or boundary).
*********************************************************************/ 
bool Maze::test_for_west_wall(int row, int column){
    if(column == 0){
        return false;
    }
    else if(locations[row][column - 1]->get_wall_char() == '#'){
        return false;
    }
    return true;
}

/*********************************************************************
** Function: bool Maze::test_for_east_wall(int row, int column)
** Description: determines if there is a wall in the eastward direction
   of a position in the maze.
** Parameters: a row and column of the maze.
** Pre-Conditions: the program wants to know if the student or TA is able
   to move right.
** Post-Conditions: the function returns true if the eastward direction
   is accessible (no wall or boundary).
*********************************************************************/ 
bool Maze::test_for_east_wall(int row, int column){
    if(column == this->locations[0].size() - 1){
        return false;
    }
    else if(locations[row][column + 1]->get_wall_char() == '#'){
        return false;
    }
    return true;
}

/*********************************************************************
** Function: void Maze::set_student_initial()
** Description: sets the initial position of the student at the start
   of the game.
** Parameters: none
** Pre-Conditions: the initial vector is created, and the four walls
   are set.
** Post-Conditions: the student is placed in a spot where they can move
   at least one space.
*********************************************************************/ 
void Maze::set_student_initial(){
    int row;
    int column;
    // the program repeats until a valid position for the space is set.
    while(true){
        row = rand() % this->locations.size();
        column = rand() % this->locations[0].size();
        // the student cannot be in a spot with a wall in it.
        if(locations[row][column]->get_wall_char() == '#'){
            continue;
        }
        // the student cannot be in a spot with walls or boundaries in all directions.
        else if(!test_for_north_wall(row, column) && !test_for_south_wall(row, column) && !test_for_west_wall(row, column) && !test_for_east_wall(row, column)){
            continue;
        }
        locations[row][column]->set_has_student(true);
        locations[row][column]->set_student_char('*');
        break;
    }
}

/*********************************************************************
** Function: void Maze::set_TA_initial()
** Description: sets the initial position of the three TAs.
** Parameters: none
** Pre-Conditions: the initial maze vector is created, and the four walls
   and intrepid student are set.
** Post-Conditions: the three initial positions of the TAs are set at
   the beginning of the game.
*********************************************************************/ 
void Maze::set_TA_initial(){
    int row;
    int column;
    for(int i = 0; i < 3; i++){
        // function repeats until a valid position for the TA is given.
        while(true){
            row = rand() % this->locations.size();
            column = rand() % this->locations[0].size();
            // the TA cannot occupy a wall space.
            if(locations[row][column]->get_wall_char() == '#'){
                continue;
            }
            // the TA must be able to move at least one space from the initial position.
            else if(!test_for_north_wall(row, column) && !test_for_south_wall(row, column) && !test_for_west_wall(row, column) && !test_for_east_wall(row, column)){
                continue;
            }
            locations[row][column]->set_has_ta(true);
            locations[row][column]->set_TA_char('T');
            locations[row][column]->set_num_TA(locations[row][column]->get_num_TA() + 1);
            break;
        }
    }
}

/*********************************************************************
** Function: void Maze::set_instructor()
** Description: sets the position of the instructor at the start of the game.
** Parameters: none
** Pre-Conditions: the initial vector is created, and the four walls,
   intrepid student, and three TAs are set.
** Post-Conditions: the instructor is placed in a spot where the student
   can reach an adjacent square.
*********************************************************************/ 
void Maze::set_instructor(){
    int row;
    int column;
    // function repeats until a valid position is chosen.
    while(true){
        row = rand() % this->locations.size();
        column = rand() % this->locations[0].size();
        // the instructor cannot occupy a wall
        if(locations[row][column]->get_wall_char() == '#'){
            continue;
        }
        // the instructor cannot be on the same space as the student.
        else if(locations[row][column]->has_student()){
             continue;
        }
        // the instructor cannot be on the same space as a TA.
        else if(locations[row][column]->has_ta()){
            continue;
        }
        // there cannot be a wall or boundary in every direction.
        else if(!test_for_north_wall(row, column) && !test_for_south_wall(row, column) && !test_for_west_wall(row, column) && !test_for_east_wall(row, column)){
            continue;
        }
        locations[row][column]->set_has_instructor(true);
        locations[row][column]->set_instructor_char('%');
        break;
    }
}

/*********************************************************************
** Function: void Maze::set_skills()
** Description: the positions of the six programming skills are set at
   the beginning of the game.
** Parameters: none
** Pre-Conditions: the initial maze vector is created, along with four
   walls, three TAs, the student, and the instructor.
** Post-Conditions: the six programming skills are placed in positions
   that are reachable.
*********************************************************************/ 
void Maze::set_skills(){
    int row;
    int column;
    for(int i = 0; i < 6; i++){
        // the function repeats until a valid position is given.
        while(true){
            row = rand() % this->locations.size();
            column = rand() % this->locations[0].size();
            // a skill cannot be in the same spot as a wall.
            if(locations[row][column]->get_wall_char() == '#'){
                continue;
            }
            // there cannot be a wall in all directions.
            else if(!test_for_north_wall(row, column) && !test_for_south_wall(row, column) && !test_for_west_wall(row, column) && !test_for_east_wall(row, column)){
                continue;
            }
            // no programming skill can be in the same space as the instructor
            else if(locations[row][column]->has_instructor()){
                continue;
            }
            // a space cannot have more than one programming skill
            else if(locations[row][column]->get_skill_char() == '$'){
                continue;
            }
            locations[row][column]->set_has_skill(true);
            locations[row][column]->set_skill('$');
            break;
        }
    }
}

/*********************************************************************
** Function: void Maze::add_student()
** Description: the student is added to the people vector based on its
   initial position.
** Parameters: none
** Pre-Conditions: the people vector is being created at the start of the game.
** Post-Conditions: the student is added in the correct position of the
   people vector.
*********************************************************************/ 
void Maze::add_student(){
    for(int i = 0; i < this->locations.size(); i++){
        for(int j = 0; j < this->locations.size(); j++){
            if(locations[i][j]->get_student_char() == '*'){
                this->people[i][j] = new IntrepidStudent;
                return;
            }
        }
    }
}

/*********************************************************************
** Function: void Maze::add_TAs()
** Description: the TAs are added to the people vector based on their
   initial positions.
** Parameters: none
** Pre-Conditions: the people vector is being created at the start of
   the game.
** Post-Conditions: the TAs are added in the correct positions of the
   people vector.
*********************************************************************/ 
void Maze::add_TAs(){
    for(int i = 0; i < this->locations.size(); i++){
        for(int j = 0; j < this->locations.size(); j++){
            if(locations[i][j]->get_TA_char() == 'T' && people[i][j] == NULL){
                this->people[i][j] = new TA;
            }
        }
    }
}

/*********************************************************************
** Function: void Maze::add_instructor()
** Description: the instructor is added to the people vector based on its
   initial position.
** Parameters: none
** Pre-Conditions: the people vector is being created at the start of the game.
** Post-Conditions: the instructor is added in the correct position of the
   people vector.
*********************************************************************/ 
void Maze::add_instructor(){
    for(int i = 0; i < this->locations.size(); i++){
        for(int j = 0; j < this->locations.size(); j++){
            if(locations[i][j]->get_instructor_char() == '%'){
                this->people[i][j] = new Instructor;
                return;
            }
        }
    }
}

/*********************************************************************
** Function: void Maze::create_people_vector()
** Description: creates the people vector to be set up identical to the
   maze vector, before adding the student, TAs, and instructor.
** Parameters: none
** Pre-Conditions: the maze vector is set up.
** Post-Conditions: the people vector is correctly populated, ready for
   use.
*********************************************************************/ 
void Maze::create_people_vector(){
    if(this->people.size() != this->locations.size()){
        this->people.resize(this->locations.size());
    }
    for(int i = 0; i < this->people.size(); i++){
        if(this->people[i].size() != this->locations[i].size()){
            this->people[i].resize(this->locations[i].size());
        }
    }
    add_student();
    add_TAs();
    add_instructor();
}

/*********************************************************************
** Function: void Maze::print_line()
** Description: prints a line for the grid.
** Parameters: none
** Pre-Conditions: the grid is ready to begin printing or is on the last
   step, or a grid is finished.
** Post-Conditions: a line to separate blocks horizontally is created.
*********************************************************************/ 
void Maze::print_line(){
    for(int i = 0; i < this->locations.size(); i++){
        for(int i = 0; i < 6; i++){
            cout << "_";
        }
    }
    cout << endl;
}

/*********************************************************************
** Function: void Maze::print_line_with_empty_spaces()
** Description: a line is printed with empty spaces in the block of the
   grid.
** Parameters: none
** Pre-Conditions: the print grid function is in the middle of printing a
   row of blocks.
** Post-Conditions: a line with empty spaces in the middle of the blocks is
   created.
*********************************************************************/ 
void Maze::print_line_with_empty_spaces(){
    for(int i = 0; i < this->locations.size(); i++){
        cout << "|";
        for(int j = 0; j < 5; j++){
            cout << " ";
        }
    }
    cout << "|" << endl;
}

/*********************************************************************
** Function: void Maze::print_maze_people(int &empty_spaces, int i, int j)
** Description: the information about the people in a space in the maze
   is printed.
** Parameters: the number of empty spaces available, as well as the row
   and column of the position of the maze.
** Pre-Conditions: the print grid function is in the middle of printing
   the maze objects.
** Post-Conditions: the information about the people in the maze is printed.
*********************************************************************/ 
void Maze::print_maze_people(int &empty_spaces, int i, int j){
    cout << locations[i][j]->get_student_char();
    cout << locations[i][j]->get_TA_char();
    cout << locations[i][j]->get_instructor_char();
    empty_spaces = empty_spaces - 3;
}

/*********************************************************************
** Function: void Maze::print_line_with_characters(int i)
** Description: prints a row of characters that represent the different
   objects in the maze.
** Parameters: the row of the maze
** Pre-Conditions: the print grid function is ready to print the characters
   based on the row of the maze.
** Post-Conditions: the line with all the object characters is printed.
*********************************************************************/ 
void Maze::print_line_with_characters(int i){
    int empty_spaces;
    for(int j = 0; j < this->locations.size(); j++){
        empty_spaces = 5;
        cout << "|";
        if(locations[i][j]->get_wall_char() == '#'){
            cout << "#";
            empty_spaces = empty_spaces - 1;
        }
        else{
            if(locations[i][j]->get_skill_char() == '$'){
                cout << "$";
                empty_spaces = empty_spaces - 1;
            }
            print_maze_people(empty_spaces, i, j);
        }
        for(int k = 0; k < empty_spaces; k++){
            cout << " ";
        }
    }
    cout << "|" << endl;
}

/*********************************************************************
** Function: void Maze::print_grid()
** Description: prints the entire grid for the maze.
** Parameters: none
** Pre-Conditions: the beginning of a turn.
** Post-Conditions: the entire grid that represents the maze is printed.
*********************************************************************/ 
void Maze::print_grid(){
    for(int i = 0; i < this->locations.size(); i++){
        print_line();
        for(int j = 0; j < 2; j++){
            print_line_with_empty_spaces();
        }
        print_line_with_characters(i);
        for(int j = 0; j < 2; j++){
            print_line_with_empty_spaces();
        }
    }
    print_line();
}

/*********************************************************************
** Function: void Maze::check_for_skill(int &acquired_skills)
** Description: checks to see if the student is on a space where a
   programming skill lies.
** Parameters: a reference to the acquired skills.
** Pre-Conditions: the beginning of a turn, after the grid is printed.
** Post-Conditions: if the student is on a programming skill, the skill
   disappears from the maze, and the number of skills in hand increases
   by one.
*********************************************************************/ 
void Maze::check_for_skill(int &acquired_skills){
    for(int i = 0; i < this->locations.size(); i++){
        for(int j = 0; j < this->locations.size(); j++){
            if(locations[i][j]->get_student_char() == '*'){
                if(locations[i][j]->get_skill_char() == '$'){
                    cout << "You have obtained a programming skill!" << endl;
                    acquired_skills = acquired_skills + 1;
                    locations[i][j]->set_skill(' ');
                }
            }
        }
    }
}

/*********************************************************************
** Function: int Maze::find_student_row()
** Description: finds the row of the student.
** Parameters: none
** Pre-Conditions: the program wants to determine if the student is
   caught by the TA.
** Post-Conditions: the row of the student is returned.
*********************************************************************/ 
int Maze::find_student_row(){
    for(int i = 0; i < this->locations.size(); i++){
        for(int j = 0; j < this->locations.size(); j++){
            if(locations[i][j]->get_student_char() == '*'){
                return i;
            }
        }
    }
}

/*********************************************************************
** Function: int Maze::find_student_column(int row)
** Description: finds the column of the student.
** Parameters: the row of the student.
** Pre-Conditions: the row of the student has already been found.
** Post-Conditions: the column of the student is returned.
*********************************************************************/ 
int Maze::find_student_column(int row){
    for(int i = 0; i < this->locations.size(); i++){
        if(locations[row][i]->get_student_char() == '*'){
            return i;
        }
    }
}

/*********************************************************************
** Function: bool Maze::test_for_north_TA(int row, int column)
** Description: determines if there is a TA to the northside of the student.
** Parameters: the row and the column of the student.
** Pre-Conditions: the row and column of the student is obtained.
** Post-Conditions: the function returns true if the student is caught
   by a TA on the northside.
*********************************************************************/ 
bool Maze::test_for_north_TA(int row, int column){
    if(row > 0){
        if(locations[row - 1][column]->get_TA_char() == 'T'){
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: Maze::test_for_south_TA(int row, int column)
** Description: determines if there is a TA to the southside of the student.
** Parameters: the row and the column of the student.
** Pre-Conditions: the row and column of the student is obtained.
** Post-Conditions: the function returns true if the student is caught
   by a TA on the southside.
*********************************************************************/ 
bool Maze::test_for_south_TA(int row, int column){
    if(row < this->locations.size() - 1){
        if(locations[row + 1][column]->get_TA_char() == 'T'){
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: bool Maze::test_for_west_TA(int row, int column)
** Description: determines if there is a TA to the westside of the student.
** Parameters: the row and the column of the student.
** Pre-Conditions: the row and column of the student is obtained.
** Post-Conditions: the function returns true if the student is caught
   by a TA on the westside.
*********************************************************************/
bool Maze::test_for_west_TA(int row, int column){
    if(column > 0){
        if(locations[row][column - 1]->get_TA_char() == 'T'){
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: bool Maze::test_for_east_TA(int row, int column)
** Description: determines if there is a TA to the eastside of the student.
** Parameters: the row and the column of the student.
** Pre-Conditions: the row and column of the student is obtained.
** Post-Conditions: the function returns true if the student is caught
   by a TA on the eastside.
*********************************************************************/ 
bool Maze::test_for_east_TA(int row, int column){
    if(column < this->locations.size() - 1){
        if(locations[row][column + 1]->get_TA_char() == 'T'){
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: bool Maze::caught_by_TA(int &appeasement_level)
** Description: determines if the student was caught by one of the TAs,
   and terminates the game if that happens.
** Parameters: a reference to the appeasement level
** Pre-Conditions: the beginning of a turn after the student has picked
   up any present programming skill.
** Post-Conditions: the function returns true and terminates the game
   if the student is on the same square as a TA or is on a square adjacent
   to a TA.
*********************************************************************/ 
bool Maze::caught_by_TA(int &appeasement_level){
    int row = find_student_row();
    int column = find_student_column(row);
    if(locations[row][column]->get_TA_char() == 'T' && appeasement_level == 0){
        cout << "You have been caught by the TA! GAME OVER!" << endl;
        return true;
    }
    if((test_for_north_TA(row, column) || test_for_south_TA(row, column) || test_for_west_TA(row, column) || test_for_east_TA(row, column)) && appeasement_level == 0){
        cout << "You have been caught by the TA! GAME OVER!" << endl;
        return true;
    }
    return false;
}

/*********************************************************************
** Function: bool Maze::test_for_north_instructor(int row, int column)
** Description: checks to see if the instructor is on the northside of
   the student.
** Parameters: the row and column of the student.
** Pre-Conditions: the row and column of the student is obtained.
** Post-Conditions: the function returns true if the instructor is to
   the northside of the student.
*********************************************************************/ 
bool Maze::test_for_north_instructor(int row, int column){
    if(row > 0){
        if(locations[row - 1][column]->get_instructor_char() == '%'){
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: bool Maze::test_for_south_instructor(int row, int column)
** Description: checks to see if the instructor is on the southside of
   the student.
** Parameters: the row and column of the student.
** Pre-Conditions: the row and column of the student is obtained.
** Post-Conditions: the function returns true if the instructor is to
   the southside of the student.
*********************************************************************/ 
bool Maze::test_for_south_instructor(int row, int column){
    if(row < this->locations.size() - 1){
        if(locations[row + 1][column]->get_instructor_char() == '%'){
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: bool Maze::test_for_west_instructor(int row, int column)
** Description: checks to see if the instructor is on the westside of
   the student.
** Parameters: the row and column of the student.
** Pre-Conditions: the row and column of the student is obtained.
** Post-Conditions: the function returns true if the instructor is to
   the westside of the student.
*********************************************************************/ 
bool Maze::test_for_west_instructor(int row, int column){
    if(column > 0){
        if(locations[row][column - 1]->get_instructor_char() == '%'){
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: bool Maze::test_for_east_instructor(int row, int column)
** Description: checks to see if the instructor is on the northside of
   the student.
** Parameters: the row and column of the student.
** Pre-Conditions: the row and column of the student is obtained.
** Post-Conditions: the function returns true if the instructor is to
   the eastside of the student.
*********************************************************************/ 
bool Maze::test_for_east_instructor(int row, int column){
    if(column < this->locations.size() - 1){
        if(locations[row][column + 1]->get_instructor_char() == '%'){
            return true;
        }
    }
    return false;
}

/*********************************************************************
** Function: bool Maze::reached_instructor(int acquired_skills)
** Description: determines if the student has reached the instructor,
   and if they did, determines if the player won the game.
** Parameters: the acquired skills obtained.
** Pre-Conditions: the grid is printed, and the student is not caught
   by the TAs.
** Post-Conditions: the functions returns true if the student has reached
   the instructor. The player loses the game if they do not have at least
   three programming skills. They win if otherwise. The game is terminated
   from here.
*********************************************************************/ 
bool Maze::reached_instructor(int acquired_skills){
    int row = find_student_row();
    int column = find_student_column(row);
    // the instructor must be on an adjacent square to the student.
    if(test_for_north_instructor(row, column) || test_for_south_instructor(row, column) || test_for_west_instructor(row, column) || test_for_east_instructor(row, column)){
        // the student must have at least 3 skills in order to win.
        if(acquired_skills >= 3){
            cout << "The instructor has given you a passing grade!" << endl;
            cout << "You can now escape from CS 162! You win!" << endl;
        }
        else{
            cout << "The instructor has given you a failing grade!" << endl;
            cout << "You lose! GAME OVER!" << endl;
        }
        return true;
    }
    return false;
}

/*********************************************************************
** Function: void Maze::move_student_up(int i, int j)
** Description: moves the student up one position.
** Parameters: the row and position of the student.
** Pre-Conditions: there are no walls or boundaries in the way.
** Post-Conditions: the student moves up one.
*********************************************************************/ 
void Maze::move_student_up(int i, int j){
    locations[i][j]->set_student_char(' ');
    people[i - 1][j] = people[i][j];
    people[i][j] = NULL;
    locations[i - 1][j]->set_student_char('*');
}

/*********************************************************************
** Function: void Maze::move_student_down(int i, int j)
** Description: moves the student down one position.
** Parameters: the row and position of the student.
** Pre-Conditions: there are no walls or boundaries in the way.
** Post-Conditions: the student moves down one.
*********************************************************************/ 
void Maze::move_student_down(int i, int j){
    locations[i][j]->set_student_char(' ');
    people[i + 1][j] = people[i][j];
    people[i][j] = NULL;
    locations[i + 1][j]->set_student_char('*');
}

/*********************************************************************
** Function: void Maze::move_student_left(int i, int j)
** Description: moves the student left one position.
** Parameters: the row and position of the student.
** Pre-Conditions: there are no walls or boundaries in the way.
** Post-Conditions: the student moves left one.
*********************************************************************/ 
void Maze::move_student_left(int i, int j){
    locations[i][j]->set_student_char(' ');
    people[i][j - 1] = people[i][j];
    people[i][j] = NULL;
    locations[i][j - 1]->set_student_char('*');
}

/*********************************************************************
** Function: void Maze::move_student_right(int i, int j)
** Description: moves the student right one position.
** Parameters: the row and position of the student.
** Pre-Conditions: there are no walls or boundaries in the way.
** Post-Conditions: the student moves right one.
*********************************************************************/ 
void Maze::move_student_right(int i, int j){
    locations[i][j]->set_student_char(' ');
    people[i][j + 1] = people[i][j];
    people[i][j] = NULL;
    locations[i][j + 1]->set_student_char('*');
}

/*********************************************************************
** Function: void Maze::appease_TAs(int &acquired_skills, int &appeasement_level)
** Description: takes away the acquired skills in hand, and sets the
   appeasement level up for 10 turns. Therefore, the TAs will ignore the student
   for 10 turns.
** Parameters: references to the acquired skills in hand, and the number of moves
   left to appease the TAs.
** Pre-Conditions: the student has programming skills in hand.
** Post-Conditions: the program takes away one programming skill, and
   the student has appeased the TA for 10 turns (note that 11 is the initial
   number, but it will immediately drop to 10 at the end of the turn).
*********************************************************************/ 
void Maze::appease_TAs(int &acquired_skills, int &appeasement_level){
    acquired_skills = acquired_skills - 1;
    appeasement_level = 11;
}

/*********************************************************************
** Function: bool Maze::evaluate_student_move(char move, int i, int j, int &acquired_skills, int &appeasement_level)
** Description: determines if the move is valid, and if it is, performs the
   correct command.
** Parameters: the move command set by the user, the row and column of the
   student, and references to the acquired skills in hand the number of moves
   left to appease the TAs.
** Pre-Conditions: a valid input is given by the user (not null).
** Post-Conditions: the move is evaluated, and if it can be performed,
   the function returns true.
*********************************************************************/ 
bool Maze::evaluate_student_move(char move, int i, int j, int &acquired_skills, int &appeasement_level){
    if(move == 'w' && test_for_north_wall(i, j)){
        move_student_up(i, j);
        return true;
    }
    else if(move == 's' && test_for_south_wall(i, j)){
        move_student_down(i, j);
        return true;
    }
    else if(move == 'a' && test_for_west_wall(i, j)){
        move_student_left(i, j);
        return true;
    }
    else if(move == 'd' && test_for_east_wall(i, j)){
        move_student_right(i, j);
        return true;
    }
    else if(move == 'p' && acquired_skills > 0){
        appease_TAs(acquired_skills, appeasement_level);
        return true;
    }
    return false;
}

/*********************************************************************
** Function: void Maze::get_student_move(int i, int j, int &acquired_skills, int &appeasement_level)
** Description: collects the move of the student from the user, and evaluates
   it. If the input is invalid (with the exception of null input, which creates
   a segmentation fault), an error message is displayed.
** Parameters: the row and column of the student, and references to the
   acquired skills in hand and the number of moves left to appease the TAs.
** Pre-Conditions: the student is located in the maze.
** Post-Conditions: the move command is collected from the user, and either
   the correct function is called, or an error message is displayed. Assume
   a character input is given.
*********************************************************************/ 
void Maze::get_student_move(int i, int j, int &acquired_skills, int &appeasement_level){
    char move = people[i][j]->get_move();
    if(!evaluate_student_move(move, i, j, acquired_skills, appeasement_level)){
        cout << "Invalid input." << endl;
    }
}

/*********************************************************************
** Function: void Maze::play_student_move(int &acquired_skills, int &appeasement_level)
** Description: searches for the student before making the student move.
** Parameters: references to the acquired skills in hand and the number of
   moves left to appease the TAs.
** Pre-Conditions: no conditions are met to end the game.
** Post-Conditions: The student move is played.
*********************************************************************/ 
void Maze::play_student_move(int &acquired_skills, int &appeasement_level){
    for(int i = 0; i < this->people.size(); i++){
        for(int j = 0; j < this->people.size(); j++){
            if(locations[i][j]->get_student_char() == '*'){
                get_student_move(i, j, acquired_skills, appeasement_level);
                return;
            }
        }
    }
}

/*********************************************************************
** Function: void Maze::move_TA_up(int i, int j)
** Description: moves the TA up one space.
** Parameters: the row and column of the TA.
** Pre-Conditions: there are no wall or boundaries in the way, and the
   TA has not moved yet.
** Post-Conditions: the TA moves up one space.
*********************************************************************/ 
void Maze::move_TA_up(int i, int j){
    locations[i][j]->set_TA_char(' ');
    people[i - 1][j] = people[i][j];
    people[i][j] = NULL;
    locations[i - 1][j]->set_TA_char('T');
    people[i - 1][j]->set_has_moved(true);
}

/*********************************************************************
** Function: void Maze::move_TA_down(int i, int j)
** Description: moves the TA down one space.
** Parameters: the row and column of the TA.
** Pre-Conditions: there are no wall or boundaries in the way, and the
   TA has not moved yet.
** Post-Conditions: the TA moves down one space.
*********************************************************************/ 
void Maze::move_TA_down(int i, int j){
    locations[i][j]->set_TA_char(' ');
    people[i + 1][j] = people[i][j];
    people[i][j] = NULL;
    locations[i + 1][j]->set_TA_char('T');
    people[i + 1][j]->set_has_moved(true);
}

/*********************************************************************
** Function: void Maze::move_TA_left(int i, int j)
** Description: moves the TA left one space.
** Parameters: the row and column of the TA.
** Pre-Conditions: there are no wall or boundaries in the way, and the
   TA has not moved yet.
** Post-Conditions: the TA moves left one space.
*********************************************************************/ 
void Maze::move_TA_left(int i, int j){
    locations[i][j]->set_TA_char(' ');
    people[i][j - 1] = people[i][j];
    people[i][j] = NULL;
    locations[i][j - 1]->set_TA_char('T');
    people[i][j - 1]->set_has_moved(true);
}

/*********************************************************************
** Function: move_TA_right(int i, int j)
** Description: moves the TA right one space.
** Parameters: the row and column of the TA.
** Pre-Conditions: there are no wall or boundaries in the way, and the
   TA has not moved yet.
** Post-Conditions: the TA moves right one space.
*********************************************************************/ 
void Maze::move_TA_right(int i, int j){
    locations[i][j]->set_TA_char(' ');
    people[i][j + 1] = people[i][j];
    people[i][j] = NULL;
    locations[i][j + 1]->set_TA_char('T');
    people[i][j + 1]->set_has_moved(true);
}

/*********************************************************************
** Function: bool Maze::evaluate_TA_move(char move, int i, int j)
** Description: evaluates the TA move command to see if it is valid, and
   if it is, move in the correct direction.
** Parameters: the move command, and the row and column of the TA.
** Pre-Conditions: by random selection, the move command is given.
** Post-Conditions: the function returns true and moves the TA in the
   correct direction if the direction needed to go does not involve
   running into a wall or the instructor.
*********************************************************************/ 
bool Maze::evaluate_TA_move(char move, int i, int j){
    if(move == 'w' && test_for_north_wall(i, j) && !test_for_north_instructor(i, j)){
        move_TA_up(i, j);
        return true;
    }
    else if(move == 's' && test_for_south_wall(i, j) && !test_for_south_instructor(i,j)){
        move_TA_down(i, j);
        return true;
    }
    else if(move == 'a' && test_for_west_wall(i, j) && !test_for_west_instructor(i,j)){
        move_TA_left(i, j);
        return true;
    }
    else if(move == 'd' && test_for_east_wall(i, j) && !test_for_east_instructor(i,j)){
        move_TA_right(i, j);
        return true;
    }
    return false;
}

/*********************************************************************
** Function: void Maze::get_TA_move(int i, int j)
** Description: collects the move command based on random selection, and
   performs the correct command. If the input is not valid, then the function
   repeats. Note the entire function may not run if the TA has already moved
   for the turn.
** Parameters: the row and column of the TA.
** Pre-Conditions: the TA is identified in the maze.
** Post-Conditions: the correct move command is given to the TA.
*********************************************************************/ 
void Maze::get_TA_move(int i, int j){
    char move;
    if(!people[i][j]->get_has_moved()){
        while(true){
            move = people[i][j]->get_move();
                if(evaluate_TA_move(move, i, j)){
                    return;
            }
        }
    }
}

/*********************************************************************
** Function: void Maze::play_TA_moves()
** Description: plays the move for every TA on the board.
** Parameters: none
** Pre-Conditions: the student has made their move.
** Post-Conditions: all three TAs make their moves.
*********************************************************************/ 
void Maze::play_TA_moves(){
    for(int i = 0; i < this->locations.size(); i++){
        for(int j = 0; j < this->locations.size(); j++){
            if(locations[i][j]->get_TA_char() == 'T'){
                for(int k = 0; k < locations[i][j]->get_num_TA(); k++){
                    get_TA_move(i, j);
                }
            }
        }
    }
    // resets all TAs move status to false for the next turn.
    for(int i = 0; i < this->locations.size(); i++){
        for(int j = 0; j < this->locations.size(); j++){
            if(locations[i][j]->get_TA_char() == 'T'){
                people[i][j]->set_has_moved(false);
            }
        }
    }
}

/*********************************************************************
** Function: void Maze::play_move(int &acquired_skills, int &appeasement_level)
** Description: plays the moves of the student and the three TAs.
** Parameters: references to the acquired skills in hand and the number of
   moves left to appease the TAs.
** Pre-Conditions: no conditions were met to end the game.
** Post-Conditions: every person except the instructor has moved on the
   board.
*********************************************************************/ 
void Maze::play_move(int &acquired_skills, int &appeasement_level){
    cout << "Programming skills left: " << acquired_skills << endl;
    cout << "Moves left to appease TAs: " << appeasement_level << endl;
    play_student_move(acquired_skills, appeasement_level);
    play_TA_moves();
    if(appeasement_level != 0){
        appeasement_level = appeasement_level - 1;
    }
}

/*********************************************************************
** Function: Maze::~Maze()
** Description: destroys all dynamically allocated memory in the maze
   and people vectors.
** Parameters: None
** Pre-Conditions: the game is over, and the student quits the game.
** Post-Conditions: Game Over
*********************************************************************/ 
Maze::~Maze(){
    for(int i = 0; i < this->locations.size(); i++){
        for(int j = 0; j < this->locations[i].size(); j++){
            delete this->locations[i][j];
        }
    }
    for(int i = 0; i < this->people.size(); i++){
        for(int j = 0; j < this->people[i].size(); j++){
            if(people[i][j] != NULL){
                delete people[i][j];
            }
        }
    }
}