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
        Weapon(string name, int weaponType, int quality, int price);

        int useQuality(GameCharacter* user);
        void workOn(GameCharacter* target, GameCharacter* user);
        bool triggerEvent(Object*);
        int getType();

        void setWeaponType(int);
        int getWeaponType();
};

#endif // WEAPON_H_INCLUDED