/*
    manages the interactions between robots and maze
*/
#include <iostream>
#include <vector>

#include "./../include/maze.h"

using namespace std;

int main() {
    // TODO: parse input matrix
    // * -> not reachable
    // E -> exit, where the robot exits
    // S -> start, where the robot starts
    vector<position> possible_moves;
    maze maze("maze.txt");
    possible_moves = maze.possible_moves();
    for(auto move: possible_moves) {
        cout << move.to_string() << endl; 
    }
    cout << endl;
    return 0;
}