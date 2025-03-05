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

bool CheckSmallWin(char board[9][9], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player
            && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player
            && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;


}

