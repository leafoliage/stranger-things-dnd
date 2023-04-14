#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

#include "string"
using namespace std;

const int STARTING_ROOM = 32;

const int MAX_HEALTH = 60;

const int MAX_INVENTORY = 6;

const int ARMOR_CLASS_BASE = 8;

const int INIT_MONEY = 25;

const int TYPE_BOUND = 100;
const int SUBTYPE_BOUND = 10;

const int EFFECT_AMOUNT = 7;

enum ObjectType { CHARACTER, ITEM };

enum CharacterType { PLAYER, NEUTRAL, ALLY, ENEMY };

enum ItemType { WEAPON, ARMOR, PROP };

enum WeaponType { MELEE, RANGE };

enum Type { tPLAYER = 0, tNEUTRAL=1, tALLY=2, tENEMY=3, tMELEE=100, tRANGE=101, tARMOR=110, tPROP=120};

enum Ability { STRENGTH, DEXTERITY, CONSTITUTION, WISDOM };

enum Job { BASKETBALL_PLAYER, GUITARIST, CHEERLEADER, REPORTER, SCOOPS_AHOY };

const int jobAilities[5][4] = {
    {3,1,-2,-2}, {1,-2,3,-2}, {1,3,-2,-2}, {-2,-2,1,3}, {0,0,0,0}
};

enum EffectType { DOUBLE_DAMAGE, ATTRACT_FIRE, DODGE, CURED, BETTER_DICE, PUPPETIZED, CLOCKED };

const int jobSkills[5][3] = {
    {DOUBLE_DAMAGE,1,0}, {ATTRACT_FIRE,2,2}, {DODGE,2,0}, {CURED,2,3}, {BETTER_DICE,1,0}
};

const string effectName[7] = {"Double Damage", "Attract Fire", "Dodge", "Cure", "Lucky Dice", "Puppetized", "Clock"};

const string effectDescription[7] = {
    "Your target can pose double damage on their enemy",
    "Your target will be attacked by all of their enemy in one round. If used on your self, your armor class will increase",
    "Your target avoids all attacks in one round",
    "Your target's HP will increase",
    "Your target gets a second chance to roll the dice, and chooses the higher score",
};

enum Direction { NORTH, SOUTH, EAST, WEST, IN, OUT};

const string Direct[6] = {"North", "South", "East", "West", "In", "Out"};

const int BATTLE_ACTIONS = 2;
const string battleActions[BATTLE_ACTIONS] = { "Retreat", "Attack" };
enum BATTLEACTION { RETREAT, ATTACK, USESKILL };

#endif // ENUM_H_INCLUDED