#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
#include "Item.h"
#include "enums.h"
using namespace std;

class Weapon: public Item {
    private:
        WeaponType weaponType;

    public:
        Weapon();
        Weapon(string, WeaponType, int, int);
        int useHardness();

        void setWeaponType(WeaponType);
        WeaponType getWeaponType();
};

#endif // WEAPON_H_INCLUDED