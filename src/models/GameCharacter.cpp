#include "GameCharacter.h"

GameCharacter::GameCharacter() {}

GameCharacter::GameCharacter(string name, int characterType, int maxHp, int currHp, int strength, int dexterity, int constitution, int wisdom): 
    Object(name, ObjectType::CHARACTER), characterType(characterType), maxHp(maxHp), currHp(currHp), strength(strength), dexterity(dexterity), constitution(constitution), wisdom(wisdom) {}

bool GameCharacter::checkIsDead() {
    return currHp <= 0;
}

int GameCharacter::takeDamage(int damage) {
    currHp -= damage;
    if (currHp < 0) {
        currHp = 0;
    }
    return currHp;
}

void GameCharacter::attack(GameCharacter* rival, Item* equipment) {
    cout << getName() << " attacked " << rival->getName() << "!" << endl;
    int hit = hitCheck(equipment);
    if (hit <= rival->armorClass() && hit < 20) {
        cout << getName() << " missed!" << endl;
        return;
    }
    equipment->workOn(rival, this);
}

int GameCharacter::abilityCheck(int ability) {
    if (ability < 0 || ability >= 4) return rollDice(20, false);
    int abilities[4] = { strength, dexterity, constitution, wisdom };
    return rollDice(20, false) + abilities[ability];
}

int GameCharacter::hitCheck(Item* equipment) {
    if (!equipment) return abilityCheck(-1);
    int itemType = equipment->getItemType();
    if (itemType == ItemType::PROP) return abilityCheck(Ability::WISDOM);
    if (itemType == ItemType::WEAPON) {
        Weapon* wep = dynamic_cast<Weapon*>(equipment);
        if (wep->getWeaponType() == WeaponType::MELEE) return abilityCheck(Ability::STRENGTH);
        return abilityCheck(Ability::DEXTERITY);
    }
    return 0;
}

int GameCharacter::armorClass() {
    return ARMOR_CLASS_BASE + dexterity;
}

void GameCharacter::setCharacterType(int characterType) {
    this->characterType = characterType;
}

void GameCharacter::setMaxHp(int maxHp) {
    this->maxHp = maxHp;
}

void GameCharacter::setCurrHp(int currHp) {
    this->currHp = currHp;
}

void GameCharacter::setStrength(int strength) {
    this->strength = strength;
}

void GameCharacter::setDexterity(int dexterity) {
    this->dexterity = dexterity;
}

void GameCharacter::setConstitution(int constitution) {
    this->constitution = constitution;
}

void GameCharacter::setWisdom(int wisdom) {
    this->wisdom = wisdom;
}

int GameCharacter::getCharacterType() const {
    return characterType;
}

int GameCharacter::getMaxHp() const {
    return maxHp;
}

int GameCharacter::getCurrHp() const {
    return currHp;
}

int GameCharacter::getStrength() const {
    return strength;
}

int GameCharacter::getDexterity() const {
    return dexterity;
}

int GameCharacter::getConstitution() const {
    return constitution;
}

int GameCharacter::getWisdom() const {
    return wisdom;
}
