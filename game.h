/*********************************************************************
** Program Filename: game.h
** Author: Anthony Silva
** Date: 03-06-2023
** Description: serves as the header file for the Game class.
*********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "maze.h"

using namespace std;

class Game{
    private:
        Maze m;
    public:
        bool check_side(string width);
        int get_side();
        void set_up();
        void play_game();
        int check_to_play_again();
};

#endif