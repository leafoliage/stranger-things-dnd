#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

const int MAX_HEALTH = 25;

const int MAX_INVENTORY = 6;

const int ARMOR_CLASS_BASE = 10;

enum ObjectType { CHARACTER, ITEM };

enum CharacterType { PLAYER, NEUTRAL, ALLY, ENEMY };

enum ItemType { WEAPON, ARMOR, PROP };

enum WeaponType { MELEE, RANGE };

enum Ability { STRENGTH, DEXTERITY, CONSTITUTION, WISDOM };

#endif // ENUM_H_INCLUDED