#include "Dice.h"

int rollDice(int face, bool output) {
    char c;
    if (output) cout << "Press Enter to roll a dice: ";
    while ((c = getchar()) != '\n') {}
    int res = rand() % face + 1;
    if (output) cout << "You rolled " << res << "! (D" << face << ")" << endl;
    return res;
}