#include "Weapon.h"
#include "Player.h"

Weapon::Weapon() : Item() {}

Weapon::Weapon(string name, int weaponType, int quality, int visibility)
    : Item(name, WEAPON, quality, visibility), weaponType(weaponType) {}

int Weapon::useQuality(GameCharacter* user) {
    int addition = weaponType == MELEE ? user->getStrength() : user->getDexterity();
    return rollDice(getQuality()) + addition;
}

void Weapon::workOn(GameCharacter* target, GameCharacter* user) {
    int damage = this->useQuality(user);
    target->takeDamage(damage);
    if (user->getCharacterType() == CharacterType::PLAYER) {
        cout << target->getName() << " lost " << damage << " hp!" << endl;
    }
}

bool Weapon::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->take(this);
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
