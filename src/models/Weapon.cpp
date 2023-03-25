#include <iostream>
#include <string>
#include "Object.h"
#include "Item.h"
#include "enums.h"
#include "Weapon.h"

Weapon::Weapon() : Item() {}

Weapon::Weapon(string name, WeaponType weaponType, int hardness, int visibility)
    : Item(name, WEAPON, hardness, visibility), weaponType(weaponType) {}

void Weapon::setWeaponType(WeaponType weaponType) {
    this->weaponType = weaponType;
}

WeaponType Weapon::getWeaponType() {
    return weaponType;
}
