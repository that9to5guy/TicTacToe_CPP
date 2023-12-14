#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include "TicTacToe.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::find;

int main()
{
    char input;
    int turns=0;
    GameBoard Tic1;
    Tic1.print_board();

    std::srand(static_cast<unsigned int>(std::time(0)));

    while(1) {
        // Player 1 turn
        while(1) {
            cout<<endl<<"Select a Valid Square to put X : ";
            cin >> input;
            if(input >= 'a' && input <= 'i'&& Tic1.player_move(input)) {
                cout << endl;
                Tic1.update_board(input,true);
                Tic1.print_board();
                turns++;
                break;
            }
        }
        // Check if Player Won ?
        if(Tic1.is_winner(true)) {
            cout << "!!! W I N N E R !!!" << endl;
            return 0;
        }

        //CPU turn
        if(turns<9) {
            Tic1.cpu_play();
            cout << endl;
            Tic1.print_board();
            turns++;
        }
        else {
            break;
        }

        // Check if CPU Won ?
        if(Tic1.is_winner(false)) {
            cout << "!!! L O S E R !!!" << endl;
            return 0;
        }
    }

    cout << endl << "!!! Match Draw !!!" << endl;

    return 0;
}