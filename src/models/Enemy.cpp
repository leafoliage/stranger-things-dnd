#include "Enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(string name, Weapon* weapon, int strength, int dexterity, int constitution, int wisdom): 
    GameCharacter(name, ENEMY, MAX_HEALTH, MAX_HEALTH, strength, dexterity, constitution, wisdom), weapon(weapon) {}

bool Enemy::triggerEvent(Object* obj) {
    // TODO
    return true;
}

Item* Enemy::getWeapon() {
    return weapon;
}
