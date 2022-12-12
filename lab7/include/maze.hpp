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
    // max size of vector is long unsigned int and this is int so there's a possible (unlikely) narrowing
    int row_index = 0;
    while(std::getline(maze_reader, maze_line)) {
        std::vector<char> line_container; 
        for (int col_index = 0; col_index < maze_line.length(); col_index++) {
            line_container.push_back(maze_line.at(col_index));
            if (maze_line.at(col_index) == 'S') start_ = position{row_index, col_index};
            if (maze_line.at(col_index) == 'E') end_ = position{row_index, col_index};
        }
        maze_.push_back(line_container);
        row_index++;
    }
    current_ = start_;
    maze_reader.close();
    print_maze();
}

// analyze current position and return possible moves by checking current_'s surrounding cells
std::vector<position> maze::possible_moves() {
    std::vector<position> possible_moves;
    int row = current_.x(); // the x position is the row index
    int col = current_.y(); // the y position is the col index 
    // i need to check if right is a good position (NOT OUT OF BOUNDS and reachable)
    // currently the only obstacle is the wall (*) , so the algorithm just checks
    // that you are not going into a wall

    // TODO: IMPLEMENT IN A GENERIC WAY

    if (col + 1 <= maze_[row].size()) {
        char cell = maze_[row][col + 1]; // next column same row -> right
        if (cell != '*') {
            position right(row, col + 1);
            possible_moves.push_back(right);
        }
    }

    if (row - 1 >= 0 && col + 1 <= maze_[row].size()) {
        char cell = maze_[row - 1][col + 1]; // prev row next column -> top right
        if (cell != '*') {
            position top_right(row - 1, col + 1);
            possible_moves.push_back(top_right);
        }
    }

    if (row + 1 <= maze_.size() && col + 1 <= maze_[row].size()) {
        char cell = maze_[row + 1][col + 1]; // next row next column -> bottom right
        if (cell != '*') {
            position bottom_right(row + 1, col + 1);
            possible_moves.push_back(bottom_right);
        }
    }

    if (col - 1 >= 0) {
        char cell = maze_[row][col - 1]; // prev column same row -> left
        if (cell != '*'){
            position left(row, col - 1);
            possible_moves.push_back(left);
        }
    }

    if (row - 1 >= 0 && col - 1 >= 0) {
        char cell = maze_[row - 1][col - 1]; // prev row prev col -> top left 
        if (cell != '*') {
            position top_left(row - 1, col - 1);
            possible_moves.push_back(top_left);
        }
    }

    if (row + 1 <= maze_.size() && col - 1 >= 0) {
        char cell = maze_[row + 1][col - 1]; // next row prev col -> bottom left
        if (cell != '*') {
            position bottom_left(row + 1, col - 1);
            possible_moves.push_back(bottom_left);
        }
    }

    if (row + 1 <= maze_.size()) {
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
    for (short i = 0; i < maze_.size(); i++) {
        for (short j = 0; j < maze_[0].size(); j++) {
            if (position(i, j) == current_)
                std::cout << 'C';
            else
                std::cout << maze_[i][j];
        }
        std::cout << std::endl;
    }
}

#endif