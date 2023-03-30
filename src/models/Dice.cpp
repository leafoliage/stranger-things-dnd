#include "Dice.h"

int rollDice(int face) {
    return rand() % face + 1;
}