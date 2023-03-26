#include "Weapon.h"
#include "Player.h"

Weapon::Weapon() : Item() {}

Weapon::Weapon(string name, int weaponType, int hardness, int visibility)
    : Item(name, WEAPON, hardness, visibility), weaponType(weaponType) {}

bool Weapon::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->addWeapon(*this);
    player->getCurrentRoom()->popObject(this);
    return true;
}

void Weapon::setWeaponType(int weaponType) {
    this->weaponType = weaponType;
}

int Weapon::getWeaponType() {
    return weaponType;
}
