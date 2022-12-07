#ifndef MAZE_HPP
#define MAZE_HPP

maze::maze(std::string filename) {
    // parsing maze and getting start and end position
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
    maze_reader.close();
    
    std::cout << "PARSED MAZE" << std::endl;
    std::cout << "START: " << start_.x() << " " << start_.y() << std::endl;
    std::cout << "END: " << end_.x() << " " << end_.y() << std::endl;
    // maze number of rows and columns
    std::cout << sizeof(maze_)/sizeof(maze_[0]) << std::endl;
    std::cout << sizeof(maze_[0])/sizeof(char) << std::endl;
    // print
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << maze_[i][j];
        }
        std::cout << std::endl;
    }
    // TODO: separate method for parsing
    // TODO: method for printing maze
}

#endif