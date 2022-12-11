/*
    class robot: represents a robot, implements the virtual function move that 
    accepts an argument of type maze& that manages the movement of the robot
    based on the specific robot, managed in the apposite derivated classes
*/
#ifndef ROBOT_H
#define ROBOT_H

#include "maze.h"
#include "position.h"

class robot {
public:
    virtual void move(maze &maze) = 0;

private:
};
#endif