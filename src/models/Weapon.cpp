#include "Weapon.h"
#include "Player.h"

Weapon::Weapon() : Item() {}

Weapon::Weapon(string name, int weaponType, int quality, int price)
    : Item(name, WEAPON, quality, price), weaponType(weaponType) {}

int Weapon::useQuality(GameCharacter* user) {
    int addition = weaponType == MELEE ? user->getStrength() : user->getDexterity();
    bool needDiceOutput = user->getCharacterType() == CharacterType::PLAYER;
    int rolled = rollDice(getQuality(), needDiceOutput);
    return rolled + addition;
}

void Weapon::workOn(GameCharacter* target, GameCharacter* user) {
    int damage = this->useQuality(user);
    target->takeDamage(damage,user);
}

bool Weapon::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->take(this);
    bool popped = player->getCurrentRoom()->popObject(this);
    if (popped) cout << "You picked up " << this->getName() << endl;
    return true;
}

int Weapon::getType() {
    return getObjectType() * TYPE_BOUND + getItemType() * SUBTYPE_BOUND + weaponType;
}

void Weapon::setWeaponType(int weaponType) {
    this->weaponType = weaponType;
}

int Weapon::getWeaponType() {
    return weaponType;
}
