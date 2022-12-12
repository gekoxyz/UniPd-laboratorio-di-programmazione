/*
    Class Maze: represents the maze, manages the file read, and gives functions
    to navigate the maze itself
*/

#ifndef MAZE_H
#define MAZE_H

#include "position.h"

#include <string>
#include <vector>

class maze {
    public:
    // maze.txt is the default maze, specify a new maze if you want a new maze
    maze(std::string filename = "./../assets/maze.txt");
    std::vector<position> possible_moves();
    void move(position p) { current_ = p; } // TODO: CHECK THAT P IS AN ELEMENT OF possible_moves()
    void print_maze();
    bool finished() { return current_ == end_; }
    position current() { return current_; }

private:
    std::string filename_;
    std::vector<std::vector<char>> maze_;
    position start_;
    position end_;
    position current_;
};

#include "maze.hpp"

#endif