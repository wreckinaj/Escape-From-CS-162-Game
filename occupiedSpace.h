#ifndef OCCUPIEDSPACE_H
#define OCCUPIEDSPACE_H

#include "mazeLocation.h"
#include "mazePerson.h"
#include "intrepidStudent.h"

using namespace std;

class StudentSpace : public MazeLocation{
    private:
        IntrepidStudent S;
    public:
        StudentSpace();
};