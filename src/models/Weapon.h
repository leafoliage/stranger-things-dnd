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
        Weapon(string, int, int, int);

        int useHardness();
        bool triggerEvent(Object*);

        void setWeaponType(int);
        int getWeaponType();
};

#endif // WEAPON_H_INCLUDED