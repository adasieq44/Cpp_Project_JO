#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Board {
    vector<vector<char>> grid;
    public:
        Board();
        void reset();
        bool makeMove(int row, int col, char symbol);
        bool isCellEmpty(int row, int col) const;
        bool isFull() const;
        char checkWinner() const;

        friend ostream& operator<<(ostream& os, const Board* board);
};
