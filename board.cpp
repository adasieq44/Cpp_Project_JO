#include "board.h"

Board::Board() {
    reset();
}

void Board::reset() {
    grid = vector<vector<char>>(3, vector<char>(3, ' '));
}

bool Board::makeMove(int row, int col, char symbol) {
    if (row<0 || row>2 || col<0 || col>2)
        return false;
    if (grid[row][col] != ' ')
        return false;

    grid[row][col] = symbol;
    return true;
}

bool Board::isCellEmpty(int row, int col) const {
    if (row<0 || row>2 || col<0 || col>2) return false;
    return grid[row][col] == ' ';
}

bool Board::isFull() const {
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            if (grid[i][j] == ' ') return false;
        }
    }
    return true;
}

char Board::checkWinner() const {
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) return grid[i][0];
        if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) return grid[0][i];
    }
    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) return grid[0][0];
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) return grid[0][2];
    return ' ';
}

ostream& operator<<(ostream& os, const Board& board) {
    os << "\n   0   1   2\n";
    for (int i = 0; i < 3; ++i) {
        os << i << ' ';
        for (int j = 0; j < 3; ++j) {
            os << '[' << board.grid[i][j] << ']';
            if (j < 2) os << ' ';
        }
        os << "\n";
    }
    os << "\n";
    return os;
}