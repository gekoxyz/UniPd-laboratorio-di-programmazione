#ifndef MAZE_HPP
#define MAZE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

maze::maze(std::string filename) {
    // parsing maze and getting start and end position
    // at the start Current position = start position
    filename_ = "./assets/" + filename;
    std::string maze_line;
    std::ifstream maze_reader(filename_);
    int row_index = 0;
    while(std::getline(maze_reader, maze_line)) {
        for (int col_index = 0; col_index < maze_line.length(); col_index++) {
            maze_[row_index][col_index] = maze_line.at(col_index);
            if (maze_line.at(col_index) == 'S') start_ = position{row_index, col_index};
            if (maze_line.at(col_index) == 'E') end_ = position{row_index, col_index};
        }
        row_index++;
    }
    current_ = start_;
    maze_reader.close();
}

std::vector<position> maze::possible_moves() {
    std::vector<position> possible_moves;
    // analyze current position and return possible moves by checking current_'s surrounding cells
    int row = current_.x(); // the x position is the row index
    int col = current_.y(); // the y position is the col index 
    // i need to check if right is a good position (NOT OUT OF BOUNDS and reachable)
    // currently the only obstacle is the wall (*) , so the algorithm just checks
    // that you are not going into a wall
    if (col + 1 <= 9) {
        char cell = maze_[row][col + 1]; // next column same row -> right
        if (cell != '*') {
            position right(row, col + 1);
            possible_moves.push_back(right);
        }
    }
    if (col - 1 >= 0) {
        char cell = maze_[row][col - 1]; // prev column same row -> left
        if (cell != '*'){
            position left(row, col - 1);
            possible_moves.push_back(left);
        }
    }
    if (row + 1 <= 8) {
        char cell = maze_[row + 1][col]; // same column next row -> down
        if (cell != '*') {
            position down(row + 1, col);
            possible_moves.push_back(down);
        }
    }
    if (row - 1 >= 0) {
        char cell = maze_[row - 1][col]; // same column prev row -> up
        if (cell != '*') {
            position up(row - 1, col);
            possible_moves.push_back(up);
        }
    }
    return possible_moves;
}

void maze::print_maze() {
    short row_index = sizeof(maze_)/sizeof(maze_[0]);
    short col_index = sizeof(maze_[0])/sizeof(char);
    for (short i = 0; i < row_index; i++) {
        for (short j = 0; j < col_index; j++) {
            if (position(i, j) == current_) {
                std::cout << 'C';
            } else {
                std::cout << maze_[i][j];
            }
        }
        std::cout << std::endl;
    }
}

#endif