#ifndef RANDOMROBOT_HPP
#define RANDOMROBOT_HPP

void randomrobot::move(maze &maze) {
    // call for available move
    std::cout << "CALLED MOVE OF RANDOMROBOT" << std::endl;
    std::vector<position> possible_moves = maze.possible_moves();
    if (possible_moves.size() > 0) {
        // choose a move randomly
        short moves_number = possible_moves.size();
        for (auto m : possible_moves) {
            std::cout << m.to_string() << ", ";
        }
        std::cout << "available moves: " << moves_number << std::endl;
        short random_move = rand() % moves_number;
        std::cout << "chose move: " << random_move << std::endl;
        // moving to the chosen position
        maze.move(possible_moves.at(random_move));
    }
}

#endif