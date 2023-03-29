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
    equipment->workOn(rival, this);
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
