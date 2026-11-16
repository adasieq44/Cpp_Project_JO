#pragma once
#include "board.h"
#include "player.h"

class Game {
    Board board;
    Player* player1;
    Player* player2;
    Player* currentPlayer;
    public:
        Game(Player* p1, Player* p2);
        void play();
};