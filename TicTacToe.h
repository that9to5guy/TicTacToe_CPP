#pragma once
#include <string>
#include <vector>

class GameBoard {
    private:
        char board[3][3] {'a','b','c','d','e','f','g','h','i'};
        std::vector<char> cpuIn {'a','b','c','d','e','f','g','h','i'};
        std::vector<char> chV;
    public:
        GameBoard();
        
        void print_board() const;

        void update_board(char input, bool playerTurn);

        void cpu_play();

        bool player_move(char input);

        bool is_winner(bool player) const;
};