#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

#include "string"
using namespace std;

const int MAX_HEALTH = 25;

const int MAX_INVENTORY = 6;

const int ARMOR_CLASS_BASE = 10;

const int INIT_MONEY = 10;

const int TYPE_BOUND = 100;
const int SUBTYPE_BOUND = 10;

enum ObjectType { CHARACTER, ITEM };

enum CharacterType { PLAYER, NEUTRAL, ALLY, ENEMY };

enum ItemType { WEAPON, ARMOR, PROP };

enum WeaponType { MELEE, RANGE };

enum Type { tPLAYER = 0, tNEUTRAL=1, tALLY=2, tENEMY=3, tMELLE=100, tRANGE=101, tARMOR=110, tPROP=120};

enum Ability { STRENGTH, DEXTERITY, CONSTITUTION, WISDOM };

enum Job { BASKETBALL_PLAYER, GUITARIST, CHEERLEADER, REPORTER, SCOOPS_AHOY };

const int jobAilities[5][4] = {
    {3,1,-2,-2}, {1,-2,3,-2}, {1,3,-2,-2}, {-2,-2,1,3}, {0,0,0,0}
};

enum Effect { CURE, REFRESH, SOLIDIFY, BURN, FREEZE, POISON };

enum Direction { NORTH, SOUTH, EAST, WEST, IN, OUT};

const string Direct[6] = {"North", "South", "East", "West", "In", "Out"};

#endif // ENUM_H_INCLUDED