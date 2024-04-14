#include "TicTacToe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe() : currentPlayer('X') {}

void TicTacToe::initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::printBoard() {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void TicTacToe::makeMove() {
    int row, col;
    cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
    cin >> row >> col;

    if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = currentPlayer;
    }
    else {
        cout << "Invalid move! Try again." << endl;
        makeMove();
        return;
    }

    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

char TicTacToe::checkWinner() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

bool TicTacToe::isGameOver() {
    if (checkWinner() != ' ' || isBoardFull()) {
        return true;
    }
    return false;
}

bool TicTacToe::isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
