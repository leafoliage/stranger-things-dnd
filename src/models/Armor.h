#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

class Armor: public Item {
    private:

    public:
        Armor();
        Armor(string name, int hardness, int visibility);

        int useHardness(Player*);
        bool triggerEvent(Object*);
};

#endif // ARMOR_H_INCLUDED