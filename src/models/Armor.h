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
        Armor(string name, int quality, int price);

        int useQuality(GameCharacter* user);
        void workOn(GameCharacter* target, GameCharacter* user);
        bool triggerEvent(Object*);
};

#endif // ARMOR_H_INCLUDED