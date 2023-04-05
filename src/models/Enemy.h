#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"

using namespace std;

class Enemy: public GameCharacter
{
private:
    Weapon* weapon;
public:
    Enemy();
    Enemy(string name, Weapon* weapon, int strength, int dexterity, int constitution, int wisdom);

    /* Virtual function that you need to complete   */
    /* In Enemy, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);
    Item* getWeapon();
};


#endif // ENEMY_H_INCLUDED
