#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "=========================================\n";
    cout << "       PROJEKT: KÓŁKO I KRZYŻYK (C++)    \n";
    cout << "=========================================\n";
    cout << "Wybierz tryb rozgrywki:\n";
    cout << "1. Gracz vs Gracz\n";
    cout << "2. Gracz vs Komputer\n";

    int choice = 0;
    while (true) {
        cout << "Twój wybór (1 lub 2): ";
        if (cin >> choice && (choice == 1 || choice == 2)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        if (cin.eof()) {
            cout << "\nPrzerwano działanie programu.\n";
            return 0;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny wybór. Wpisz 1 lub 2.\n";
    }

    char sym1 = 'X';
    string symInput;
    while (true) {
        cout << "Gracz 1 - wybierz symbol (X lub O): ";
        if (cin >> symInput) {
            if (symInput == "X" || symInput == "x") {
                sym1 = 'X';
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            if (symInput == "O" || symInput == "o") {
                sym1 = 'O';
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        if (cin.eof()) {
            cout << "\nPrzerwano działanie programu.\n";
            return 0;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny symbol. Wpisz X lub O.\n";
    }

    char sym2 = (sym1 == 'X') ? 'O' : 'X';

    Player* p1 = new playerHuman(sym1, "Gracz 1");
    Player* p2 = nullptr;

    if (choice == 2) {
        p2 = new playerAI(sym2, "Komputer");
    } else {
        p2 = new playerHuman(sym2, "Gracz 2");
    }

    cout << p1->getName() << " gra jako: " << p1->getSymbol()
         << " | " << p2->getName() << " gra jako: " << p2->getSymbol() << "\n";

    if (*p1 == *p2) {
        cout << "[Info]: Gracze posiadają identyczne symbole.\n";
    } else {
        cout << "[Info]: Gracze posiadają różne symbole.\n";
    }

    Game game(p1, p2);
    game.play();

    delete p1;
    delete p2;

    cout << "\nNaciśnij Enter, aby zamknąć program...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}