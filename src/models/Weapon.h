#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

class Weapon: public Item {
    private:
        int weaponType;

    public:
        Weapon();
        Weapon(string name, int weaponType, int hardness, int visibility);

        int useHardness(Player*);
        bool triggerEvent(Object*);

        void setWeaponType(int);
        int getWeaponType();
};

#endif // WEAPON_H_INCLUDED