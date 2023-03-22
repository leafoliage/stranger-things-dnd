#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
private:
    CharacterType characterType;
    int maxHp;
    int currHp;
    int strength;
    int dexterity;
    int constitution;
    int wisdom;
public:
    GameCharacter();
    GameCharacter(string,ObjectType,CharacterType,int,int,int,int,int,int);
    bool checkIsDead();
    int takeDamage(int);

    /* Set & Get function*/
    void setCharacterType(CharacterType);
    void setMaxHp(int);
    void setCurrHp(int);
    void setStrength(int);
    void setDexterity(int);
    void setConstitution(int);
    void setWisdom(int);
    CharacterType getCharacterType() const;
    int getMaxHp() const;
    int getCurrHp() const;
    int getStrength() const;
    int getDexterity() const;
    int getConstitution() const;
    int getWisdom() const;
};
#endif // GAMECHARACTER_H_INCLUDED
