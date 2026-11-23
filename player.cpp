#include "player.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

Player::Player(char sym, string n) : symbol(sym), name(n) {}

char Player::getSymbol() const {
    return symbol;
}
string Player::getName() const {
    return name;
}

bool Player::operator==(const Player& other) const {
    return this->symbol == other.symbol;
}

playerHuman::playerHuman(char sym, string n) : Player(sym, n) {}

void playerHuman::makeMove(Board& board, int& row, int& col) {
    cout << "Podaj wiersz (0-2) i kolumnę (0-2): ";

    if (!(cin >> row >> col)) {
        if (cin.eof()) {
            throw runtime_error("Przerwano strumień wejściowy");
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Wprowadź poprawne liczby!");
    }

    if (row < 0 || row > 2 || col < 0 || col > 2) {
        throw out_of_range("Podaj współrzędne na planszy (0-2)!");
    }

    if (!board.isCellEmpty(row, col)) {
        throw logic_error("To pole jest już zajęte! Nie możesz tutaj postawić symbolu.");
    }
}

playerAI::playerAI(char sym, string n) : Player(sym, n) {}

void playerAI::makeMove(Board& board, int& row, int& col) {
    if (board.isFull()) {
        throw runtime_error("Brak wolnych pól na planszy!");
    }
    do {
        row = rand()%3;
        col = rand()%3;
    } while (!board.isCellEmpty(row, col));

    cout << name << " wybiera pole: " << row << " " << col << "\n";
}