/*
    Class Maze: represents the maze, manages the file read, and gives functions
    to navigate the maze itself
*/

#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <iostream>
#include <fstream>
class position {
public:
    position() {}
    position(int x, int y) {
        x_ = x;
        y_ = y;
    }
    int x() { return x_; }
    int y() { return y_; }

private:
    int x_;
    int y_;
};

class maze {
    public:
    // maze.txt is the default maze, specify a new maze if you want a new maze
    maze(std::string filename = "./../assets/maze.txt");

    private:
    std::string filename_;
    char maze_[9][9];
    position start_;
    position end_;
};

#include "maze.hpp"

#endif