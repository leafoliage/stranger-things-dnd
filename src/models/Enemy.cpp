#include "Enemy.h"
#include "Player.h"

Enemy::Enemy() {}

Enemy::Enemy(string name, Weapon* weapon, int strength, int dexterity, int constitution, int wisdom): 
    GameCharacter(name, ENEMY, MAX_HEALTH, MAX_HEALTH, strength, dexterity, constitution, wisdom), weapon(weapon) {}

bool Enemy::triggerEvent(Object* obj) {
    Player* player = dynamic_cast<Player*>(obj);
    Battle battleground;

    player->getCurrentRoom()->callEnemy(&battleground);
    battleground.add(player);
    battleground.initiate();
    while (!battleground.ended()) battleground.run();
    return true;
}

Item* Enemy::getWeapon() {
    return weapon;
}
