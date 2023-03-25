#include <iostream>
#include <string>
#include "Object.h"
#include "Item.h"
#include "enums.h"

Armor::Armor() {}

Armor::Armor(string name, int hardness, int visibility):
    Item(name, ARMOR, hardness, visibility) {}