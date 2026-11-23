#include "game.h"
#include <iostream>
#include <stdexcept>

Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2), currentPlayer(p1) {}

void Game::play() {
    board.reset();
    currentPlayer = player1;
    char winner = ' ';

    while (!board.isFull() && winner == ' ') {
        cout << board;
        cout << "Teraz gra: " << currentPlayer->getSymbol()
             << " [" << currentPlayer->getName() << "]\n";

        int row = -1, col = -1;
        try {
            currentPlayer->makeMove(board, row, col);

            if (!board.makeMove(row, col, currentPlayer->getSymbol())) {
                throw runtime_error("Nie udało się wykonać ruchu!");
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << " Spróbuj ponownie.\n";
            continue;
        } catch (const out_of_range& e) {
            cout << e.what() << " Spróbuj ponownie.\n";
            continue;
        } catch (const logic_error& e) {
            cout << e.what() << " Spróbuj ponownie.\n";
            continue;
        } catch (const exception& e) {
            cout << "[WYJĄTEK]: " << e.what() << "\n";
            if (cin.eof()) {
                return;
            }
            cout << "Spróbuj ponownie.\n";
            continue;
        }

        winner = board.checkWinner();
        if (winner == ' ') {
            currentPlayer = (currentPlayer == player1) ? player2 : player1;
        }
    }

    cout << "Koniec gry!\n" << board;
    if (winner != ' ') {
        cout << "Zwycięstwo! Wygrywa: " << winner << " [" << currentPlayer->getName() << "]!\n";
    } else {
        cout << "Remis!\n";
    }
}