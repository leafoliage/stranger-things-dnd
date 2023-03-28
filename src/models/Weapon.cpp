#include "Weapon.h"
#include "Player.h"

Weapon::Weapon() : Item() {}

Weapon::Weapon(string name, int weaponType, int quality, int visibility)
    : Item(name, WEAPON, quality, visibility), weaponType(weaponType) {}

int Weapon::useQuality(Player* player) {
    int addition = weaponType == MELEE ? player->getStrength() : player->getDexterity();
    return getQuality() + addition;
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
