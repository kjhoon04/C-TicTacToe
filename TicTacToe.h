#include <iostream>
#define TICTACTOE_H

class TicTacToe {
private:
    char board[3][3]; // 3x3 보드
    char currentPlayer; // 현재 플레이어 (X 또는 O)

public:
    TicTacToe(); // 생성자
    void initializeBoard(); // 보드를 초기화하는 함수
    void printBoard(); // 보드를 출력하는 함수
    void makeMove(); // 플레이어의 입력을 처리하는 함수
    char checkWinner(); // 게임의 승자를 확인하는 함수
    bool isGameOver(); // 게임이 종료되었는지 확인하는 함수
    bool isBoardFull(); // 보드가 모두 채워졌는지 확인하는 함수
};
