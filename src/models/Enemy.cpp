#include "Enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(string name, int strength, int dexterity, int constitution, int wisdom): 
    GameCharacter(name, CHARACTER, ENEMY, MAX_HEALTH, MAX_HEALTH, strength, dexterity, constitution, wisdom) {}
