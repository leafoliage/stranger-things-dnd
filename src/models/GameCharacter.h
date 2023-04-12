#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Effect.h"
#include "Skill.h"
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
    Effect effect;
    Skill skill;
public:
    GameCharacter();
    GameCharacter(string name, int characterType, int maxHp, int currHp, int strength, 
        int dexterity, int constitution, int wisdom);
    GameCharacter(string name, int characterType, int maxHp, int currHp, int strength, 
        int dexterity, int constitution, int wisdom, Skill skill);

    virtual bool attack(GameCharacter* rival, Item* equipment);
    virtual int armorClass();
    virtual int abilityCheck(int ability);
    virtual Item* getWeapon() = 0;
    virtual bool wantUseSkill();

    int getType();

    bool checkIsDead();
    int hitCheck(Item* equipment);
    bool hostile(GameCharacter*);
    int takeDamage(int,GameCharacter*);

    void gotEffect(int effect, int time, int power);
    bool hasEffect(int);
    int getEffect(int);
    void effectElapse();

    void useSkillOn(GameCharacter*);
    bool skillAvailable();
    void skillCoolDown();
    void upgradeSkill();
    string getSkillName();
    string getSkillDescription();

    /* Set & Get function*/
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
