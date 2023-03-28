#include "Weapon.h"
#include "Player.h"

Weapon::Weapon() : Item() {}

Weapon::Weapon(string name, int weaponType, int hardness, int visibility)
    : Item(name, WEAPON, hardness, visibility), weaponType(weaponType) {}

int Weapon::useHardness(Player* player) {
    int addition = weaponType == MELEE ? player->getStrength() : player->getDexterity();
    return getHardness() + addition;
}

bool Weapon::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->addWeapon(this);
    bool popped = player->getCurrentRoom()->popObject(this);
    if (popped) cout << "You picked up " << this->getName() << endl;
    return true;
}

void Weapon::setWeaponType(int weaponType) {
    this->weaponType = weaponType;
}

int Weapon::getWeaponType() {
    return weaponType;
}
