#include "TicTacToe.h"
#include <iostream>

using namespace std;

int main() {
    TicTacToe game;
    game.initializeBoard();

    while (!game.isGameOver()) {
        game.printBoard();
        game.makeMove();
    }

    game.printBoard();

    char winner = game.checkWinner();
    if (winner == ' ') {
        cout << "It's a draw!" << endl;
    }
    else {
        cout << "Player " << winner << " wins!" << endl;
    }

    return 0;
}
