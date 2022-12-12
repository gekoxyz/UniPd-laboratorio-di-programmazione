#ifndef RANDOMROBOT_HPP
#define RANDOMROBOT_HPP

void randomrobot::move(maze &maze) {
    // call for available move (i always have an available move except if the start position is trapped)
    // TODO: check if start position is trapped
    std::vector<position> possible_moves = maze.possible_moves();
    if (possible_moves.size() > 0) {
        // choose a move randomly, moves_number is short because you have only 8 possible moves
        short moves_number = possible_moves.size();
        short random_move = rand() % moves_number;
        // moving to the chosen position
        maze.move(possible_moves.at(random_move));
    }
}

#endif