/*
    derivated from robot, manages a robot that makes random movements
    in the 8 cells near the current position
*/

#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H

#include <cstdlib>
#include <ctime>

#include "robot.h"

class randomrobot : public robot {
public:
    randomrobot() { srand((unsigned)time(NULL)); }
    void move(maze &maze);

private:
};

#include "randomrobot.hpp"

#endif