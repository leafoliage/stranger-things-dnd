#include "Armor.h"

Armor::Armor() {}

Armor::Armor(string name, int hardness, int visibility):
    Item(name, ARMOR, hardness, visibility) {}