#include "game.h"
#include <iostream>
#include <optional>

using namespace std;

void Game::play() {
    //Figure out first and second player's letters
    char players[2] = {'X', 'Y'};
    //Alternate between the two
    int toMove = 1;
    optional<bool> res = {};
    int col=-1;
    do {
        toMove = 1-toMove;
        b.printBoard();
        cin >> col;
        while(!b.canMakeMove(players[toMove], col-1)) {
            cin >> col;
        }
        res = b.makeMove(players[toMove], col-1);
    }while(!res.has_value());
    b.printBoard();
    congratulate(*res?optional<char>(players[toMove]):optional<char>());
}

void Game::congratulate(optional<char> side) {
    if(side) {
        cout << *side << " wins";
    } else {
        cout << "draw";
    }
}