/*
    manages the interactions between robots and maze
*/
#include <iostream>
#include <vector>

#include "./../include/maze.h"
#include "./../include/randomrobot.h"

using namespace std;

int main() {
    cout << "creating maze object" << endl;
    maze maze("maze.txt");

    cout << "possible moves:" << endl;
    vector<position> possible_moves;
    possible_moves = maze.possible_moves();
    for(auto move: possible_moves) {
        cout << move.to_string() << endl; 
    }

    cout << "creating random robot" << endl;
    randomrobot randomrobot;
    cout << "calling move of randomrobot" << endl;
    while (!maze.finished()) {
        randomrobot.move(maze);
        maze.print_maze();
    }
    cout << "FINISHED MAZE!" << endl;
    return 0;
}