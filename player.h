#pragma once
#include "board.h"
#include <string>

using namespace std;

class Player {
    public:
        Player(char sym, string n);
        virtual ~Player() {}
        char getSymbol() const;
        string getName() const;
        virtual void makeMove(Board& board, int& row, int& col) = 0;
        bool operator==(const Player& other) const;
    protected:
        char symbol;
        string name;
};

class playerHuman : public Player {
    public:
        playerHuman(char sym, string n);
        void makeMove(Board& board, int& row, int& col) override;
};

class playerAI : public Player {
    public:
        playerAI(char sym, string n);
        void makeMove(Board& board, int& row, int& col) override;
};