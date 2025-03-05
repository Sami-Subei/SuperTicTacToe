//
// Created by Sami Subei on 2/12/25.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#endif //FUNCTIONS_H
#include <iostream>
#include <unistd.h>
using namespace std;

void SlowPrint(const string &text, int delay) {
    for(char c : text) {
        cout << c;
        cout.flush();
        usleep(delay);
    }
}
void initializeBoard(char board[9][9]) {
    for(int row= 0; row < 9; row++) {
        for(int col=0; col < 9; col++) {
            board[row][col]='.';
        }
    }
}
void BoardPrint(const char board[9][9]) {
    for(int row = 0; row < 9; row++) {
        if(row % 3 == 0 && row != 0) {
            cout << "-------+-------+--------\n";
        }
        for(int col = 0; col < 9; col++) {
            if(col % 3 == 0 && col != 0) {
                cout << " | ";
            }
            cout << board[row][col] << " ";

        }


        cout << endl;

    }

}

bool makemove(char board[9][9], int inp_row, int inp_col, char player) {
    if(inp_row < 0 || inp_row >= 9 || inp_col < 0 || inp_col >= 9 || board[inp_row][inp_col] != '.') {
        return false;
    }
    board[inp_row][inp_col] = player;
    return true;
}

bool CheckSmallWin(char board[9][9], char player, int box) {

        int rowOffset = box / 3 * 3;
        int colOffset = box % 3 * 3;

    for (int i = 0; i < 3; i++) {
        if (board[rowOffset + i][colOffset] == player && board[rowOffset+ i][colOffset + 1] == player
            && board[rowOffset + i][colOffset + 2] == player)
           goto win;
        if (board[rowOffset][colOffset+ i] == player && board[rowOffset + 1][colOffset+ i] == player
            && board[rowOffset + 2][colOffset + i] == player)
            goto win;
    }
    if (board[rowOffset][colOffset] == player && board[rowOffset + 1][colOffset + 1] == player && board[rowOffset + 2][colOffset + 2] == player)
        goto win;
    if (board[rowOffset][colOffset + 2] == player && board[rowOffset + 1][colOffset + 1] == player && board[rowOffset + 2][colOffset] == player)
        goto win;

    return false;

    win:
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[rowOffset + i][colOffset + j] = player;
        }
    }
    return true;

}

bool CheckWin(char bigBoard[9], char player) {

    for(int i = 0; i < 3; i++) {
        if(bigBoard[i * 3] == player && bigBoard[i * 3 + 1] == player && bigBoard[i * 3 + 2] == player)
            return true;
    }
    for(int j = 0; j < 3; j++) {
        if(bigBoard[j] == player && bigBoard[j + 3] == player && bigBoard[j + 6])
            return true;


    }

    if (bigBoard[0] == player && bigBoard[4] == player && bigBoard[8] == player)
        return true;
    if (bigBoard[2] == player && bigBoard[4] == player && bigBoard[6] == player)
        return true;

    return false;

}