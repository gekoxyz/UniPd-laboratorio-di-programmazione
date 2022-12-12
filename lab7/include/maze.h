/*
    Class Maze: represents the maze, manages the file read, and gives functions
    to navigate the maze itself
*/

#ifndef MAZE_H
#define MAZE_H

#include "position.h"

#include <string>
#include <vector>
#include <algorithm>

class maze {
    public:
    // maze.txt is the default maze, specify a new maze if you want a new maze
    maze(std::string filename = "./../assets/maze.txt");
    std::vector<position> possible_moves();
    bool cell_reachable(char cell);
    void move(position p);
    void print_maze();
    bool finished() { return current_ == end_; }
    position current() { return current_; }
private:
    std::string filename_;
    std::vector<std::vector<char>> maze_;
    position start_;
    position end_;
    position current_;
    int row_size_;
    int col_size_;
};

#include "maze.hpp"

#endif