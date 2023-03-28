#include "Player.h"

Player::Player() {}

Player::Player(string name, int strength, int dexterity, int constitution, int wisdom):
    GameCharacter(name,CHARACTER,PLAYER,25+constitution,25+constitution,strength,dexterity,constitution,wisdom) {}

void Player::addArmor(Armor* armor) {
    wardrobe.push_back(armor);
}

void Player::addWeapon(Weapon* weapon) {
    weapons.push_back(weapon);
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

void Player::changeRoom(Room* newRoom) {
    previousRoom = currentRoom;
    currentRoom = newRoom;
}

bool Player::triggerEvent(Object* obj) {
    // Show the status of the player
    cout << "Player status:" << endl;
    cout << "----------------" << endl;
    cout << "Current HP: " << getCurrHp() << endl;
    cout << "Strength: " << getStrength() << endl;
    cout << "Dexterity: " << getDexterity() << endl;
    cout << "Constitution: " << getConstitution() << endl;
    cout << "Wisdom: " << getWisdom() << endl;
    cout << "Money: " << money << endl;
    return true;
}

void Player::switchWeapon(int index) {
    if (index >= 0 && index < weapons.size()) {
        swap(weapons[0], weapons[index]);
    }
}

Weapon* Player::getCurrWeapon() const {
    if (!weapons.empty()) {
        return weapons[0];
    }
    // return an empty weapon if the weapons list is empty
    return new Weapon();
}

void Player::switchArmor(int index) {
    if (index >= 0 && index < wardrobe.size()) {
        swap(wardrobe[0], wardrobe[index]);
    }
}

Armor* Player::getCurrArmor() const {
    if (!wardrobe.empty()) {
        return wardrobe[0];
    }
    // return an empty armor if the wardrobe is empty
    return new Armor();
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

void Player::setPreviousRoom(Room* room) {
    previousRoom = room;
}

void Player::setArmor(vector<Armor*> armorList) {
    wardrobe = armorList;
}

void Player::setWeapons(vector<Weapon*> weaponList) {
    weapons = weaponList;
}

void Player::setInventory(vector<Item*> inventory) {
    this->inventory = inventory;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

Room* Player::getPreviousRoom() const {
    return previousRoom;
}

vector<Armor*> Player::getWardrobe() const {
    return wardrobe;
}

vector<Weapon*> Player::getWeapons() const {
    return weapons;
}

vector<Item*> Player::getInventory() const {
    return inventory;
}
