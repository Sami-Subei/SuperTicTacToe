#include <iostream>
#include "function.h"
using namespace std;

bool makemove();
bool CheckSmallWin(char board[9][9], char player, int box);
bool CheckWin(char bigBoard[9], char player);


int main()
{
    char board[9][9];
    char bigBoard[9];
    bool gamerunning = false;
    int turn = 1;
    initializeBoard(board);
    int menu_choice;
    SlowPrint("-----------Welcome to Sami's -----------", 50000);
    cout << endl;
    SlowPrint("--------Super TicTacToe Project!--------", 50000);
    cout << endl;
    SlowPrint("1. Start", 50000);
    cout << endl;
    SlowPrint("2. Rules?", 50000);
    cout << endl;
    cin >> menu_choice;


    if(menu_choice == 2) {
        SlowPrint("1. Players X and O alternate turns, starting with X.\n", 50000);
        SlowPrint("2. X chooses any position across the board to start.\n", 50000);
        SlowPrint("3. O must play in the gameboard corresponding to the position chosen by X.\n ", 50000);
        SlowPrint("Example: If X plays in Box A, position 3, O must play in Box C.\n", 50000);
        SlowPrint("4. Players continue directing each other to specific gameboards based on their moves.\n", 50000);
        SlowPrint("5. Winning a small Box (three in a row) claims the Box for the player.\n", 50000);
        SlowPrint("6. Once a Box is won or filled, players sent there may play anywhere on the board.\n", 50000);
        SlowPrint( "7. The game ends when a player wins three Boxes in a row or no legal moves remain, resulting in a draw.\n", 50000);
        cout << endl;
        cout << "Would you like to start the game?\n";
        cout << "Enter (1) to start the game: ";
        cin >> menu_choice;
    }
    if(menu_choice == 1) {

        gamerunning = true;


    }

    while(gamerunning) {
        char player1 = 'X', player2 = 'O', player;
        BoardPrint(board);

        int inp_row, inp_col;
        cout << "Enter a row and column:";
        cin >> inp_row >> inp_col;
        if(turn % 2 == 1) {
            player = player1;
            cout << "It is player " << player <<"'s turn!\n";
        } else {
            player = player2;
            cout << "It is currently " << player << " turn!\n";
        }

        if (!makemove(board, inp_row, inp_col, player)) {
            cout << "Invalid move! Try again.\n";
            continue; // Skip to next iteration
        }
        if(makemove(board,inp_row,inp_col,player)) {
            BoardPrint(board);
            continue;
        }




        for(int box = 0; box < 9; box++) {
            if(CheckSmallWin(board, player, box)) {
                bigBoard[box] = player;

                if(CheckWin(bigBoard, player)) {
                    cout << "Player" << player << " wins the game!!!" << endl;
                    BoardPrint(board);
                    gamerunning = false;
                    break;
                }

                }
            }




        turn += 1;


    }

    return 0;
}
