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
    Enemy(string name, vector<string> script, int hp, const int abilities[4], Skill skill);
    Enemy(string name, Weapon* weapon, int strength, int dexterity, int constitution, int wisdom);

    /* Virtual function that you need to complete   */
    /* In Enemy, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);
    Item* getWeapon();
    void setWeapon(Weapon*);
};


#endif // ENEMY_H_INCLUDED
