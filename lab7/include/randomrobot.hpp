#ifndef RANDOMROBOT_HPP
#define RANDOMROBOT_HPP

position randomrobot::move(maze &maze) {
    // call for available move
    std::vector<position> possible_moves = maze.possible_moves();
    return position(0,0);
}

#endif