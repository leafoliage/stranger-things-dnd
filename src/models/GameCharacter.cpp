#include "GameCharacter.h"

GameCharacter::GameCharacter() {}

GameCharacter::GameCharacter(string name, int characterType, int maxHp, int currHp, int strength, 
int dexterity, int constitution, int wisdom): 
    Object(name, ObjectType::CHARACTER), characterType(characterType), maxHp(maxHp), 
    currHp(currHp), strength(strength), dexterity(dexterity), constitution(constitution), 
    wisdom(wisdom) {}

GameCharacter::GameCharacter(string name, int characterType, int maxHp, int currHp, int strength, 
int dexterity, int constitution, int wisdom, Skill skill): 
    Object(name, ObjectType::CHARACTER), characterType(characterType), maxHp(maxHp), 
    currHp(currHp), strength(strength), dexterity(dexterity), constitution(constitution), 
    wisdom(wisdom), skill(skill) {}

int GameCharacter::getType() {
    return getObjectType() * TYPE_BOUND +  characterType;
}

bool GameCharacter::checkIsDead() {
    return currHp <= 0;
}

int GameCharacter::takeDamage(int damage, GameCharacter* attacker) {
    if (this->hasEffect(DODGE)) return currHp;
    if (attacker->hasEffect(DOUBLE_DAMAGE)) damage *= 2;
    logf("%s lost %d hp", getName().c_str(), damage);
    currHp -= damage;
    if (currHp < 0) {
        currHp = 0;
    }
    return currHp;
}

bool GameCharacter::wantUseSkill() {
    return skill.available() && currHp <= maxHp/2;
}

bool GameCharacter::attack(GameCharacter* rival, Item* equipment) {
    logf("%s attacked %s!", getName().c_str(), rival->getName().c_str());
    int hit = hitCheck(equipment);
    if ((hit <= rival->armorClass() && hit < 20) || hit<=0) {
        logf("%s missed", getName().c_str());
        return false;
    }
    if (!equipment) {
        int dice = this->strength > 0 ? this->strength : this->dexterity;
        rival->takeDamage(1+rollDice(dice, false),this);
    }
    else equipment->workOn(rival, this);
    return rival->checkIsDead();
}

int GameCharacter::abilityCheck(int ability) {
    int res = rollDice(20, characterType==CharacterType::PLAYER);
    if (this->hasEffect(BETTER_DICE)) {
        int res2 = rollDice(20, characterType==CharacterType::PLAYER);
        res = res2 > res ? res2: res;
    }
    if (ability < 0 || ability >= 4) return res;
    if (res >= 20) return 20;
    if (res <= 0) return 0;
    int abilities[4] = { strength, dexterity, constitution, wisdom };
    return res + abilities[ability];
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

bool GameCharacter::hostile(GameCharacter* character) {
    bool reverse = this->hasEffect(PUPPETIZED);
    int type1 = this->getCharacterType(), type2 = character->getCharacterType();
    bool result;
    if (type1 >= CharacterType::ENEMY) result = type2 < CharacterType::ENEMY;
    else result = type2 >= CharacterType::ENEMY;
    return reverse ? !result: result;
}

int GameCharacter::armorClass() {
    return ARMOR_CLASS_BASE + dexterity;
}

void GameCharacter::gotEffect(int effect, int time, int power) {
    if (effect == CURED) currHp += power;
    return this->effect.add(effect,time,power);
}

bool GameCharacter::hasEffect(int effect) {
    return this->effect.getTime(effect) > 0;
}
int GameCharacter::getEffect(int effect) {
    if (effect==CLOCKED) return this->effect.getTime(effect);
    return this->effect.getPower(effect);
}
void GameCharacter::effectElapse() {
    return effect.elapse();
}

void GameCharacter::useSkillOn(GameCharacter* character) {
    string user, target;
    if (character == NULL) return;
    if (characterType == PLAYER) user = "You";
    else user = getName();
    if (characterType == PLAYER && this == character) target = "youself";
    else target = character->getName();

    logf("%s posed %s effect on %s!", user.c_str(), skill.name().c_str(), target.c_str());
    skill.workOn(character);
}

bool GameCharacter::skillAvailable() {
    return skill.available();
}

void GameCharacter::skillCoolDown() {
    skill.coolDown();
}

void GameCharacter::upgradeSkill() {
    skill.upgrade();
}

string GameCharacter::getSkillName() {
    return skill.name();
}

string GameCharacter::getSkillDescription() {
    return skill.description();
}

bool GameCharacter::hasSkill(int effectType) {
    return skill.equal(effectType);
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
