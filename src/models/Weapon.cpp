#include "Weapon.h"

Weapon::Weapon() : Item() {}

Weapon::Weapon(string name, int weaponType, int hardness, int visibility)
    : Item(name, WEAPON, hardness, visibility), weaponType(weaponType) {}

void Weapon::setWeaponType(int weaponType) {
    this->weaponType = weaponType;
}

int Weapon::getWeaponType() {
    return weaponType;
}
