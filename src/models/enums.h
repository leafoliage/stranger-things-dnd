#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

const int MAX_HEALTH = 25;

enum ObjectType { CHARACTER, ITEM };

enum CharacterType { PLAYER, NEUTRAL, ALLY, ENEMY };

enum ItemType { WEAPON, ARMOR, PROP };

enum WeaponType { MELEE, RANGE };

#endif // ENUM_H_INCLUDED