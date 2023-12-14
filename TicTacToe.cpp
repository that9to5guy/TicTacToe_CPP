#include<iostream>
#include<string>
#include "TicTacToe.h"

using std::cout;
using std::endl;

GameBoard::GameBoard() {
    cout << "Tic~Tac~Toe " <<endl<<endl;
}

void GameBoard::print_board() const {
    for(int i=0;i<3;i++) {
        cout<< " "<<board[i][0]<<" | "<<board[i][1]<<" | "<<board[i][2]<<" " << endl;
        if(i<2) {
                cout << "---|---|---" << endl;
        }
    }
}

void GameBoard::update_board(char input, bool playerTurn) {
    char setSymb;
    setSymb = playerTurn ? 'X' : '0' ;

    // Update the Board with Player Input
    if(input < 'd') {
        board[0][input-'a'] = setSymb;
    }
    else if (input < 'g') {
        board[1][input-'d'] = setSymb;
    }
    else {
        board[2][input-'g'] = setSymb;
    }

    //Update the vector for CPU input
    cpuIn.erase(std::remove(cpuIn.begin(),cpuIn.end(),input),cpuIn.end());
}

void GameBoard::cpu_play() {
    int rIndex = std::rand() % cpuIn.size();
    chV.push_back(cpuIn[rIndex]);
    cout << endl << "CPU chose to put 0 : " << cpuIn[rIndex] << endl;
    update_board(cpuIn[rIndex],false);
}

bool GameBoard::player_move(char input) {
    if(!(find(chV.begin(),chV.end(),input)!=chV.end())) {
        chV.push_back(input);
        return true;
    }
    else {
        return false;
    }
}

bool GameBoard::is_winner(bool player) const{
    char setSymb;
    setSymb = player ? 'X' : '0' ;
    for(int i=0; i<3; i++) {
        if(board[i][0]==setSymb && board[i][1]==setSymb && board[i][2]==setSymb) {
            return true;
        }
        if(board[0][i]==setSymb && board[1][i]==setSymb && board[2][i]==setSymb) {
            return true;
        }
    }
    if(board[0][0]==setSymb && board[1][1]==setSymb && board[2][2]==setSymb) {
        return true;
    }
    if(board[0][2]==setSymb && board[1][1]==setSymb && board[2][0]==setSymb) {
        return true;
    }
    
    return false;
}
