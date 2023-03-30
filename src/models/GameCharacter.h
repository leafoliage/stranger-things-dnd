#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
using namespace std;

class GameCharacter: public Object
{
private:
    int characterType;
    int maxHp;
    int currHp;
    int strength;
    int dexterity;
    int constitution;
    int wisdom;
public:
    GameCharacter();
    GameCharacter(string name, int characterType, int maxHp, int currHp, int strength, int dexterity, int constitution, int wisdom);

    virtual void attack(GameCharacter* rival, Item* equipment);
    virtual int armorClass();

    bool checkIsDead();
    int takeDamage(int);
    int abilityCheck(int ability);
    int hitCheck(Item* equipment);

    /* Set & Get function*/
    void setCharacterType(int);
    void setMaxHp(int);
    void setCurrHp(int);
    void setStrength(int);
    void setDexterity(int);
    void setConstitution(int);
    void setWisdom(int);
    int getCharacterType() const;
    int getMaxHp() const;
    int getCurrHp() const;
    int getStrength() const;
    int getDexterity() const;
    int getConstitution() const;
    int getWisdom() const;
};
#endif // GAMECHARACTER_H_INCLUDED
